/*
钻石继承
分三层：
  公共基类
  多个中间子类
  汇聚子类
存在的问题：在汇聚子类中有多个公共基类
可以用::访问限定符号解决,但不推荐
因为,有的业务公共基类的变量应该是统一的
解决方案: 虚继承
*/

#include <iostream>
using namespace std;

class UpType // 公共基类
{
public:
  int m_up;
};

class MidType1 : public UpType //中间子类
{
public:
  int m_mid1;
};

class MidType2 : public UpType
{
public:
  int m_mid2;
};

class DownType : public MidType1, public MidType2 // 汇聚子类
{
public:
  int m_dow;
};

int main(){
  DownType down;
  cout<<"最底部class:的size:"<<sizeof(down)<<endl;
  // 内存分布: |m_mid1 + m_up|m_mid2 + m_up|m_down|
  // 20 = 4*5 = down + (mid1+top) + (mid2+top)
   
  // down.m_up = 1; //error
  down.MidType1::m_mid1 = 1;
  down.MidType1::m_up = 1;
  return 0;
}