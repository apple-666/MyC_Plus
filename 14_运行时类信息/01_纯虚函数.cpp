/*
���麯��:virtual void foo() = 0;
�����ࣺ
  1,�д��麯��
  2,����ʵ��������
  3,������븲��ȫ�����麯��,����Ҳ�ǳ�����
*/

#include <iostream>
using namespace std;

class A
{ // ������
public:
  void bar()
  {
    // ...
  }
  virtual void foo() = 0;  // ���麯��
  virtual void foo2() = 0; // ���麯��
};

class B : public A
{
public:
  virtual void foo()
  {
    // ...
  }
};

class C : public A
{
public:
  virtual void foo()
  {
    // ...
  }
    virtual void foo2() 
    {
      // ...
    }
};

int main(void)
{
  //  A a;
  //  new A; //error

  // B b;
  // new B; //error
  C c;
  new C;
  return 0;
}
