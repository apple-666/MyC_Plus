/**���� �ľ�̬��Ա����
 * ��Ա����: �ܷ������г�Ա
 * ��̬������ֻ�ܷ��ʾ�̬��Ա
 * 
 */
#include <iostream>
using namespace std;

class A
{
public:
  int m_i;
  static int m_a; // ���� �ܰ��� ����ľ�̬���� ��Ϊ��Ա����

  void foo() const
  { // ����const����func,Ϊconst class* this ,��ֻ���޸�const�����Ա����
    cout << "foo() is invoked" << endl;
    cout << m_i << endl; // ok
    cout << m_a << endl; // ok
    foo2();
  }

  static void foo2() // ���ᴫ class* this
  {
    cout << "foo2() is invoked" << endl;
    // cout << m_i << endl; // error
    cout << m_a << endl; // ok,��̬��Ա�����ڲ����Է��ʾ�̬��Ա
  }
};

int A::m_a = 1; // ������ʽ���������еľ�̬��Ա����

int main(void)
{
  A a; // ����a(��a�����ڴ�ռ�)-->������Ҫ����aռ���ڴ�ռ��С
  a.foo();

  A::foo2(); // ֻ�о�̬������A:: ��ʽ����
  a.foo2();
  return 0;
}
