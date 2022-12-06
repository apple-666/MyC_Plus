/*
模板型成员函数: 类模板里的成员函数是 其他函数模板定义的 （类模板里有函数模板）
*/
#include <iostream>
using namespace std;

template <class T>
class One
{
public:
  // 模板型成员函数 = 函数模板 (直接定义)
  // template <class T2>
  // void coutt()
  // {
  //   cout << "template<T> template<T2>函数模板" << endl;
  // }

  // 外部定义
  template <class T2>
  void coutt();
};

// 外部定义
template <class T>
template <class T2>
void One<T>::coutt()
{
  cout << "template<T> template<T2>函数模板" << endl;
}

int main()
{

  One<int> o;
  o.coutt<float>();
  return 0;
}