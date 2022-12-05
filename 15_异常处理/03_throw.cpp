/*
try 捕捉顺序是按从上到下而不是最优的
catch 1
catch 2
总结: catch 最匹配的放在前面
*/

#include <iostream>
#include <cstdio>
using namespace std;

class A
{
};
class B : public A
{
};

void foo()
{
  throw B(); // 抛出的为子类对象
}
int main(void)
{
  try
  {
    foo();
  }
  catch( B& e ) { // 参数为 子类类型引用
      cout << "2. B&" << endl;
  }
  catch (A &e)
  { // 参数为 基类类型引用 基类& 可以接受子类引用(因为子类范围>基类 可以从子类隐式转换成基类)
    cout << "1. A&" << endl;
  }
  // catch (B &e)
  // { // 参数为 子类类型引用
  //   cout << "2. B&" << endl;
  // }
  return 0;
}
