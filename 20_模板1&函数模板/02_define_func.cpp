/*
用宏代替多个通用 （但有安全问题）
解决：加入通用函数模板T
##作用：在带参数的宏定义中将两个子串联接起来
*/
#include <iostream>
using namespace std;

// 代替以下
#define  MAX(T) T max_##T(T x,T y){return x>y?x:y;}

MAX(int)            // 实例化函数  int max_int(int x,int y)
MAX(double)         // double max_double(double x,double y)
MAX(string)         // string max_string(string x,string y)

#define Max(T) max_##T  // 用Max(T)  代替三个max_T()

int main(void)
{
  int nx = 10, ny = 20;
  double dx = 1.23, dy = 4.56;
  string sx = "world", sy = "hello";

  // 全部用define
  cout << Max(int)(nx, ny) << endl;
  cout << Max(double)(dx, dy) << endl;
  cout << Max(string)(sx, sy) << endl;
  char cx[100] = "world", cy[100] = "hello";
  cout << Max(string)(cx, cy) << endl; // hello cx>cy 比较首地址??   cx:cy 返回数据
  // 输出world 没问题啊？
  return 0;
}
