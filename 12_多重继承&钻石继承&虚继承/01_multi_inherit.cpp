/*
多继承
多继承中的 父子类转换会作地址偏移
*/
#include <iostream>
using namespace std;

class A
{
public:
  int m_a;
  A() { cout << "~~~A()" << endl; }
  ~A() { cout << "~~~A析构" << endl; };
};

class B
{
public:
  int m_b;
  B() { cout << "~~~B()" << endl; }
  ~B() { cout << "~~~B析构" << endl; };
};

class C
{
public:
  int m_c;
  C() { cout << "~~~C()" << endl; }
  ~C() { cout << "~~~C析构" << endl; }
};

class D : public A, public B, public C
{
public:
  int m_d;
  D()
  {
    cout << "~~~~D()" << endl;
  }
  ~D()
  {
    cout << "~~~D析构" << endl;
  }
};

int main()
{
  A a;
  D d;
  cout << "size:" << sizeof(a) << endl;
  cout << "size:" << sizeof(d) << endl;

  D *d_ptr = &d; // 对d取地址
  cout << "整个子类对象的首地址:" << d_ptr << endl;
  cout << "在子类中A基类的首地址:" << &d.m_a << endl;
  cout << "在子类中B基类的首地址:" << &d.m_b << endl;
  cout << "在子类中C基类的首地址:" << &d.m_c << endl;

  // 转换成基类 会作地址偏移
  cout << "------隐式转换后-----" << endl;
  A *d_a = &d;
  B *d_b = &d;
  C *d_c = &d;
  cout << "子类转成基类A的首地址:" << d_a << endl;
  cout << "子类转成基类B的首地址:" << d_b << endl;
  cout << "子类转成基类c的首地址:" << d_c << endl;

  // 转回成子类 也会作地址偏移
  cout << "----static_cast---静态转成大子类" << endl;
  D *d1 = static_cast<D *>(d_a);
  D *d2 = static_cast<D *>(d_b);
  D *d3 = static_cast<D *>(d_c);
  cout << "a转成大子类后 首地址为:" << d1 << endl;
  cout << "b转成大子类后 首地址为:" << d2 << endl;
  cout << "c转成大子类后 首地址为:" << d3 << endl;

  // 使用reinterpret_cast重解释转换 不做指针偏移
  cout << "----reinterpret_cast---静态转成大子类" << endl;
  D *r1 = reinterpret_cast<D *>(d_a);
  D *r2 = reinterpret_cast<D *>(d_b);
  D *r3 = reinterpret_cast<D *>(d_c);
  cout << "a转成大子类后 首地址为:" << r1 << endl;
  cout << "b转成大子类后 首地址为:" << r2 << endl;
  cout << "c转成大子类后 首地址为:" << r3 << endl;

  return 0;
}