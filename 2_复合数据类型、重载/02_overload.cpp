// 函数之间的关系 - 重载( 1.同一作用域内  2.函数名相同   3.形参表不同 )
// 函数形参表是否相同根据 形参的个数 以及 每个对应的形参类型 判断
#include <iostream> 
using namespace std;

void foo( char* c, short s ) {
    cout << "1. foo(char*,short)" << endl;
}
void foo( int i, double d ) {
    cout << "2. foo(int,double)" << endl;
}
void foo( const char* c, short s ) {
    cout << "3. foo(const char*,short)" << endl;
}
void foo( double d, int i ) {
    cout << "4. foo(double,int)" << endl;
}

// int foo( int d, double i ) {} // error
// void foo( int d, double i ) {}   // error

int main( void ) {
    char* c;    short s;
    foo( c, s ); // 1
    const char* cc;
    foo( cc, s ); // 3
    int i;  double d;
    foo( i, d ); // 2
    foo( d, i ); // 4
    return 0;
}

