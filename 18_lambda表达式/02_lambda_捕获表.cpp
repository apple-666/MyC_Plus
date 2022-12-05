/*
lambda的捕获表 [c](int d = 40){cout<<1<<};
  四种捕获表
    []      空
    [c]     变量    变量不可变
    [&c]    引用    可变
    [this]  指针访问外部对象的成员
  用 = 按值捕获所有变量 包括this
  用 & 按引用捕获所有变量 包括this
使用了捕获表的原理:

class X{
public:
  X(int c):c(c){}
  operator()() {
    cout<<1;
  }
private:
  const int c;
}
X{c}() // 创建匿名对象时用外部的c传参
*/

#include <iostream>
#include <typeinfo>
using namespace std;

// lambda表达式 - 捕获表
int a = 10;
class Y
{
public:
  Y(int e2=11):e(e2){}
  void foo(int c = 30)
  {
    cout << "-----------[]------------" << endl;
    [](int d = 40)
    {
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;
      //          cout << "c=" << c << endl; // error
      cout << "d=" << d << endl;
    }();

    cout << "-----------[c]------------" << endl;
    [c]()
    {
      cout << "c=" << c << endl;
    }();

    cout << "-----------[&c]------------" << endl;
    [&c]()
    {
      cout << "++c:" << ++c << endl;
    }();
    /*
    class X{
    public:
      X(int& c):c(c){}
      operator()( ) {
        cout<<1;
      }
    private:
      int& c;
    }
    X{c}()
    */
    cout << "-----------[this]------------" << endl;
    [this]()
    { cout << "e=" << e << endl; }();
    // xx{Y y}.operator()
  }

private:
  static int b;
  int e;
};
int Y::b = 20;

int main(void)
{
  Y y;
  y.foo();
  return 0;
}
