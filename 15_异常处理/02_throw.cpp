/*
异常捕获中的拷贝次数:
情况一: 2次
  A a; throw a; 拷贝一个a到标准库中
  try catch(A e)从标准库拷贝一个a到e中
情况二: 0次 (使用引用技术)
  throw A(); A构造出一个的对象 (用匿名对象 可以被gcc++优化)
  thr catch(A& e) 

*/

#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
  A() {}
  A(const A &that) { cout << "A类的拷贝构造函数被调用" << endl; }
  ~A() {}
  const char *getInfo()
  {
    string msg = "I am A";
    return msg.c_str();
  }
};

void foo()
{
  //  A a;
  // throw a; // 克隆

  throw A(); // g++编译器优化
}

int main(void)
{
  try
  {
    foo();
  }
  catch (A& e)
  {
    cout << "捕获异常:" << e.getInfo() << endl;
    // ...
  }
  return 0;
}
