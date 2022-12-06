/*
子模板访问父模板资源 报错

类模板在实例化之后才有 真正的类生成！

解决方法：
  表明当前为未知类,先跳过编译. 用作用域访问限定符 | this指针访问(实例化之后才会有this,所以编译成功)
*/

#include <iostream>
using namespace std;
// 基类模板
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

// 子类
template <class T, class D>
class Derived : public Base<T>
{
public:
  // m_i = 19;
  // foo();// error 未生成类就访问了父类的
  void bar()
  {
    // 转换为未知类型的调用
    Base<T>::m_i = 10;
    Base<T>::foo();
    this->foo();
  }

  // 以下正常
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