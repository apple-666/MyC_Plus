/**
 * 三种继承方式:  原始标记-> 重新标记
 *  :public      三种不变
 *  :protected   pub->protect 其他不变    （额外的：子类 内部才能调用,不能通过对象调用）
 *  :private     全变private
 * 继承最基本的特点:
(1) 子类对象 内部包含 基类子对象
(2) 子类内部 可以访问 基类的 非私有(公有/保护)成员(变量/函数)
子类的fun 在定义表  

权限标记符:
在子类内部访问父类对象,根据原始标记
在子类外部访问父类对象,根据重新标记 (用对象调用时)
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

    // 子类可以访问父类的 公有,保护成员
    cout << m_a << endl;
    // Base::foo();
    cout << m_b << endl;
    bar();
    // cout<<m_c<<endl; // 父类私有成员没法访问
    // hum();
  }
  // void foo(){
  //   cout<<"子类的foo"<<endl;
  // }

private:
  int m_d;
  // void bar(){
  //   cout<<"子类的bar"<<endl;
  // }
};

int main()
{
  Base b;
  cout<<"Base类的大小:"<<sizeof(b)<<endl;
  Son a;
  cout<<"子类的大小(包含了父类的):"<<sizeof(a)<<endl;
  a.foo();
  a.Base::foo(); // 只有public继承可以 在外部调用
  return 0;
}
