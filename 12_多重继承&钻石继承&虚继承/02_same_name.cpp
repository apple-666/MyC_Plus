/*
���ؼ̳����������� ���������ͻ
���������
  1,���ظ����ͬ�� ����������д����������
  2,�÷����޶��� A::m_c (�Ƽ�ʹ��)
*/

#include <iostream>
using namespace std;
class A
{ // ѧ����
public:
  int m_c; // �ɼ�
};
class B
{ // ��ʦ��
public:
  int m_c; // ����
};
class D : public A, public B
{ // ������
public:
  int m_d;
  int m_c; // ��ҵ���Ϻ�������,������Ϊ�˽�����m_c����
  void foo()
  {
    // m_c = 1; // error;
    A::m_c = 100; // ok
  }
};
int main(void)
{
  D d;
  // d.m_c = 2; // error
  d.B::m_c = 1;
  return 0;
}
