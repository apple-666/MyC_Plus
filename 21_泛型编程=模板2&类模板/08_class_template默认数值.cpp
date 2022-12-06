/*
模板 的类型参数表可以有 数值型的参数
：只能为整数，可以有默认值
template<class T,size_t a=10>
class A{

}

*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T, size_t maxSize=10>
class A
{
public:
  void foo()
  {
    cout<<"数组默认最大值："<<maxSize<<endl;
  }
  T& operator[](int i){
    return m_arr[i];
  }
  size_t size() {
    return maxSize;
  }
private:
  T m_arr[maxSize];
};

int main()
{ 
  A<int> a1;
  a1.foo();
  for(int i=0; i<a1.size();i++) a1[i] = i+1;
  for(int i=0; i<a1.size();i++) cout<<a1[i]<<endl;

  A<int,100> a2;
  a2.foo();
  return 0;
}