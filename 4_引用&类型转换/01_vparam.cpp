// 引用作为形参

/***
 * 原： void func(int *a,int *b)  
        使用func(&a,&b)
 * 现： 用引用
        void func(int &a,int &b)
        使用func(a,b)

*/
#include <iostream>
using namespace std;

void Swap(int &x, int &y)
{ // 非常引用型 参数
    int z = x;
    x = y;
    y = z;
}
void Swap(int *x, int *y) //传指针
{
    int z = *x;
    *x = *y;
    *y = z;
}

void Print( const int& x, const int& y ) { // 常引用型 参数
//  x = 8888; // 会报错，防止在函数内部意外修改实参
    cout << x << ' ' << y << endl;
}
int main(void)
{
    int a = 10, b = 20;
    Swap(a, b);
    cout << "a:" << a << " b:" << b << endl;

    int c = 11, d = 22;
    Swap(&c, &d);
    cout << "c:" << c << " d:" << d << endl;

    Print( 8888, 9999 );

    return 0;
}
