
#include <iostream> 
#include <typeinfo>
using namespace std;

void foo( auto v=10 ) { // 11��֧�֣���14��׼֧��
}

// class A {
// public:
//     A() : a(10), b(3.14) {
//         //��auto a = 10;��
//         //��auto b = 3.14;��
//     }
//     auto a; // ����
//     auto b; // ����
// };

int main( void ) {
    foo( 8888 );
    return 0;
}










