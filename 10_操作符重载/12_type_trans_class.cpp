/**
 * class类型 之间的转换: A -> B
 *  方法一：(编译先用)类型转换构造函数 A中写friend + B中写构造Dog(Cat)
 *  方法二: 类型转换操作符函数 A中写操作符就行
*/

#include<iostream>
using namespace std;

class Dog; // 短式申明 告诉 Dog是个class (用于16行的Dog)

class Cat{
public:
  Cat(const char* name): m_name(name) {}
  // 类型转换操作符函数
  operator Dog() const; // 声明 定义写后面(因为还没有编译到Dog)
  void talk(){
    cout<<"name:"<<m_name<<" 在喵喵"<<endl;
  }
private:
  string m_name;
};

class Dog{
public:
  Dog(const char* name):m_name(name) {}

  // 类型转换构造函数 
  // Dog(const Cat& cat):m_name(cat.m_name) {
  //       cout << "Dog类的类型转换构造函数被调用" << endl;
  // }
  void talk(){
    cout<<"name:"<<m_name<<" 在旺旺"<<endl;
  }
private:
  string m_name;
};

Cat::operator Dog()const {
  cout<<"Cat类的类型转换操作符函数被调用"<<endl;
  return Dog(this->m_name.c_str());
}

int main(){
  Cat a1("huahua");
  a1.talk();

  /**
   * 方法一:
   *  .Dog(Cat a1) 类型转换构造函数 
   * 方法二:
   *  a1.operator Dog() 类型转换操作符函数
  */
  Dog a2 = a1; 
  a2.talk();

  return 0;
}
