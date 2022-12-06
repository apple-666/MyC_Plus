/*
函数模板: 一般用T
template<typename appleT>
appleT Max(appleT x,appleT y){
  return x>y?x:y;
}

template<typename|class appleT>
function(){

}

*/

#include <iostream>
using namespace std;

class Integer
{
public:
  Integer(int ii) : i(ii) {}
  bool operator>(Integer that)
  {
    return this->i > that.i;
  }
  int i;
};

template <typename appleT>
appleT Max(appleT x, appleT y)
{
  return x > y ? x : y;
}
// 编译出各个函数实例
// int Max(int x, int y){return x > y ? x : y}

int main(void)
{
  int i1 = 1, i2 = 2;
  cout << Max<int>(i1, i2) << endl;
  cout << Max(i1, i2) << endl; // 也行
  double d1 = 1.0, d2 = 0.4;
  cout << Max<double>(d1, d2) << endl;
  Integer int1(111), int2(10);
  cout << Max<Integer>(int1, int2).i << endl;
  return 0;
}
