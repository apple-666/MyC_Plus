/*

*/
#include <iostream>
using namespace std;

class Base
{
public:
  int m_a;
  void foo() { cout << "Base::foo" << endl; }

protected:
  int m_b;
  void bar() { cout << "Base::bar" << endl; }

private:
  int m_c;
  void hum() { cout << "Base::hum" << endl; }
};

class Son :public Base
{
public:
  void fun()
  {
  }

private:
  int m_d;
};

int main()
{
  Son son;
  // 子类转父类 范围缩小(因为子类内容>=父类内容) 编译器隐式转换
  Base far = son;
  // 子类指针转父类指针 范围缩小(因为子类内容>=父类内容) 编译器隐式转换
  Base* farr = &son;
  Base& farrr = son;

  // 指针本身只占4字节,指针的类型决定了指针的眼界(数据类型的字节)和补偿(+1 = +n字节)
  // 父类转子类 要强制转换 
  Base* far2 = &son;
  Base& far3 = son;
  Son* son2 = static_cast<Son*>(far2);
  Son& son3 = static_cast<Son&>(far3);
  return 0;
}
