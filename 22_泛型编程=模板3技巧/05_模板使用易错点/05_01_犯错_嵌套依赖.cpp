/*
嵌套依赖: T::B b 编译器判断是T类的静态成员,但后面却是声明变量,所以前后不一致,会报错
T是依赖用户输入的类型，所以是依赖错误.

解放方案: 前面加 class或者 typename 代表是 类型
*/

#include<iostream>
using namespace std;

class A{

  public:
    class B{
      public:
        void foo() {
          cout<<"A::B.foo()"<<endl;
        }
    };
};

template<class T>
void print(){
  // T::B b; // 不能嵌套依赖
  class T::B b; // 加了class 能辨别出是待定的类名
  b.foo();
}

int main( void ) {
  print<A>(); // class A::B b; b.foo();
  // print<int>(); //error
  return 0;
}