/*
模板类型可以默认
template<class T=int,class D=double>
class A{

}

*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T=double, class D=int>
class A
{
public:
  void foo()
  {
    cout<<"m_t:"<<typeid(m_t).name()<<" m_d:"<<typeid(m_d).name()<<endl;
  }
private:
  T m_t;
  D m_d;
};

int main()
{ 
  A<int,int> a1;
  a1.foo();
  A<> a2;
  a2.foo();
  return 0;
}