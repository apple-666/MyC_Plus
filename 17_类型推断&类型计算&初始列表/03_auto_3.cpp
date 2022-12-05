
#include <iostream> 
#include <typeinfo>
using namespace std;

void foo( auto v=10 ) { // 11不支持，但14标准支持
}

// class A {
// public:
//     A() : a(10), b(3.14) {
//         //【auto a = 10;】
//         //【auto b = 3.14;】
//     }
//     auto a; // 声明
//     auto b; // 声明
// };

int main( void ) {
    foo( 8888 );
    return 0;
}










