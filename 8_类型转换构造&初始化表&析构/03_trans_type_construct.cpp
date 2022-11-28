/***
 * 类型转换构造函数
 * explicit: 修饰转换函数,用了这个关键词就必须强制转换static_cast
 * frient: 友元申明, 友元可以访问本类私有属性
 * 猫 -> 转成 -> 狗
 */
#include <iostream> 
using namespace std;

class Cat
{
public:
  // 类型转换函数
  explicit Cat(const char *name) : m_name(name)
  {
    cout << "Cat类的类型转换构造函数被调用" << endl;
  }
  void talk()
  {
        cout << m_name << ": 喵喵~~~" << endl;

  }

private:
  string m_name;
  friend class Dog; // 友元申明: 让Dog能访问cat的private属性
};

class Dog
{
public:
  Dog(const char *name) : m_name(name)
  {
  }
  // 类型转换构造函数
  explicit Dog(const Cat &that) : m_name(that.m_name)
  {
    cout << "Dog类的类型转换构造函数被调用" << endl;
  }

  void talk()
  {
        cout << m_name << ": 汪汪~~~" << endl;

  }

private:
  string m_name;
};

#include <iostream>
using namespace std;
int main(void)
{ 
  Cat qw("小白");
  qw.talk();

  // Dog qw1(qw); // ok
  // qw1.talk();
  //  Dog bigyellow = qw; //  ok 定义 匿名Dog类对象, 利用 匿名Dog类对象.Dog( smallwhite )
  //  bigyellow.talk();                             // Dog bigyellow = 匿名Dog类对象;
  
  
   // ok 用了explicit,就一定要强制转换
   Dog qw2 = static_cast<Dog>(qw);
  qw2.talk();

  // static_cast<Dog>(qw).talk();

  return 0;
}
