/*
模板型成员类: 类模板的类模板 嵌套
*/
#include <iostream>
using namespace std;

template <class X>
class A
{
public:
  void foo1()
  {
    cout << "A<X>::foo1()" << endl;
  }
  template <class Y>
  class B
  {
  public:
    template <class T>
    void foo2()
    {
      cout << "A<X>::B<Y>::foo2<T>()" << endl;
    }
    // 用外部定义
    template <class Z>
    class C;
  };
};

template <class X>
template <class Y>
template <class Z>
class A<X>::B<Y>::C
{
public:
  template <class W>
  void foo3()
  {
    cout << "A<X>::B<Y>::C<Z>::foo3<W>()" << endl;
  }
};

int main(void)
{
  A<int> a;
  a.foo1();

  A<int>::B<int> b;
  b.foo2<double>();

  A<int>::B<int>::C<float> c;
  c.foo3<double>();
  return 0;
}
