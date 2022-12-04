/*
多重继承下容易引发 多个命名冲突
解决方法：
  1,隐藏父类的同名 在子类中重写变量就行了
  2,用访问限定名 A::m_c (推荐使用)
*/

#include <iostream>
using namespace std;
class A
{ // 学生类
public:
  int m_c; // 成绩
};
class B
{ // 老师类
public:
  int m_c; // 工资
};
class D : public A, public B
{ // 助教类
public:
  int m_d;
  int m_c; // 在业务上毫无意义,仅仅是为了将基类m_c隐藏
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
