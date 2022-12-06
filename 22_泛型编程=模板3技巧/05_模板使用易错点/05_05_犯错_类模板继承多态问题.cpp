/*
类模板继承后的多态问题
  类模板的普通函数可以是虚函数 用virtual修饰
  类模板的成员模板函数不能是虚函数 无法用virtual
    (因为：虚函数表在实例化类模板时就产生。但是函数模板的实例化是在编译之后调用了才会完成)
*/

#include <iostream>
using namespace std;


template<class T>
class Base{
  public:
    virtual void foo(){
      cout<<"Base:::::"<<endl;
    }
};

template<class T,class D> class Derived:public Base<T>{
  public:
    void foo(){
      cout<<"Derived::foo:"<<endl;
    }
};


int main()
{
  Derived<int,double> d;
  Base<int>* b = &d;
  b->foo();

  return 0;
}