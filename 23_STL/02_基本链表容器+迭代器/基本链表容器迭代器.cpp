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

迭代器:引入两个迭代器 范围（头数据-尾数据-NULL）
  起始迭代器，用途：遍历用       头节点标记,当前节点标记,尾节点标记
  终止迭代器，用途：作为结束标记  头节点标记,当前为NULL,尾节点标记
迭代器的类:
  1,构造 重载操作符 * ++ -- == !=
  2,begin迭代器和end迭代器。用迭代器遍历
  3,指定位置用迭代器插入,删除操作
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
    {                  // 相等 说明链表之前为NULL
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

public:
  // 正向非常迭代类
  class iterator
  {
  public:
    // 迭代器伴随着容器,不能凭空出现所以构造带参
    iterator(node *s, node *c, node *e) : m_start(s), m_cur(c), m_end(e) {}
    T &operator*()
    {
      if (m_cur == NULL)
        throw underflow_error("operator*:访问范围溢出");
      return m_cur->m_data;
    }
    iterator &operator++()
    {
      // 返回迭代器本身 所以用&
      if (m_cur == NULL)
      { // 回到初始 循环迭代器
        m_cur = m_start;
      }
      else
      {

        m_cur = m_cur->m_next;
      }
      return *this;
    }
    iterator &operator--()
    {
      // 返回迭代器本身 所以用&
      if (m_cur == NULL)
      { // 回到初始 循环迭代器
        m_cur = m_end;
      }
      else
      {
        m_cur = m_cur->m_prev;
      }
      return *this;
    }
    bool operator==(iterator const &that) const
    {
      // 每一个指向的地址相同 说明同一个迭代器
      return m_start == that.m_start && m_cur == that.m_cur && m_end == that.m_end;
    }
    bool operator!=(iterator const &that) const
    {
      // return m_start!=that.m_start||m_cur!=that.m_cur||m_end!=that.m_end;
      // 可调用相反的方法
      return !(*this == that);
    }

  private:
    node *m_start;     // 开始指向
    node *m_cur;       // 当前指向
    node *m_end;       // 终止指向
    friend class list; // 不然没法访问m_cur等
  };

  // 以下是list 范围
  // 起始迭代器
  iterator begin()
  {
    return iterator(m_head, m_head, m_tail);
  }
  // 终止迭代器
  iterator end()
  {
    return iterator(m_head, NULL, m_tail);
  }
  // 在指定位置(之前)插入
  void insert(iterator const &loc, T const &data)
  {
    if (loc == end())
      push_back(data);
    else
    {
      // prev 指向 (迭代器指向的)节点的前一个节点  next指向当前(迭代器指向的)节点
      node *pnode = new node(loc.m_cur->m_prev, data, loc.m_cur);
      if (pnode->m_prev != NULL)
      {
        pnode->m_prev->m_next = pnode;
      }
      else
      {
        m_head = pnode;
      }
      loc.m_cur->m_prev = pnode;
    }
  }
  void erase(iterator const &loc)
  {
    if (loc == end())
      throw underflow_error("访问范围溢出");
    else
    {
      // 左边 指向 右边
      node *nown = loc.m_cur;
      if (nown->m_prev == NULL) // 第一节点
      {
        m_head = nown->m_next;
      }
      else
      {
        nown->m_prev->m_next = nown->m_next;
      }

      // 右边 指向 左边
      if (nown->m_next == NULL) // 最后一个节点
      {
        m_tail = nown->m_prev;
      }
      else
      {
        nown->m_next->m_prev = nown->m_prev;
      }
    }
  }
  // 正向常迭代类:无法修改目标节点
  class const_iterator
  {
  public:
    const_iterator(iterator const &it) : m_it(it) {}
    T const &operator*()
    {
      return *m_it; // 用的 const无法修改目标
    }
    const_iterator &operator++()
    {
      ++m_it;
      return *this;
    }
    const_iterator &operator--()
    {
      --m_it;
      return *this;
    }
    bool operator==(const_iterator const &that)
    {
      return m_it == that.m_it;
    }
    bool operator!=(const_iterator const &that)
    {
      return !(m_it == that.m_it);
    }

  private:
    iterator m_it;
  };
  // 起始常迭代器
  const_iterator cbegin() const
  {
    return iterator(m_head, m_head, m_tail);
  }
  // 终止常迭代器
  const_iterator cend() const
  {
    return iterator(m_head, NULL, m_tail);
  }

private:
  node *m_head;
  node *m_tail;
};

// 查找功能 <迭代器类型,list类型>
template<class IT,class T>
IT find(IT const& from,IT const& to, T const& data){
  for(IT i = from;i!=to;++i){
    if(*i==data) return i;
  }
  return to;// to不参与查找,没有找到返回to
}

// 快速排序 升序 <迭代器类型>
template<typename IT>void sort(IT const& a,IT const& b){
  cout<<"void sort() 还没有实现"<<endl;
}


// 用迭代器打印数据
void print(list<int> &l)
{
  typedef list<int>::iterator IT; // 设置别名 IT 代表 list<int>::iterator
  for (IT i = l.begin(); i != l.end(); ++i)
  {
    cout << *i << " ";
  }
  cout << endl;
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
  print(l);

  // 增
  l.insert(++l.begin(), 1111);
  print(l);
  // 删
  l.erase(++l.begin());
  print(l);
  // 改
  typedef list<int>::iterator IT;
  IT i = l.begin();
  *i = 111;
  print(l);

  IT i2 = find(l.begin(),l.end(),4);
  if(i2!=l.end()) {
    cout<<"找到了："<<*i2<<endl;
  }else {
    cout<<"没有找到"<<endl;
  }

  sort(l.begin(),l.end());
  cout<<"----sort()之后------"<<endl;
  print(l);

  cout << "--使用正向常迭代器-----" << endl;
  const list<int> cls(l);
  typedef list<int>::const_iterator CIT;
  for (CIT i = cls.cbegin(); i!= cls.cend(); ++i)
  {
      cout<<*i<<" ";
  }
  cout<<endl;
  
  return 0;
}
