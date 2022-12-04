/*
实现多态条件:
1,基类有virtual的函数
2,子类覆盖了基类同名函数,用基类指针/引用 指向子类去调用虚函数
*/

#include <iostream>
using namespace std;

class Base{
  public:
    Base(){
      cout<<"no1,Base::构造";
      this->same1();// 是基类调用的
      
    }
    ~Base(){
      cout<<"Base:析构"<<endl;
    }
    void foo(/*Base* this */) { // 基类指针指向子类的same1
      this->same1(); // 是子类调用的
    }
    virtual void same1(){
      cout<<"Base::same1"<<endl;
    }
};

class Derived:public Base{
  public:
    Derived(){
      //no.1 Base(); 基类.Base
      //no.2 Derived 子类.Derived;
      cout<<"no2,Derived::构造"<<endl;
    }
    ~Derived(){
      cout<<"Derived::析构"<<endl;
    }
    void same1() {
      cout<<"Derived::same1"<<endl;
    }
};

int main(){

  // Base bse;
  // bse.foo();

  Derived der;
  // der.same1();

  der.foo();// foo(&der) 调用的基类的foo
  return 0;
}