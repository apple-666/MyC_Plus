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

������:�������������� ��Χ��ͷ����-β����-NULL��
  ��ʼ����������;��������       ͷ�ڵ���,��ǰ�ڵ���,β�ڵ���
  ��ֹ����������;����Ϊ�������  ͷ�ڵ���,��ǰΪNULL,β�ڵ���
����������:
  1,���� ���ز����� * ++ -- == !=
  2,begin��������end���������õ���������
  3,ָ��λ���õ���������,ɾ������
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
    {                  // ��� ˵������֮ǰΪNULL
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

public:
  // ����ǳ�������
  class iterator
  {
  public:
    // ����������������,����ƾ�ճ������Թ������
    iterator(node *s, node *c, node *e) : m_start(s), m_cur(c), m_end(e) {}
    T &operator*()
    {
      if (m_cur == NULL)
        throw underflow_error("operator*:���ʷ�Χ���");
      return m_cur->m_data;
    }
    iterator &operator++()
    {
      // ���ص��������� ������&
      if (m_cur == NULL)
      { // �ص���ʼ ѭ��������
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
      // ���ص��������� ������&
      if (m_cur == NULL)
      { // �ص���ʼ ѭ��������
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
      // ÿһ��ָ��ĵ�ַ��ͬ ˵��ͬһ��������
      return m_start == that.m_start && m_cur == that.m_cur && m_end == that.m_end;
    }
    bool operator!=(iterator const &that) const
    {
      // return m_start!=that.m_start||m_cur!=that.m_cur||m_end!=that.m_end;
      // �ɵ����෴�ķ���
      return !(*this == that);
    }

  private:
    node *m_start;     // ��ʼָ��
    node *m_cur;       // ��ǰָ��
    node *m_end;       // ��ָֹ��
    friend class list; // ��Ȼû������m_cur��
  };

  // ������list ��Χ
  // ��ʼ������
  iterator begin()
  {
    return iterator(m_head, m_head, m_tail);
  }
  // ��ֹ������
  iterator end()
  {
    return iterator(m_head, NULL, m_tail);
  }
  // ��ָ��λ��(֮ǰ)����
  void insert(iterator const &loc, T const &data)
  {
    if (loc == end())
      push_back(data);
    else
    {
      // prev ָ�� (������ָ���)�ڵ��ǰһ���ڵ�  nextָ��ǰ(������ָ���)�ڵ�
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
      throw underflow_error("���ʷ�Χ���");
    else
    {
      // ��� ָ�� �ұ�
      node *nown = loc.m_cur;
      if (nown->m_prev == NULL) // ��һ�ڵ�
      {
        m_head = nown->m_next;
      }
      else
      {
        nown->m_prev->m_next = nown->m_next;
      }

      // �ұ� ָ�� ���
      if (nown->m_next == NULL) // ���һ���ڵ�
      {
        m_tail = nown->m_prev;
      }
      else
      {
        nown->m_next->m_prev = nown->m_prev;
      }
    }
  }
  // ���򳣵�����:�޷��޸�Ŀ��ڵ�
  class const_iterator
  {
  public:
    const_iterator(iterator const &it) : m_it(it) {}
    T const &operator*()
    {
      return *m_it; // �õ� const�޷��޸�Ŀ��
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
  // ��ʼ��������
  const_iterator cbegin() const
  {
    return iterator(m_head, m_head, m_tail);
  }
  // ��ֹ��������
  const_iterator cend() const
  {
    return iterator(m_head, NULL, m_tail);
  }

private:
  node *m_head;
  node *m_tail;
};

// ���ҹ��� <����������,list����>
template<class IT,class T>
IT find(IT const& from,IT const& to, T const& data){
  for(IT i = from;i!=to;++i){
    if(*i==data) return i;
  }
  return to;// to���������,û���ҵ�����to
}

// �������� ���� <����������>
template<typename IT>void sort(IT const& a,IT const& b){
  cout<<"void sort() ��û��ʵ��"<<endl;
}


// �õ�������ӡ����
void print(list<int> &l)
{
  typedef list<int>::iterator IT; // ���ñ��� IT ���� list<int>::iterator
  for (IT i = l.begin(); i != l.end(); ++i)
  {
    cout << *i << " ";
  }
  cout << endl;
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
  print(l);

  // ��
  l.insert(++l.begin(), 1111);
  print(l);
  // ɾ
  l.erase(++l.begin());
  print(l);
  // ��
  typedef list<int>::iterator IT;
  IT i = l.begin();
  *i = 111;
  print(l);

  IT i2 = find(l.begin(),l.end(),4);
  if(i2!=l.end()) {
    cout<<"�ҵ��ˣ�"<<*i2<<endl;
  }else {
    cout<<"û���ҵ�"<<endl;
  }

  sort(l.begin(),l.end());
  cout<<"----sort()֮��------"<<endl;
  print(l);

  cout << "--ʹ�����򳣵�����-----" << endl;
  const list<int> cls(l);
  typedef list<int>::const_iterator CIT;
  for (CIT i = cls.cbegin(); i!= cls.cend(); ++i)
  {
      cout<<*i<<" ";
  }
  cout<<endl;
  
  return 0;
}
