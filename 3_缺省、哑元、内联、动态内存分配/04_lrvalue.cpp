// 左值 和 右值
// 左值 = 右值
// 左值： 能取到地址
// 右值： 取不到地址
#include <iostream> 
using namespace std;
int foo( ) {
    int m=100;
    return m;
}
int main( void ) {
    /**
     * @brief 左值
     * 函数的生命期：具名内存-->能够取址-->左值|非常左值(无const修饰)
     *                                     |常左值 用const修饰            
     */
    int a = 11;
    &a; // 取地址操作
    const int b = 10;
    &b;
//  b = 15; // error

    /**
     * @brief 右值
     * 语句级的生命期：匿名内存-->不能取址-->右值|直接更改右值毫无意义(c++98/03标准给出结论)
     * 函数返回值也是右值
     * 
     */
    10;
//  &10; // error 右值取不到地址
//  10 = 15; // error

    /*|100|*/foo( ); // (1)生成跳转指令 (2)开辟一块无名内存空间
//  &foo( ); // error
//  foo( ) = 15; // error

    return 0;
}

