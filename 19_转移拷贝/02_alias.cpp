/*
& ��ֵ����:
  ��ͨ��  ֻ��������ֵ
  const�� ��������ֵ���� 
&& ��ֵ����:
  ��ͨ��  ֻ��������ֵ,���޸�
  const:  ֻ��������ֵ,�����޸�
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
  //��ֵ
  int a=10,b=2;

  int& la = a;
  // int& lb = a+b;//error ����������ֵ
  const int& lb = b+b; // ��������ֵ


  int&& ra = a+a;
  ra = 1;//�����޸� ��ֵ����
  // int&& rb = b;// ����������ֵ

  const int&& ra2 = a+a;
  // ra2 = 1;// error ���ܸ�
}