/*
& 左值引用:
  普通：  只能引用左值
  const： 引用左右值都行 
&& 右值引用:
  普通：  只能引用右值,可修改
  const:  只能引用右值,不可修改
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
  //左值
  int a=10,b=2;

  int& la = a;
  // int& lb = a+b;//error 不能引用右值
  const int& lb = b+b; // 能引用右值


  int&& ra = a+a;
  ra = 1;//可以修改 右值引用
  // int&& rb = b;// 不能引用左值

  const int&& ra2 = a+a;
  // ra2 = 1;// error 不能改
}