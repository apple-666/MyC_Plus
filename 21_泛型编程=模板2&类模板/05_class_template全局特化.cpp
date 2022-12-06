/*
模板的特化语法:
1,全局特化
  1.1 全类特化 整个类特化
  1.2 成员特化 整个函数特化
2,局部特化


全类
template<>
class AppleL<特化类型>{

}

成员
template<>
返回值类型 类名 <类型参数1...>::func名(){}
*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class CMath
{
public:
  CMath(T const &t1, T const &t2) : m_t1(t1), m_t2(t2) {}
  T add()
  {
    return m_t1 + m_t2;
  }

private:
  T m_t1;
  T m_t2;
};

// 全类特化
// template <>
// class CMath<char* const>
// {
// public:
//   CMath<char* const>(char* const& t1, char* const& t2) : m_t1(t1), m_t2(t2) {}
//   char* const add()
//   {
//     return strcat(m_t1, m_t2);
//   }

// private:
//   char* const m_t1;
//   char* const m_t2;
// };

template<> char* const CMath <char* const>::add(){
  return strcat(m_t1, m_t2);
}

int main()
{

  CMath<int> m1(1, 2);
  cout << m1.add() << endl;
  CMath<double> m2(1.1, 2.2);
  cout << m2.add() << endl;

  char c1[10] = "apple", c2[10] = " come";
  CMath<char* const > m3(c1, c2); // const 可加可不加
  cout<<m3.add()<<endl; // 两个指针没法相加
  return 0;
}