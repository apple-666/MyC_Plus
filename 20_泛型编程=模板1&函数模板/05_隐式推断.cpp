/*
函数模板中的隐式推断: max(1,2) 推断成 max<int>(1,2)
*/

#include <iostream>
using namespace std;
// 函数模板
template <typename T>
T Max(T x, T y)
{
  return x > y ? x : y;
}

template <class T, class D>
void Func(D x)
{
}

template <class R,class T>R Human(T x){
  R r;
  return r;
}

int main(void)
{
  int nx = 10, ny = 20;
  cout << Max(nx, ny) << endl;
  //      Max<>(nx,ny)==>Max<int>(nx,ny)
  double dx = 1.23, dy = 4.56;
  cout << Max(dx, dy) << endl;
  //      Max<double>(dx,dy)
  string sx = "world", sy = "hello";
  cout << Max(sx, sy) << endl;
  //      Max<string>(sx,sy)

  // Func<nx>; //无法推断T类
  Func<double>(nx);// T类为double D类为int
  // Max(1,2.0); // 类不同

  // Human(1); //无法推断R
  Human<double>(1); // 都可以推断出
  return 0;
}
