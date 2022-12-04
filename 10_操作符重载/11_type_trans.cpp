/**
 * 自定义 类型转换
 * 基本类型转 -> class类型 用类型转换构造函数
 * int -> integer
 * integer -> int
*/

#include<iostream>
using namespace std;

class Integer {
public:
  Integer(int i):m_i(i){ // int -> integer 类型转换构造函数
  }
  operator int( /*const Integer* this */) const { // 类型转换操作符函数 
      return this->m_i;
  }

private:
  int m_i;
  friend ostream& operator<<(ostream& os,const Integer& that);
};

ostream& operator<<(ostream& os,const Integer& that){
  os<<"Integer:"<<that.m_i<<endl;
  return os;
}


int main() {
  int a = 1;
  Integer b = a;//int->Integer 转换成匿名Integer对象.Integer(int n) 类型转换构造函数
                // a.operator Integer() a是int类,里面肯定没有这个函数
  // Integer c = Integer(a) // 和上一行一样
  cout<<b<<endl;

  int c = b; //Integer->int 转换成匿名int对象.int(Integer B) 但是没有这个函数
             // 应该是 b.operator int() 类型转换构造函数
  cout<<c<<endl;
  return 0;
}