/*
lambda�Ĳ���� [c](int d = 40){cout<<1<<};
  ���ֲ����
    []      ��
    [c]     ����    �������ɱ�
    [&c]    ����    �ɱ�
    [this]  ָ������ⲿ����ĳ�Ա
  �� = ��ֵ�������б��� ����this
  �� & �����ò������б��� ����this
ʹ���˲�����ԭ��:

class X{
public:
  X(int c):c(c){}
  operator()() {
    cout<<1;
  }
private:
  const int c;
}
X{c}() // ������������ʱ���ⲿ��c����
*/

#include <iostream>
#include <typeinfo>
using namespace std;

// lambda���ʽ - �����
int a = 10;
class Y
{
public:
  Y(int e2=11):e(e2){}
  void foo(int c = 30)
  {
    cout << "-----------[]------------" << endl;
    [](int d = 40)
    {
      cout << "a=" << a << endl;
      cout << "b=" << b << endl;
      //          cout << "c=" << c << endl; // error
      cout << "d=" << d << endl;
    }();

    cout << "-----------[c]------------" << endl;
    [c]()
    {
      cout << "c=" << c << endl;
    }();

    cout << "-----------[&c]------------" << endl;
    [&c]()
    {
      cout << "++c:" << ++c << endl;
    }();
    /*
    class X{
    public:
      X(int& c):c(c){}
      operator()( ) {
        cout<<1;
      }
    private:
      int& c;
    }
    X{c}()
    */
    cout << "-----------[this]------------" << endl;
    [this]()
    { cout << "e=" << e << endl; }();
    // xx{Y y}.operator()
  }

private:
  static int b;
  int e;
};
int Y::b = 20;

int main(void)
{
  Y y;
  y.foo();
  return 0;
}
