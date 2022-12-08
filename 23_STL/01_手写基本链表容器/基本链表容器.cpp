/*
��������:list Ϊ˫������ m_headָ������Ͷ m_tailָ������β
��дlist��:
  0.ȱʡ����,�пղ���
  1.���������������
  2.��β����ɾ�ڵ�
    - �׽ڵ�ǰָ��ΪNULL β�ڵ��ָ��ΪNULL
  3.��ȡ��β�ڵ�����
  4.����(�������),������size
  5.�������� (Ҫ�õ�push_back)

*/

#include <iostream>
using namespace std;

template <class T>
class list
{
public:
  list() : m_head(NULL), m_tail(NULL) {}
  // ��������д,node��list�ڵ���,list����ʱ��δ����node
  // erroe: list(node* head=NULL,node* tail=NULL): m_head(head), m_tail(tail){}
  list(list const &that) : m_head(NULL), m_tail(NULL)
  {
    for (node *i = that.m_head; i != NULL; i = i->m_next)
    {
      push_back(i->m_data);
    }
    cout << "list�Ŀ�������" << endl;
  }
  ~list()
  {
    clear();
    // cout<<"list������"<<endl;
  }

  bool empty()
  {
    return m_head == NULL && m_tail == NULL;
  }

  void push_front(const T &value)
  {
    m_head = new node(NULL, value, m_head); // newNode�ĺ�ָ��ָ�� ������m_headָ��ָ��ĵ�һ������
    if (m_head->m_next == NULL)
    {                  //��� ˵������֮ǰΪNULL
      m_tail = m_head; // ��β�ڵ�ָ��ͬһ���ڵ�
    }
    else
    {
      // m_head��node*ָ�� m_head->m_next��node*ָ���е�һ������(�¸��ڵ�ĵ�ַ)
      m_head->m_next->m_prev = m_head;
    }
  }
  void push_back(const T &value)
  {
    m_tail = new node(m_tail, value, NULL);
    if (m_tail->m_prev == NULL)
    { // =˵��ԭ����Ϊ��
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
      cout << "pop_front�� ������Ϊ��" << endl;
      return;
    }
    // ���ݵڶ��ڵ� (����Ϊ��)
    node *nextNode = m_head->m_next;
    // ɾ��ͷָ��ָ�������=��һ���ڵ� �����ڴ�й¶
    delete m_head;
    m_head = nextNode;
    if (m_head != NULL) // ˵���������ݵĽڵ�
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
      cout << "pop_back�� ������Ϊ��" << endl;
      return;
    }
    // ���ݵ����ڵ� (����Ϊ��)
    node *nextNode = m_tail->m_prev;
    // ɾ��βָ��ָ�������=���һ���ڵ� �����ڴ�й¶
    delete m_tail;
    m_tail = nextNode;
    if (m_tail != NULL) // ˵���������ݵĽڵ�
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
      throw underflow_error("front(): �������ݷ�Χ���");
    return m_head->m_data;
  }
  T &back()
  {
    if (empty())
      throw underflow_error("back(): �������ݷ�Χ���");
    return m_tail->m_data;
  }
  void clear()
  {
    while (!empty())
    {
      pop_front(); // ������m_head = NULL,�����ڴ�й¶����
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
  // �ڵ���: ��3����ǰָ��,�ڵ�����(����),��ָ�룩
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
  
  // �����ostreamʵ�ַ��� list<T>
  friend ostream &operator<<(ostream &os, list<int> &l);
  friend ostream &operator<<(ostream &os, list<double> &l);
};

ostream &operator<<(ostream &os, list<int> &l)
{
  // pnode!=NULL ��������node������
  for (list<int>::node *pnode = l.m_head; pnode != NULL; pnode = pnode->m_next)
  {
    os << pnode->m_data << " ";
  }
  return os;
}
ostream &operator<<(ostream &os, list<double> &l)
{
  // pnode!=NULL ��������node������
  for (list<double>::node *pnode = l.m_head; pnode != NULL; pnode = pnode->m_next)
  {
    os << pnode->m_data << " ";
  }
  return os;
}

int main()
{
  list<int> l;
  cout << "�Ƿ�Ϊ�գ�" << l.empty() << endl;
  for (int i = 5; i > 0; i--)
    l.push_front(i);
  for (int i = 0; i < 5; i++)
    l.push_back(i + 5);
  cout << "l.size():" << l.size() << endl;
  cout << "������������:" << l << endl;

  l.pop_front();
  l.pop_back();
  cout << "l.front():" << l.front() << endl;
  cout << "l.back():" << l.back() << endl;

  l.clear();
  cout << "�Ƿ�Ϊ�գ�" << l.empty() << endl;

  for (int i = 1; i <= 20; i++)
    l.push_back(i);
  cout << "������������:" << l << endl;
  list<int> l2(l);
  cout << l2 << endl;

  cout<<"-----------double��-----------"<<endl;
  list<double> l3;
  cout << "�Ƿ�Ϊ�գ�" << l3.empty() << endl;
  for (int i = 5; i > 0; i--)
    l3.push_front(i * 1.1);
  for (int i = 0; i < 5; i++)
    l3.push_back(i * 2.2);
  cout << "l.size():" << l3.size() << endl;
  cout << "������������:" << l3 << endl;

  l3.pop_front();
  l3.pop_back();
  cout << "l3.front():" << l3.front() << endl;
  cout << "l3.back():" << l3.back() << endl;

  l3.clear();
  cout << "�Ƿ�Ϊ�գ�" <<l3.empty() << endl;

  return 0;
}
