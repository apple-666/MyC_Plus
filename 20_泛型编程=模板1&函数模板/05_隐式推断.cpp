/*
����ģ���е���ʽ�ƶ�: max(1,2) �ƶϳ� max<int>(1,2)
*/

#include <iostream>
using namespace std;
// ����ģ��
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

  // Func<nx>; //�޷��ƶ�T��
  Func<double>(nx);// T��Ϊdouble D��Ϊint
  // Max(1,2.0); // �಻ͬ

  // Human(1); //�޷��ƶ�R
  Human<double>(1); // �������ƶϳ�
  return 0;
}
