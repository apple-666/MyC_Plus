// 类型计算 比 类型推导 针对类型的确定 会更加精准
#include <iostream>
#include <typeinfo>
using namespace std;


int main( void ) {
    const int a = 10;
    
    auto b = a;
    // b: int
    cout << "b的类型: " << typeid(b).name() << endl; // i
    cout << "b=" << b << ", a=" << a << endl; // b的初始值 和 a相同
    b++; // 允许更改

    decltype(a) c = a;
    // c: const int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "c=" << c << ", a=" << a << endl; // c的初始值 和 a相同
//  c++; // 不允许更改
    return 0;
}
