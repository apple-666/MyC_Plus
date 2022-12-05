/*
虚函数的应用
  动态类型转换: 基类指针/引用 转子类的 （运行时获取类 信息进行转换）
  指向的对象类型和要转成的对象类型相同则 成功,否则失败

*/
#include <iostream>
using namespace std;
class A
{ // 因为有虚函数,所以编译器根据A类信息,将制作一张虚函数表   "A"...|A::foo的地址
  virtual void foo() {} // 要有虚函数才能动态转
};
class B : public A
{ // 编译器根据B类信息,将制作一张虚函数表   "B"...|A::foo的地址
};
class C : public B
{ // 编译器根据C类信息,将制作一张虚函数表   "C"...|A::foo的地址
};
class D
{ // 编译器根据D类信息,不制作虚函数表(因为没有虚函数)
};
int main(void)
{
  B b;
  A *pa = &b; //大->小,隐式转换
  B *pb;
  C *pc;
  D *pd;
  cout << "-----dynamic_cast（更安全，更严谨）-----" << endl;
  pb = dynamic_cast<B *>(pa); // pa指向的是B类,所以可以转成B指针
  //检查过程： pa指向b类内存空间 找虚表指针 找虚函数表 发现里面是B类的信息 要转的也是B类的
  cout << "A* pa ---> B* pb: " << pb << endl; // 成功
  pc = dynamic_cast<C *>(pa);
  cout << "A* pa ---> C* pc: " << pc << endl; //空指针 失败
  pd = dynamic_cast<D *>(pa); // 动态转可以
  cout << "A* pa ---> D* pd: " << pd << endl; //空指针 失败

  cout << "-----static_cast(不严谨)-----" << endl;
  pb = static_cast<B *>(pa);
  // 检查过程: 编译器检查 A*-->B* 的反向 B*-->A* 可以隐式,那就可以过
  cout << "A* pa ---> B* pb: " << pb << endl;
  pc = static_cast<C *>(pa);
  cout << "A* pa ---> C* pc: " << pc << endl; // 过了,没有查出错误
//  pd = static_cast<D*>(pa); // D 不属于子类 没法用static转换
//  cout << "A* pa ---> D* pd: " << pd << endl;
  return 0;
}
