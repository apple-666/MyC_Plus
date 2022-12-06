/*
模板的特化语法:
1,全局特化
  1.1 全类特化 整个类特化
  1.2 成员特化 整个函数特化
2,局部特化
  形式多，不建议用

*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T, class D>
class A
{
public:
  static void foo()
  {
    cout << "T D" << endl;
  }
};

// 局部特化 形式一
template <class T>
class A<T, int>
{
public:
  static void foo()
  {
    cout << "T int" << endl;
  }
};


// 局部特化 形式二
template <class T>
class A<T, T>
{
public:
  static void foo()
  {
    cout << "T T" << endl;
  }
};

int main()
{
  A<int,double>::foo();
  // A<double>::foo(); //error 不存在只有一个类型的 
  A<double,int>::foo(); // 使用了局部特化类
  // A<int,int>::foo(); // 形式1,2都可以 有冲突

  return 0;
}