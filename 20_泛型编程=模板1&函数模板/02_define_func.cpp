/*
�ú������ͨ�� �����а�ȫ���⣩
���������ͨ�ú���ģ��T
##���ã��ڴ������ĺ궨���н������Ӵ���������
*/
#include <iostream>
using namespace std;

// ��������
#define  MAX(T) T max_##T(T x,T y){return x>y?x:y;}

MAX(int)            // ʵ��������  int max_int(int x,int y)
MAX(double)         // double max_double(double x,double y)
MAX(string)         // string max_string(string x,string y)

#define Max(T) max_##T  // ��Max(T)  ��������max_T()

int main(void)
{
  int nx = 10, ny = 20;
  double dx = 1.23, dy = 4.56;
  string sx = "world", sy = "hello";

  // ȫ����define
  cout << Max(int)(nx, ny) << endl;
  cout << Max(double)(dx, dy) << endl;
  cout << Max(string)(sx, sy) << endl;
  char cx[100] = "world", cy[100] = "hello";
  cout << Max(string)(cx, cy) << endl; // hello cx>cy �Ƚ��׵�ַ??   cx:cy ��������
  // ���world û���Ⱑ��
  return 0;
}
