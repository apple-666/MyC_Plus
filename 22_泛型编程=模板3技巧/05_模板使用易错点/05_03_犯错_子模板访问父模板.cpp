/*
��ģ����ʸ�ģ����Դ ����

��ģ����ʵ����֮����� �����������ɣ�

���������
  ������ǰΪδ֪��,����������. ������������޶��� | thisָ�����(ʵ����֮��Ż���this,���Ա���ɹ�)
*/

#include <iostream>
using namespace std;
// ����ģ��
template <class T>
class Base
{
public:
  int m_i;
  void foo()
  {
    cout << "Base<T>::foo()" << endl;
  }
};

// ����
template <class T, class D>
class Derived : public Base<T>
{
public:
  // m_i = 19;
  // foo();// error δ������ͷ����˸����
  void bar()
  {
    // ת��Ϊδ֪���͵ĵ���
    Base<T>::m_i = 10;
    Base<T>::foo();
    this->foo();
  }

  // ��������
  int m_i;
  void foo() {
    cout<<"Derived<>::foo()"<<endl;
  }
};

int main()
{
  Derived<int,int> d;
  d.bar();
  return 0;
}