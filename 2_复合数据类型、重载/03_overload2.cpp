// 详谈同一作用域内: 得看站在哪个角度去说话
#include <iostream> 
using namespace std;
namespace ns1 {
    void foo( char* c, short s ) {
        cout << "1. foo(char*,short)" << endl;
    }
    void foo( int i, double d ) {
        cout << "2. foo(int,double)" << endl;
    }
}
namespace ns2 {
    void foo( const char* c, short s ) {
        cout << "3. foo(const char*,short)" << endl;
    }
    void foo( double d, int i ) {
        cout << "4. foo(double,int)" << endl;
    }
}
int main( void ) {
    // 名字空间指令(ns1中的foo在当前作用域可见--出现可见表中)
    using namespace ns1; 

    // 名字空间声明(ns2中的foo引入当前作用域--出现定义表中)
    using ns2::foo;
    // 先定义表 再可见表

    char* c;    short s;
    foo( c, s ); // 3
    return 0;
}

