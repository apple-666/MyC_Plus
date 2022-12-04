/*
解密多态 - 虚函数表
原理：
  1,使用virtual,会存虚表指针,指针指向对应类的虚函数表
  2,动态绑定函数: 指针pa指向b对象 + pa.func()
    1. 根据pa找到b对象所占内存空间
    2. 从b对象所占内存空间中 获取 虚表指针
    3. 根据虚表指针 找到 编译器根据B类信息制作的虚函数表
    4. 从虚函数表中 获取 虚函数的 入口地址
    5. 利用 函数的入口地址 调用 函数
性能上:
  动态绑定,没法使用内联,性能会缺失
*/

#include <iostream>
using namespace std;

// A虚函数表存储: A::foo A::bar
class A
{
public:
  virtual void foo() { cout << "A::foo" << endl; }
  virtual void bar() { cout << "A::bar" << endl; }
};

// B虚函数表存储: B::foo A::bar
class B : public A
{
public:
  void foo() { cout << "B::foo" << endl; }
};

int main(void)
{
  /*
    因为有virtual所以会存 虚表指针指向对应类的虚函数表
  */
  A a;
  cout << "没有成员变量的类A的内存大小:" << sizeof(a) << endl;
  B b;
  cout << "没有成员变量的类B的内存大小:" << sizeof(b) << endl;

  /*
  拿到虚表指针(本身为指针指向函数的指针,所以是二级指针)
  解释  &a 对a取地址 为三级指针了
        void(***)() 转为三级void指针
        *(void(***)()) 对三级指针解引用变为二级指针
  */
  void (**v_ptr)() = *((void (***)())(&a));
  v_ptr[0](); // =a.foo()
  v_ptr[1](); // =a.bar()

  void (**v_ptr2)() = *((void (***)())(&b));
  v_ptr2[0](); // =b.foo()
  return 0;
}
