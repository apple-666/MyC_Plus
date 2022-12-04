/**
 * 重载 << >> 输入输出操作符
 * cout 为 输出流对象
 *  <<   要求: operator<<(ostream,<T>) 
 *  1,左操作数:非常左值的输出流对象
 *  2,右操作数:左值或右值
 *  3,return: 左操作数本身
 * 
 * >> 要求  operator>>( istream, a )
 *  Human类不能为const 要输入
 */

#include <iostream>
using namespace std;
class Human
{
public:
  Human(int age = 0, const char *name = "无名") : m_age(age), m_name(name)
  {
  }
  void getinfo()
  {
    cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
  }
  // ostream是标准模板库的类,只能放在全局域中

private:
  int m_age;
  string m_name;
  friend ostream &operator<<(ostream &os, const Human &that);
  friend istream &operator>>(istream &is, Human &that);
};

// ostream &operator<<(ostream &os, int) {} 实现方式进行延伸
ostream &operator<<(ostream &os, const Human &that)
{
  os << "name:" << that.m_name << " age:" << that.m_age;
  return os;
}
istream& operator>>( istream& is, Human& that ) {
    is >> that.m_name>>that.m_age;
    return is;
}
int main(void)
{
  Human a(22, "apple"), b(20, "赵云"); // 非常左值
  cout << a << endl;
  cout << Human(23, "apple") << endl
       << endl
       << endl; // 返回的是左值本身所有可以进行串联
  cin>>a;
  cout<<a<<endl;
  return 0;
}
