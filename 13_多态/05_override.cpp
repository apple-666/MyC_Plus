/*
���ǵ�����:
1,���ຯ��Ϊ��Ա����,����ȫ��/��̬����
2,��virtual
3,���า�ǰ汾,����ͬfunc��,�βα�������ȫһ��
4,����ķ���ֵҪһ��(�������෵��ָ�� �� ����ķ���ָ�������)
5,������쳣����ֵ,
    ����ֵʱ�������� ������쳣����ֵҪ��ͬ�����ڻ���� 
    ����ֵʱ������ ������쳣����ֵҪ��ͬ��С�ڻ���� 
*/
#include <iostream>
using namespace std;
// ��̸����
class A
{
};
class B : public A
{
};
class C : public B
{
};
class D
{
};

class X
{
public:
  virtual void aoo() { cout << "X::aoo" << endl; }
  virtual B *boo() { cout << "X::boo" << endl; }
  virtual void coo() throw(int, double) { cout << "X::coo" << endl; }
  virtual void doo() throw(B, D) { cout << "X::doo" << endl; }
};
class Y : public X
{
public:
  //  void doo( ) throw(B,D,A) {  cout << "Y::doo" << endl;   } // error-�쳣˵������
  //  void doo( ) throw(B,A) {  cout << "Y::doo" << endl;   } // error-�쳣˵����ͬ
  //  void doo( ) throw(C,D) {  cout << "Y::doo" << endl;   } // ok
  void doo() throw(C) { cout << "Y::doo" << endl; } // ok

  //  void coo( ) throw(int,double,float) {   cout << "Y::coo" << endl;  } // error-�쳣˵������
  //  void coo( ) throw(int,float) {   cout << "Y::coo" << endl;  } // error-�쳣˵����ͬ
  void coo() throw(int) { cout << "Y::coo" << endl; } // ok

  //  A* boo( ) { cout << "Y::boo" << endl;   } // error-����ֵ����̫��һ��
  C *boo() { cout << "Y::boo" << endl; } // ok C��B������

  //  void aoo( int a=0 ) {   cout << "Y::aoo" << endl;   } // error-�ββ�һ��
  //  void aoo( ) const {   cout << "Y::aoo" << endl;   } // error-�����Բ�һ��
  //  int aoo( ) {   cout << "Y::aoo" << endl; return 0;  } // error-����ֵ����̫��һ��
  void aoo() { cout << "Y::aoo" << endl; } // ok
};

int main(void)
{
  X *px = new Y;
  px->aoo();
  px->boo();
  px->coo();
  px->doo();
  return 0;
}
