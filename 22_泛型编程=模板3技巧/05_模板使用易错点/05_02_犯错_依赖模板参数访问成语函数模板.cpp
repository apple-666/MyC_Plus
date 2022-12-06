/*
依赖模板参数访问成员函数模板

报错原因：第一次编译,类调用函数,无法识别<>,无法识别为函数模板

解放方案: 类型后加 .template  说明是template 函数模板
*/

#include<iostream>
using namespace std;

class A{
  public:
    template<class T> void foo(){
      cout<<"A::foo<T>()"<<endl;
    }
};

template<class D>
void print(){
  D d; // D是模板参数 
  // d.foo<int>(); // 出现 依赖模板参数访问成员函数模板
  d.template foo<int>();
}

int main( void ) {
  print<A>();
  return 0;
}