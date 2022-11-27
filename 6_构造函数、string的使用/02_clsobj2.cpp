/***
 * 类的申明和定义分开写
 */
#include <cstring>
#include <iostream>

using namespace std;

// 申明
class Human
{
public:
  Human(int age = 0, const char *name = "xx"); // 在申明中可以指定默认值
  void getinfo();

private:
  int m_age;
  char m_name[100];
};

// 定义
Human::Human(int age, const char *name ) // 在定义中不能指定默认值
{
  cout << "构造被调用" << endl;
  this->m_age = age;
  strcpy(this->m_name, name);
}
void Human::getinfo()
{
  cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
}

int main(void)
{

  Human apple(22, "apple");
  apple.getinfo();
}