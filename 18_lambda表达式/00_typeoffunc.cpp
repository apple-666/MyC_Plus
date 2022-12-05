/*
函数内部可以有表达式,自定义类, 不能有函数
全局函数和成员函数:内部的编译顺序
  1,编译class A   2,编译函数
*/
#include <iostream>
#include <typeinfo>
using namespace std;

void foo()
{
  int a = 10;            // ok,函数内部可以定义变量(局部变量)
  cout << 2 * a << endl; // ok,函数内部可以有表达式 也可以有 语句

  // void bar( ) { // error, 函数内部 不能定义 函数
  //     cout << "bar() is invoked" << endl;
  // }
}

// 成员函数内部有类型的编译顺序： 1,编译class A   2,编译函数
int a;
void foo2(int b)
{
  int c;
  class A
  {
  public:
    void bar(int d)
    {
      a = 1;
      // b = 2;// 按编译顺序 找不到b
      // c = 2;//同理
      d = 1;
    }
  };
}

// 内部函数,内有class
int a2 = 1;
class A
{
public:
  void foo(int b)
  {
    // e = 1; // this 是A的
    class B
    {
      public:
        void bar(int c){
          a2 = 10;
          // b = 2;//error
          c = 2; 
          d = 1; // 静态的编译器会先开始编译
          
          // this->e = 1; // 用this->e 也不行，this是B的
          // A::e = 1; // 不行，要用对象访问
          // e = 1; // error 要指明对应的对象才能访问普通成员变量
        }
    };
  }
private:
  static int d; // 静态成员变量属于类 不属于对象
  int e;        // 普通成员变量不属于类属于对象
};

int
main(void)
{

  return 0;
}
