/*
虚继承 virtual 标识符 (常用 class s:virtual public top)
  1,可以保证：
    1,公共基类对象在汇聚对象中只存在一份
    2,公共基类对象可以被多个中间子类共享
如何实现：
  中间子类有指针:保存中间子类首地址到公共虚基类的首地址的偏移量
*/


#include <iostream>
using namespace std;

class UpType // 公共虚基类
{
public:
  int m_age;
};

class MidType1 : virtual public UpType //中间子类
{
public:
  int m_mid1;
  void setAge(int age){ // 检测是否共享top的对象
    this->m_age = age; // 指向父类的m_age
  }
  int getAge(){
    return this->m_age; // 检测是否共享top的对象
  }
};

class MidType2 : virtual public UpType
{
public:
  int m_mid2;
  int getAge2(){
    return this->m_age;
  }
};

class DownType : public MidType1, public MidType2 // 汇聚子类
{
public:
  int m_dow;
  void foo(){
    m_age = 1;
  }
};

int main(){
  DownType down;
  cout<<"汇聚子类的size是:"<<sizeof(down)<<endl; // size更大了,多了一个字节
  /*
  内存分布变化: 
  |m_mid1 + m_up |m_mid2 + m_up |m_down|  
  ->
  |m_mid1 + *this|m_mid2 + *this|m_down|m_up|
  */ 
  
  down.setAge(22);
  cout<<down.getAge()<<endl;
  cout<<down.getAge2()<<endl;
  down.m_age = 1; //error 虚继承没法访问
  return 0;
}