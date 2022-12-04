/*
��̳�
��̳��е� ������ת��������ַƫ��
*/
#include <iostream>
using namespace std;

class A
{
public:
  int m_a;
  A() { cout << "~~~A()" << endl; }
  ~A() { cout << "~~~A����" << endl; };
};

class B
{
public:
  int m_b;
  B() { cout << "~~~B()" << endl; }
  ~B() { cout << "~~~B����" << endl; };
};

class C
{
public:
  int m_c;
  C() { cout << "~~~C()" << endl; }
  ~C() { cout << "~~~C����" << endl; }
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
    cout << "~~~D����" << endl;
  }
};

int main()
{
  A a;
  D d;
  cout << "size:" << sizeof(a) << endl;
  cout << "size:" << sizeof(d) << endl;

  D *d_ptr = &d; // ��dȡ��ַ
  cout << "�������������׵�ַ:" << d_ptr << endl;
  cout << "��������A������׵�ַ:" << &d.m_a << endl;
  cout << "��������B������׵�ַ:" << &d.m_b << endl;
  cout << "��������C������׵�ַ:" << &d.m_c << endl;

  // ת���ɻ��� ������ַƫ��
  cout << "------��ʽת����-----" << endl;
  A *d_a = &d;
  B *d_b = &d;
  C *d_c = &d;
  cout << "����ת�ɻ���A���׵�ַ:" << d_a << endl;
  cout << "����ת�ɻ���B���׵�ַ:" << d_b << endl;
  cout << "����ת�ɻ���c���׵�ַ:" << d_c << endl;

  // ת�س����� Ҳ������ַƫ��
  cout << "----static_cast---��̬ת�ɴ�����" << endl;
  D *d1 = static_cast<D *>(d_a);
  D *d2 = static_cast<D *>(d_b);
  D *d3 = static_cast<D *>(d_c);
  cout << "aת�ɴ������ �׵�ַΪ:" << d1 << endl;
  cout << "bת�ɴ������ �׵�ַΪ:" << d2 << endl;
  cout << "cת�ɴ������ �׵�ַΪ:" << d3 << endl;

  // ʹ��reinterpret_cast�ؽ���ת�� ����ָ��ƫ��
  cout << "----reinterpret_cast---��̬ת�ɴ�����" << endl;
  D *r1 = reinterpret_cast<D *>(d_a);
  D *r2 = reinterpret_cast<D *>(d_b);
  D *r3 = reinterpret_cast<D *>(d_c);
  cout << "aת�ɴ������ �׵�ַΪ:" << r1 << endl;
  cout << "bת�ɴ������ �׵�ַΪ:" << r2 << endl;
  cout << "cת�ɴ������ �׵�ַΪ:" << r3 << endl;

  return 0;
}