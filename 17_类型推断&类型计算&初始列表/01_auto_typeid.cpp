/*
ʹ��auto �������������ƶ�
*/

#include <iostream>
using namespace std;

// �������������Ƶ����������ճ�����

int main(void)
{
  int a = 10;
  const int b = 10;
  auto t = a;
  cout << t << " " << typeid(t).name() << endl;
  cout << &t << " " << &a << endl;
  // cout<<&b<<" "<<&t<<" "<<&a<<endl;

  auto t2 = b;
  cout << t2 << " " << typeid(t2).name() << endl;
  cout << &t2 << " " << &b << endl;
  t2++; // const -> auto ��û���õ������Կ��Ը���

  const auto t3 = b;
  cout << t3 << " " << typeid(t3).name() << endl;
  cout << &t3 << " " << &b << endl;
  // t3++; // const + auto 

  // ָ���� �����õ�������
  auto t4 = &a; // ��ֵ�� int*
  *t4 = 11; 
  cout<<"t4:"<<typeid(t4).name() << endl; // pi


  auto t5 = &b; // ��ֵ�� const int* ��ʾ��ָ��ָ�������г����� (const int* const p �ʹ���ָ�뱾���г�����)
  cout<<"t5:"<<typeid(t5).name() << endl; // pki (pָ�� k������ i int)
  // *t5 = 1; // ָ��ָ�������Ϊconst bΪconst ���ܸı�
  t5 = NULL; // ָ�뱾��û��const,���Ըı�
  return 0;
}
