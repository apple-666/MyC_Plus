/*
覆盖的条件:
1,基类函数为成员函数,不是全局/静态函数
2,用virtual
3,子类覆盖版本,有相同func名,形参表常属性完全一致
4,子类的返回值要一致(除了子类返回指针 是 基类的返回指针的子类)
5,如果是异常返回值,
    返回值时基本类型 子类的异常返回值要相同或少于基类的 
    返回值时类类型 子类的异常返回值要相同或小于基类的 
*/
#include <iostream>
using namespace std;
// 详谈覆盖
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
  //  void doo( ) throw(B,D,A) {  cout << "Y::doo" << endl;   } // error-异常说明过多
  //  void doo( ) throw(B,A) {  cout << "Y::doo" << endl;   } // error-异常说明不同
  //  void doo( ) throw(C,D) {  cout << "Y::doo" << endl;   } // ok
  void doo() throw(C) { cout << "Y::doo" << endl; } // ok

  //  void coo( ) throw(int,double,float) {   cout << "Y::coo" << endl;  } // error-异常说明过多
  //  void coo( ) throw(int,float) {   cout << "Y::coo" << endl;  } // error-异常说明不同
  void coo() throw(int) { cout << "Y::coo" << endl; } // ok

  //  A* boo( ) { cout << "Y::boo" << endl;   } // error-返回值类型太不一致
  C *boo() { cout << "Y::boo" << endl; } // ok C是B的子类

  //  void aoo( int a=0 ) {   cout << "Y::aoo" << endl;   } // error-形参不一致
  //  void aoo( ) const {   cout << "Y::aoo" << endl;   } // error-常属性不一致
  //  int aoo( ) {   cout << "Y::aoo" << endl; return 0;  } // error-返回值类型太不一致
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
