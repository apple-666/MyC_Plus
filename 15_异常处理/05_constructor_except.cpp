/*
建议在构造中抛异常
构造中的except
 1,对象类的成员变量 在抛异常前 自动会回滚(析构)
 2,动态资源类成员变量  在抛异常前 要手动delete
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
      delete m_p; // 要手动
      //抛异常则 对象类的成员变量执行析构 m_a.~A()
      throw 1;
    }
    // m_a.A() 默认
  }
  ~C()
  {
    cout << "~C() is invoked" << endl;
    delete m_p;
    // m_a.~A() 默认
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
  }      // 如果c是残缺对象,则不会调用析构
  catch (...)
  { // 捕获异常但不做处理
  }
  return 0;
}
