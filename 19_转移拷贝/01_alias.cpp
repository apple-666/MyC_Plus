/*
&& ��ֵ���� ����ֵȡ����
*/

#include <iostream>
using namespace std;

int foo()
{
  int m = 10;
  return m;
}

int main()
{
  /*
  ��ֵ�� �����ڴ� ��ȡֵ
  */
  int a = 10;
  int &ra = a;
  const int &cra = a;
  const int b = 10;
  const int &cb = b;

  /*
  ��ֵ�� �����ڴ� ����ȡֵ
  ��������ֵ�� ��ֵ
  ��const/����/���� ���Խ���foo()��ֵ �����ӳ�����ֵ����������
  */
  const int rf0 = /*�����ڴ� 10*/ foo();
  const int &rf = 10;
  int &&rf2 = foo(); // ����������
  const int &rf3 = foo(); 
}