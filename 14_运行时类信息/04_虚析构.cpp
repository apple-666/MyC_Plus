/*
使用delete会启动析构函数
虚析构函数(在申请动态内存的特殊情况):
    当基类不是虚析构时,A a = new B,delete a; 只会删除A类的堆内存,B堆内存泄露
    所以要用virtual 做虚析构函数,实现子类覆盖基类的析构函数
结论：尽量为基类建虚析构函数
*/

#include <iostream> 
#include <typeinfo>
using namespace std;
class A {
public:
    A() : m_a(new int) {
        //【int* m_a=new int;】定义m_a,初值为指向一块堆内存(动态资源)
        cout << "A() is invoked - 申请了一块堆内存:" << m_a << endl;
    }
    virtual ~A( ) { // 虚 析构函数
        delete m_a;
        cout << "~A() is invoked - 释放了一块堆内存:" << m_a << endl;
    } // 释放 m_a 本身所占内存空间
private:
    int* m_a;
};
class B : public A {
public:
    B() : m_b(new int) {
        cout << "B() is invoked - 申请了一块堆内存:" << m_b << endl;
    }
    ~B() {
        delete m_b;
        cout << "~B() is invoked - 释放了一块堆内存:" << m_b << endl;
         // 对于 基类子对象,利用 基类子对象.~A()
    } 
private:
    int* m_b;
};
int main( void ) {
    A* p = new B; // 定义 B类堆对象，利用 B类堆对象.B()
    delete p; // 利用指针p->析构函数( ~B() )     释放B类堆对象本身所占内存空间
    return 0;
} 





