/*
链表容器:list 为双向链表 m_head指向链表投 m_tail指向链表尾
重写list类:
  0.缺省构造,判空操作
  1.输出流操作符重载
  2.首尾部增删节点
    - 首节点前指针为NULL 尾节点后指针为NULL
  3.获取首尾节点数据
  4.析构(清空链表),求容器size
  5.拷贝构造 (要用到push_back)

*/

#include <iostream>
using namespace std;

template <class T>
class list
{
public:
  list() : m_head(NULL), m_tail(NULL) {}
  // 不能这样写,node是list内的类,list构造时还未编译node
  // erroe: list(node* head=NULL,node* tail=NULL): m_head(head), m_tail(tail){}
  list(list const &that) : m_head(NULL), m_tail(NULL)
  {
    for (node *i = that.m_head; i != NULL; i = i->m_next)
    {
      push_back(i->m_data);
    }
    cout << "list的拷贝构造" << endl;
  }
  ~list()
  {
    clear();
    // cout<<"list的析构"<<endl;
  }

  bool empty()
  {
    return m_head == NULL && m_tail == NULL;
  }

  void push_front(const T &value)
  {
    m_head = new node(NULL, value, m_head); // newNode的后指针指向 容器的m_head指针指向的第一个数据
    if (m_head->m_next == NULL)
    {                  //相等 说明链表之前为NULL
      m_tail = m_head; // 首尾节点指向同一个节点
    }
    else
    {
      // m_head是node*指针 m_head->m_next是node*指针中的一个属性(下个节点的地址)
      m_head->m_next->m_prev = m_head;
    }
  }
  void push_back(const T &value)
  {
    m_tail = new node(m_tail, value, NULL);
    if (m_tail->m_prev == NULL)
    { // =说明原容器为空
      m_head = m_tail;
    }
    else
    {
      m_tail->m_prev->m_next = m_tail;
    }
  }
  void pop_front()
  {
    if (empty())
    {
      cout << "pop_front中 但容器为空" << endl;
      return;
    }
    // 备份第二节点 (可能为空)
    node *nextNode = m_head->m_next;
    // 删除头指针指向的数据=第一个节点 避免内存泄露
    delete m_head;
    m_head = nextNode;
    if (m_head != NULL) // 说明是有数据的节点
    {
      m_head->m_prev = NULL;
    }
    else
    {
      m_tail = NULL;
    }
  }
  void pop_back()
  {
    if (empty())
    {
      cout << "pop_back中 但容器为空" << endl;
      return;
    }
    // 备份倒二节点 (可能为空)
    node *nextNode = m_tail->m_prev;
    // 删除尾指针指向的数据=最后一个节点 避免内存泄露
    delete m_tail;
    m_tail = nextNode;
    if (m_tail != NULL) // 说明是有数据的节点
    {
      m_tail->m_next = NULL;
    }
    else
    {
      m_head = NULL;
    }
  }
  T &front()
  {
    if (empty())
      throw underflow_error("front(): 访问数据范围溢出");
    return m_head->m_data;
  }
  T &back()
  {
    if (empty())
      throw underflow_error("back(): 访问数据范围溢出");
    return m_tail->m_data;
  }
  void clear()
  {
    while (!empty())
    {
      pop_front(); // 不能用m_head = NULL,会有内存泄露风险
    }
  }
  size_t size()
  {
    size_t s = 0;
    for (node *i = m_head; i != NULL; i = i->m_next)
    {
      s++;
    }
    return s;
  }

private:
  // 节点类: 存3数（前指针,节点数据(泛型),后指针）
  class node
  {
  public:
    node(node *prev, T data, node *next) : m_prev(prev), m_data(data), m_next(next) {}
    node *m_prev;
    T m_data;
    node *m_next;
  };
  node *m_head;
  node *m_tail;
  
  // 如何让ostream实现泛型 list<T>
  friend ostream &operator<<(ostream &os, list<int> &l);
  friend ostream &operator<<(ostream &os, list<double> &l);
};

ostream &operator<<(ostream &os, list<int> &l)
{
  // pnode!=NULL 代表本身是node有数据
  for (list<int>::node *pnode = l.m_head; pnode != NULL; pnode = pnode->m_next)
  {
    os << pnode->m_data << " ";
  }
  return os;
}
ostream &operator<<(ostream &os, list<double> &l)
{
  // pnode!=NULL 代表本身是node有数据
  for (list<double>::node *pnode = l.m_head; pnode != NULL; pnode = pnode->m_next)
  {
    os << pnode->m_data << " ";
  }
  return os;
}

int main()
{
  list<int> l;
  cout << "是否为空：" << l.empty() << endl;
  for (int i = 5; i > 0; i--)
    l.push_front(i);
  for (int i = 0; i < 5; i++)
    l.push_back(i + 5);
  cout << "l.size():" << l.size() << endl;
  cout << "容器所有数据:" << l << endl;

  l.pop_front();
  l.pop_back();
  cout << "l.front():" << l.front() << endl;
  cout << "l.back():" << l.back() << endl;

  l.clear();
  cout << "是否为空：" << l.empty() << endl;

  for (int i = 1; i <= 20; i++)
    l.push_back(i);
  cout << "容器所有数据:" << l << endl;
  list<int> l2(l);
  cout << l2 << endl;

  cout<<"-----------double类-----------"<<endl;
  list<double> l3;
  cout << "是否为空：" << l3.empty() << endl;
  for (int i = 5; i > 0; i--)
    l3.push_front(i * 1.1);
  for (int i = 0; i < 5; i++)
    l3.push_back(i * 2.2);
  cout << "l.size():" << l3.size() << endl;
  cout << "容器所有数据:" << l3 << endl;

  l3.pop_front();
  l3.pop_back();
  cout << "l3.front():" << l3.front() << endl;
  cout << "l3.back():" << l3.back() << endl;

  l3.clear();
  cout << "是否为空：" <<l3.empty() << endl;

  return 0;
}
