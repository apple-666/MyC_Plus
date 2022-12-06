/*
类模板： 特点：分布完成功能
  只有使用了 实例化,成员变量,函数
  对应的构造,成员变量,函数才会被添加进类模板

}
*/
#include <iostream>
using namespace std;

class Integer
{
public:
  Integer(const int &i2 = 1) : i1(i2) {}
  Integer operator+(Integer that)
  {
    return that.i1 + i1;
  }
  int i1;
};

template <class T>
class AppleL
{
public:
  AppleL(const T &a1, T const &a2) : m1(a1), m2(a2) {}
  // T add(){
  //   return m1 + m2;
  // }

  // 可以外部定义
  T add();

private:
  T m1;
  T m2;
};

template <class T>
T AppleL<T>::add()
{
  return m1 + m2;
}
// class AppleL<int> {} 创建的类的实例

int main()
{

  Integer i1(1);
  Integer i2(2);
  AppleL<Integer> ai(i1, i2);
  ai.add();
  return 0;
}