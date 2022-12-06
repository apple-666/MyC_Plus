/*
类类型 有默认的构造初始化值
基本类型 没有

解决方法：
  T t = T(); 使用缺省初始化 ：类类型:Integer() 用构造
                             基本类型:int()   默认初始化
*/

#include <iostream>
using namespace std;

class Integer{
  public:
    Integer():m_i(100){}
  private:
    int m_i;
    friend ostream& operator<<(ostream& os,Integer const& i);
};

ostream& operator<<(ostream& os,Integer const& i)
{
  os<<i.m_i;
  return cout;
}
template<class T> 
void print(){
  // T t; 会有问题
  T t = T(); // 缺省初始化
  cout<<t<<endl;
}

int main()
{
  print<int>();   // 没有初始的
  print<double>(); // 没有初始的
  print<Integer>(); // 构造有初始化

  return 0;
}