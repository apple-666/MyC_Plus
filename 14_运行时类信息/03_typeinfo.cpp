/*
获取数据类型
typeid操作符 
  1,运行时获取数据类型信息
  2,无法获取 对象本身的 常属性信息
typeid获取类类型:
  虚基类:
    根据指针指向的对象类型
  非虚基类:
    指针本身的类型
*/
#include <iostream>
#include <typeinfo>
using namespace std;

class A
{ // 编译器根据A类信息,将制作一张虚函数表  "A"...|A::foo的地址
public:
  virtual void foo() {}
};
class B : public A
{ // 编译器根据B类信息,将制作一张虚函数表  "B"...|A::foo的地址
};

int main()
{

  B b; // |虚表指针| --> 编译器根据B类信息制作的虚函数表
  A *pa = &b;
  A &ra = b;


  cout << typeid(*pa).name() << endl; // pa-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
  cout << typeid(ra).name() << endl;  //  ra-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"

  int a;
  const type_info &inf = typeid(a);
  // 1. 获取对象m的类型信息
  // 2. 创建一个type_info类的对象
  // 3. 将 获取的m的类型信息 保存到 type_info类对象的 各个私有成员变量中
  // 4. 返回这个 type_info类对象的 常引用
  cout << "类型" << inf.name() << endl;
  cout << typeid(a).name() << endl;

  int bb;
  double d;
  float f;
  cout << (typeid(a) == typeid(bb)) << endl; // typeid(m).operator==( typeid(cm) )
  cout << (typeid(bb) == typeid(d)) << endl; // typeid(m).operator==( typeid(cm) )
}