// C++编译器(例如:g++),会更改函数名(因为C++标准要求的)
#include <iostream> 
using namespace std;

void foo( char* c, short s ) { // _Z3fooPcs
    cout << "1. foo(char*,short)" << endl;    
}
void foo( const char* c, short s ) { // _Z3fooPKcs
    cout << "2. foo(const char*,short)" << endl;
}
void foo( char* c, int s ) { // _Z3fooPci
    cout << "3. foo(char*,int)" << endl;
}
void foo( char* c, char s ) { // _Z3fooPcc
    cout << "4. foo(char*,char)" << endl;
}
void foo( ... ) { // _Z3fooz
    cout << "5. foo(...)" << endl;
}
int main( void ) {
    char* c;    short s;
    foo( c, s ); // _Z3fooPcs(c,s);  普通方式调用 重载关系的函数时, 根据 实参的类型 来确定到底 调用哪个 foo

    // 函数指针方式调用 重载关系的函数时, 根据 函数指针的类型 来确定到底 调用哪个foo
    void(*search_fun)(char* ,char ) = foo; 
    char *d; char a;
    search_fun(d,a);
    return 0;
}

