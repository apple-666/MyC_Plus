/*
&& 右值引用 给右值取真名
*/

#include <iostream>
using namespace std;

int foo()
{
  int m = 10;
  return m;
}

int main()
{
  /*
  左值： 具名内存 能取值
  */
  int a = 10;
  int &ra = a;
  const int &cra = a;
  const int b = 10;
  const int &cb = b;

  /*
  右值： 匿名内存 不能取值
  函数返回值是 右值
  用const/引用/真名 可以接收foo()右值 这样延长了右值的生命周期
  */
  const int rf0 = /*匿名内存 10*/ foo();
  const int &rf = 10;
  int &&rf2 = foo(); // 用真名接收
  const int &rf3 = foo(); 
}