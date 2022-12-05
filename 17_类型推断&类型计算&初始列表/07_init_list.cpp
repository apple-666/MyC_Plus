/*
列表初始化:追求的书写代码一致性 (因为初始化有:= () {} )
类型 对象{初始值}
{数据}      初始化
{多个数据}  数组初始化
*/

#include <iostream>
#include <typeinfo>
using namespace std;

struct BD
{
  int m_year;
  int m_month;
  int m_day;
};
struct Student
{
  string m_name;
  int m_age;
  BD m_bday;
};

class Human
{
public:
  Human(int age = 0, const char *name = "null") : m_age(age), m_name(name)
  {
  }
  int m_age;
  string m_name;

private:
};

int main()
{
  // 基本类型变量
  int a{123};
  cout << a << endl;

  // 数组
  int b[]{1, 2, 3};
  cout << b[0] << " " << b[1] << " " << b[2] << endl;

  // 结构体
  Student s{"apple", 21, {2000, 2, 18}};
  cout << s.m_name << ' ' << s.m_age << ' ' << s.m_bday.m_year << '-' << s.m_bday.m_month << '-'
       << s.m_bday.m_day << endl;

  // 自定义类
  Human h{21, "apple"}; // 调用h.Human()构造
  cout << "姓名:" << h.m_name << ", 年龄:" << h.m_age << endl;

  // 自定义类的指针
  Human *ptr_h{new Human{22, "pear"}};
  cout << ptr_h->m_name << " " << ptr_h->m_age << endl;
  delete ptr_h;
  ptr_h = NULL; // 设置为空指针

  // 指针数组
  Human *ptr_h_s{new Human[3]{Human{1, "aa"}, Human{2, "bb"}, Human{3, "cc"}}};
  cout << ptr_h_s[0].m_name << endl;
  delete[] ptr_h_s;
  ptr_h_s = NULL;

  return 0;
}