// auto 与 引用 联合使用
// 同样做为别名,地址相同
#include <iostream> 
#include <typeinfo>
using namespace std;


int main( void ) {
    int a = 10;
    const int b = 10;

    auto c = a;
    // auto:int      c:int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c: " << &c << ", &a: " << &a << endl;  // 地址不同
    c++; // 允许更改

    auto& d = a;
    // auto: int      d: int&
    cout << "d的类型: " << typeid(d).name() << endl; // i
    cout << "&d: " << &d << ", &a: " << &a << endl;  // 地址相同
    d++; // 允许更改

    // 如果指明按引用推导,并且目标带有常属性,则可以自动推导const
    auto& e = b;
    // auto: const int      e: const int&
    cout << "e的类型: " << typeid(d).name() << endl; // i
    cout << "&e: " << &e << ", &b: " << &b << endl;  // 地址相同
//  e++; // 不允许更改

    return 0;
}






