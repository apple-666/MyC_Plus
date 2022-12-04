/*
纯虚函数:virtual void foo() = 0;
抽象类：
  1,有纯虚函数
  2,不能实例化对象
  3,子类必须覆盖全部纯虚函数,否则也是抽象类
*/

#include <iostream>
using namespace std;

class A
{ // 抽象类
public:
  void bar()
  {
    // ...
  }
  virtual void foo() = 0;  // 纯虚函数
  virtual void foo2() = 0; // 纯虚函数
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
