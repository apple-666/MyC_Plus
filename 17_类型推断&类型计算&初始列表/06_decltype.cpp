/*
��������ֵ���ͺ���
  auto fun()->decltype(x){  // x�Ӳ�����ȡ
    return x+y;
  }
*/
#include <iostream>
#include <typeinfo>
using namespace std;

auto foo( int a, double y )->decltype(a) { // ���ʽΪ�����ڴ�
  int x = 1;
    return x + y;
}

int main( void ) {
    auto f = foo(1,3);
    // f: double
    cout << "f������: " << typeid(f).name() << endl; // d
    return 0;
}

