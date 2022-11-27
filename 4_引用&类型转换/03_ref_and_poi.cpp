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
    return 0;
}

