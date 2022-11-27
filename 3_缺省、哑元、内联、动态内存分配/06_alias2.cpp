// 左值 / 右值 与 引用
#include <iostream> 
using namespace std;
int foo( ) {
    int m=100;
    return m;
}
int main( void ) {
// 函数的生命期
// 具名内存-->能够取址-->左值|非常左值(无const修饰)
//                           |常左值  (有const修饰)
    int a = 10;
    int& ra = a; 
    const int& cra = a;

    const int b = 10;
//  int& rb = b; // error
    const int& crb = b;

// 语句级的生命期(引用可以延长右值的生命期)
// 匿名内存-->不能取址-->右值|直接更改右值毫无意义(c++98/03标准给出结论)
//
    const int& ri = 10; 

    const int& rf = /*|100|*/foo( ); 

    return 0;
}


