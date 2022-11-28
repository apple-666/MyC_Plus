/***
 * 引用 和 指针 在使用上的差别
 * 指针是指向，有传递性
 * 引用是别名，就是目标，更包容
*/
#include <iostream> 
using namespace std;

int main( void ) {
    int a = 10;

    int* pa = NULL; // ok,存在空指针
//  int& ra = NULL; // error,不存在空引用
    int& ra = a; // ok,引用从诞生的一刻,就必须指明是谁的别名

    int** ppa = &pa; // ok,存在指针的指针
//  int&& rra = ra; // error,不存在引用的引用
    int& rra = ra; // ok,但是这并不是引用的引用,而应该是 rra为a的别名

    int*&rpa = pa; // ok, 存在指针的引用 rpa是引用 pa是指针
//  int&*pra = &ra; // error,不存在引用的指针
    int* pra = &ra; // ok,但是这并不是引用的指针,而应该是a的指针

    int x, y, z;
    int*p[3] = {&x, &y, &z}; // ok, 存在指针的数组
//  int&r[3] = { x, y, z }; // error,不存在引用的数组

    int arr[3];
    int(&rarr)[3] = arr; // ok,存在数组的引用

    // 名字在中间,类型在两边;从右到左,从近到远,括号优先
    int a;          // int型a              
    int a[3];       // a数组存着3int型      
    int a[3][4];    // a [3]数组每个存着[4]数组
    int(*p)[3];     // 指针p指向 数组int型的 = 数组指针    
    int*p[3];       // p是个数组,存着3个int指针 = 指针数组
    int(*p[3])[4];  // ():指针数组b指向一个数组a里有4个int = a数组的指针数组 = 数组指针数组  
    int(*p)(int,double);  // 指针指向函数 = 函数指针
    int(*p[3])(int,double);  // 指针数组指向函数 = 函数指针数组
    return 0;
}

