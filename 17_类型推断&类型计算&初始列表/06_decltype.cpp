/*
函数返回值类型后置
  auto fun()->decltype(x){  // x从参数中取
    return x+y;
  }
*/
#include <iostream>
#include <typeinfo>
using namespace std;

auto foo( int a, double y )->decltype(a) { // 表达式为无名内存
  int x = 1;
    return x + y;
}

int main( void ) {
    auto f = foo(1,3);
    // f: double
    cout << "f的类型: " << typeid(f).name() << endl; // d
    return 0;
}

