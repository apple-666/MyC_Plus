/*
�����ڹ��������쳣
�����е�except
 1,������ĳ�Ա���� �����쳣ǰ �Զ���ع�(����)
 2,��̬��Դ���Ա����  �����쳣ǰ Ҫ�ֶ�delete
*/
#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
  A() { cout << "A() is invoked" << endl; }
  ~A() { cout << "~A() is invoked" << endl; }
};
class C
{
public:
  C() : m_p(new A)
  {
    cout << "C() is invoked" << endl;
    if (1 == 1)
    {
      delete m_p; // Ҫ�ֶ�
      //���쳣�� ������ĳ�Ա����ִ������ m_a.~A()
      throw 1;
    }
    // m_a.A() Ĭ��
  }
  ~C()
  {
    cout << "~C() is invoked" << endl;
    delete m_p;
    // m_a.~A() Ĭ��
  }

private:
  A m_a;
  A *m_p;
};
int main(void)
{
  try
  {
    C c; // c.C()
  }      // ���c�ǲ�ȱ����,�򲻻��������
  catch (...)
  { // �����쳣����������
  }
  return 0;
}
