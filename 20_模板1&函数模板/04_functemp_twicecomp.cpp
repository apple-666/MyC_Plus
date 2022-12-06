/*
函数模板有二次编译:
1 检查模板本身的语法等
2 实例化出函数时再次检查函数的语法

类型隐式推断: max(1,2) 推断为 max<int>(1,2)
*/
#include <iostream>
using namespace std;

class A
{
public:
  void func()
  {
    cout << "A::func()" << endl;
  }
};

template <typename T>
void foo()
{
  // 1,标识符必须是存在的 a,b,func()
  // abc();//error


  // 2,已知的类 调用的方法要存在
  A a;
  // a.abc();   // error 不存在
  a.func(); //  ok   存在


  // 3,T的类 第一次编译假定合理
  T t;
  // t.abc();   // 第二次编译时，error
  t.func();

  // 4,T的类 调用方法不能出现<>
  // t.ab<c>(); // 但是不能出现<>   error
}

int main(void)
{
  foo<A>();
  return 0;
}
