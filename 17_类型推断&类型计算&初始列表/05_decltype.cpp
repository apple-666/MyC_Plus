/*
类型计算 的 三种计算规则 按对应类型计算
1,标识符表达式  
2,函数表达式
3,其他表达式
  3.1 表达式结果为左值
  3.2 表达式结果为右值
*/ 
#include <iostream>
#include <typeinfo>
using namespace std;


double foo( int x, int y );

int main( void ) {
    int a = 10;
    //(1) 如果传递的为标识符表达式，编译器将该标识符的类型 作为最终计算出的类型
    decltype(a) c = a;
    // c: int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c=" << &c << ", &a=" << &a << endl; // 地址不同
    c++; // 允许更改

    //(2) 如果传递的为函数表达式，编译器将该函数返回值的类型 最为最终计算出的类型
    decltype(foo(3,4)) d = a;
    // d: short
    cout << "d的类型: " << typeid(d).name() << endl; // s
    cout << "&d=" << &d << ", &a=" << &a << endl; // 地址不同
    d++; // 允许更改

    //(3) 如果其他表达式
    //(3.1) 表达式的结果为左值，编译器将该左值引用的类型(取别名,所以指向地址相同) 作为最终计算出的类型
    decltype(++a) e = a; // ++a 返回a 是左值。
    // e: int&
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e=" << &e << ", &a=" << &a << endl; // 地址相同
    e++; // 允许更改


    //(3.2) 表达式的结果为右值，编译器将该右值的类型 作为最终计算出的类型
    decltype(a++) f = a; // a2 = a  a++ 返回的a2是放在无名内存是右值
    // f: int
    cout << "f的类型: " << typeid(f).name() << endl; // i
    cout << "&f=" << &f << ", &a=" << &a << endl; // 地址不同
    f++; // 允许更改

    return 0;
}





