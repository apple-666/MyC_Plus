//类中 
// 成员变量跟着类的生命周期, 是类生命周期
// 静态成员变量: 类目::  的形式定义+访问
//    不占类的空间,是进程级生命周期,初始化和定义在全局作用域
#include <iostream>
using namespace std;

class A {
public:
    int m_i;
    static int m_a; // 类中 能包含 本类的静态对象 作为成员变量
};

int A::m_a = 1111; // 这种形式来定义类中的静态成员变量

int main( void ) {
    A a; // 定义a(给a分配内存空间)-->编译器要计算a占据内存空间大小
    cout << "a的大小:" << sizeof(a) << endl; // 4
    cout<<A::m_a<<endl;

    a.m_a = 22;
    cout<<a.m_a<<endl;
    return 0;
}
