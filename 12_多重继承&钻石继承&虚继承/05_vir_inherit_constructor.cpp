/*
����̳��� ���캯��
�������:
  1,�м����ഴ������ʱ,���м�����Թ���������Ӷ���������
  2,����ഴ��ʱ,�ɻ�������Թ���������Ӷ���������
*/
#include<iostream>
using namespace std;

class A{
  public:
  int a;
  A(int a1 = 2):a(a1){
  }
};

class B:virtual public A{
  public:
  int b;
  B(int a1,int b1):A(a1),b(b1){
  }
};

class C:virtual public A{
  public:
  int c;
  C(int a1,int c1):A(a1),c(c1){
  }
};

class D:public B,public C{
public:
 int d;
 D(int a1,int b1,int c1,int d1):A(a1),B(1111,b1),C(2222,c1),d(d1){
  // ֻ�� A(a1) �ܳ�ʼ���������� 
  // B(1111,b1) �е�a���ᱻ��ֵΪ1111,Cͬ��
 }
};

int main(){
  B boy(11, 22);
  cout<<boy.a<<" "<<boy.b<<endl;

  B boy2(11,22);
  cout<<boy.a<<" "<<boy.b<<endl;

  D dog(11,22,33,44);
  cout<<dog.a<<" "<<dog.b<<" "<<dog.c<<" "<<dog.d<<endl;

  return 0;
}




