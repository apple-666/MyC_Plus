/*
使用auto 编译器做类型推断
*/

#include <iostream>
using namespace std;

// 编译器做类型推导，并不是照抄类型

int main(void)
{
  int a = 10;
  const int b = 10;
  auto t = a;
  cout << t << " " << typeid(t).name() << endl;
  cout << &t << " " << &a << endl;
  // cout<<&b<<" "<<&t<<" "<<&a<<endl;

  auto t2 = b;
  cout << t2 << " " << typeid(t2).name() << endl;
  cout << &t2 << " " << &b << endl;
  t2++; // const -> auto 后没有拿到常属性可以更改

  const auto t3 = b;
  cout << t3 << " " << typeid(t3).name() << endl;
  cout << &t3 << " " << &b << endl;
  // t3++; // const + auto 

  // 指针下 可以拿到常属性
  auto t4 = &a; // 右值是 int*
  *t4 = 11; 
  cout<<"t4:"<<typeid(t4).name() << endl; // pi


  auto t5 = &b; // 右值是 const int* 表示：指针指向内容有常属性 (const int* const p 就代表指针本身有常属性)
  cout<<"t5:"<<typeid(t5).name() << endl; // pki (p指针 k常属性 i int)
  // *t5 = 1; // 指针指向的内容为const b为const 不能改变
  t5 = NULL; // 指针本身没有const,可以改变
  return 0;
}
