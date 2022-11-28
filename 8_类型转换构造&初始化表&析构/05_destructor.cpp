/***
 * 析构函数: 销毁对象前自动调用一次
 * ~Human( ) {}
 * 作用: 销毁成员变量
 * 对于基本类型的成员变量m_age,什么都不做
   对于类类型的成员变量m_name,利用 m_name.~string()
*/

// 析构函数
#include <iostream>
using namespace std;
class Human
{
public:
  void getinfo(/* Human* this */)
  {
    cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
  }
  Human(int age = 0, const char *name = "无名") : m_age(age), m_name(name)
  {
    cout << "Human类缺省构造函数被调用" << endl;
  }
  Human(const Human &that) : m_age(that.m_age), m_name(that.m_name)
  {
    cout << "Human类的拷贝构造函数被调用" << endl;
  }
  Human &operator=(/* Human* this */ const Human &that)
  {
    // 编译器不会在自定义的拷贝赋值函数中塞任何操作
    cout << "Human类拷贝赋值函数被调用" << endl;
    this->m_age = that.m_age;
    this->m_name = that.m_name;
    return *this;
  }
  //  如果类没有提供析构函数,编译器将提供一个默认的析构函数
  /*  ~Human( ) {
          对于基本类型的成员变量m_age,什么都不做
          对于类类型的成员变量m_name,利用 m_name.~string()
      } 释放 m_age / m_name 本身所占内存空间*/

  ~Human()
  {
    cout << "我就是~~~~~析构函数" << endl;

    // 最后默认会释放 m_age / m_name 本身所占内存空间
  }

private:
  int m_age;     // 基本类型的成员变量
  string m_name; // 类类型的成员变量
};
int main(void)
{
  Human h; // 定义h,利用h.Human() --> (无名,0)
  cout << "h被赋值前: ";
  h.getinfo();

  Human h2(22, "张飞"); // 定义h2,利用h2.Human(22,"张飞") --> (张飞,22)
  h2.getinfo();

  Human h3(h2); //= h2; 定义h3,利用h3.Human(h2) --> h3维护的数据 和 h2维护的数据 内容相同
  h3.getinfo();

  h = h3; // h.operator=(h3) 拷贝赋值函数 --> h维护的数据 和 h3维护的数据 内容相同
  cout << "h被赋值后: ";
  h.getinfo();
  return 0;
} //(1) 利用h.~Human()  h2.~Human()  h3.~Human()    (2) 释放 h/h2/h3 本身所占内存空间
