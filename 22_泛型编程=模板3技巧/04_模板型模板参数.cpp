/*
模板型模板参数: 类模板类型参数 是类目定义的
*/

#include <iostream>
using namespace std;

template <class T>
class Array
{
public:
  T m_arr[10];
  T &operator[](int i) { return m_arr[i]; }
};

template <class T2,template<class M>class C =Array> // 模板型模板参数
class Sum
{
public:
  Sum(C<T2>& s):m_s(s){} //构造
  T2 value(){
    T2 sum = 0;
    for(int i=0; i<10; i++) sum+=m_s[i];
    return sum;
  }
private:
  C<T2> m_s; // 模板型成员变量
};

int main(){
  Array<int> a1; // a1是数组[10]
  for(int i=0; i<10; i++) a1[i] = i;
  Sum<int,Array> s1(a1);
  cout<<s1.value()<<endl;
  return 0;
}