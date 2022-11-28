/**类中 的静态成员函数
 * 成员函数: 能访问所有成员
 * 静态函数：只能访问静态成员
 * 
 */
#include <iostream>
using namespace std;

class A
{
public:
  int m_i;
  static int m_a; // 类中 能包含 本类的静态对象 作为成员变量

  void foo() const
  { // 用了const修饰func,为const class* this ,就只能修改const的类成员变量
    cout << "foo() is invoked" << endl;
    cout << m_i << endl; // ok
    cout << m_a << endl; // ok
    foo2();
  }

  static void foo2() // 不会传 class* this
  {
    cout << "foo2() is invoked" << endl;
    // cout << m_i << endl; // error
    cout << m_a << endl; // ok,静态成员函数内部可以访问静态成员
  }
};

int A::m_a = 1; // 这种形式来定义类中的静态成员变量

int main(void)
{
  A a; // 定义a(给a分配内存空间)-->编译器要计算a占据内存空间大小
  a.foo();

  A::foo2(); // 只有静态的能用A:: 方式调用
  a.foo2();
  return 0;
}
