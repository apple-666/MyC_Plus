/*
�ú������ͨ�� �����а�ȫ���⣩
*/

#include <iostream>
using namespace std;

// ��������
#define appleMax(x, y) (x > y ? x : y)

int max_int(int x, int y)
{
  return x > y ? x : y;
}
double max_double(double x, double y)
{
  return x > y ? x : y;
}
string max_string(string x, string y)
{
  return x > y ? x : y;
}

int main(void)
{
  int nx = 10, ny = 20;
  cout << max_int(nx, ny) << endl;
  double dx = 1.23, dy = 4.56;
  cout << max_double(dx, dy) << endl;
  string sx = "world", sy = "hello";
  cout << max_string(sx, sy) << endl;

  // ȫ����define
  cout << appleMax(nx, ny) << endl;
  cout << appleMax(dx, dy) << endl;
  cout << appleMax(sx, sy) << endl;
  char cx[100] = "world", cy[100] = "hello";
  cout << appleMax(cx, cy) << endl; // hello cx>cy �Ƚ��׵�ַ??   cx:cy ��������
  // ���world û���Ⱑ��
  return 0;
}
