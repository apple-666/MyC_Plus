/*
lambda 表达式:
[捕获表](形参表)-> 返回类型{函数体};
原理:
  1,生成一个类
  2,类定义小括号操作符
  3,返回类的匿名对象
auto f = [](int x,int y)->int {return x>y?x:y;};

class xx{
  public:
    int operator()(int x,int y){
      return x>y?x:y;
    }
};
auto f = xx{}
f(1,2) -> f.operator()(1,2);
*/
#include <iostream>
#include <typeinfo>
using namespace std;

int Max(int x, int y)
{
  return x > y ? x : y;
}

int main(void)
{
  int a = 10, b = 20;
  cout << Max(a, b) << endl;

  auto f = [](int x, int y) -> int
  { return x > y ? x : y; };
  cout << f(10, 20) << endl;
  cout << "f的类型:" << typeid(f).name() << endl;

  // 简写
  auto f2 = [](int x, int y)
  { return x > y ? x : y; }; // 返回值省略
  cout << f2(10, 20) << endl;
  /*
  简写原理：
    class xx{
      public:
        auto operator()(int x,int y) ->decltype(x>y?x:y){
          return x>y?x:y;
        }
    };
  */
  cout <<  [](int x, int y)
  { return x > y ? x : y; }(a,b)<< endl;


  cout<<"lambda没有返回值的"<<endl;
  auto f3 = [](){cout<<"这里是一行-------"<<endl;};
  f3();
  //简写 省略()
  auto f4 = []{cout<<"这里是一行-------"<<endl;};
  f4();

  return 0;
}
