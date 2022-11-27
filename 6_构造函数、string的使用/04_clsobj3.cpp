// 定义类对象的方法
#include <iostream>
#include <cstring>
using namespace std;
class Human
{
public:
  Human(/* Human* this */ int age = 0, const char *name = "无名"); // 声明
  void getinfo(/* Human* this */);                                 // 声明
private:
  int m_age;        // 声明
  char m_name[256]; // 声明
};

Human::Human(/* Human* this */ int age, const char *name)
{ // 定义
  // 在this所指向的内存空间中 定义m_age(给m_age分配内存空间)初值为随机数
  // 在this所指向的内存空间中 定义m_name(给m_name分配内存空间)初值为随机数
  cout << "Human类的构造函数被调用" << endl;
  this->m_age = age;
  strcpy(this->m_name, name);
}
void Human::getinfo()
{ // 定义
  cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
}

int main()
{
  Human(11, "pengpeng").getinfo();

  // 首选
  Human h(22, "zhangfa ");
  h.getinfo();

  Human h2;
  h2.getinfo();

  Human h3[3];
  for (int i = 0; i < 3; i++)
    h3[i].getinfo();

  // 数组首选
  Human h4[3] = {Human(1, "peng"), Human(2, "peng2"), Human(3, "peng3")};
  for (int i = 0; i < 3; i++)
    h4[i].getinfo();

  Human h5[3] = {Human(1, "peng"), Human(2, "peng2"), Human(3, "peng3")};
  for (int i = 0; i < sizeof(h5) / sizeof(h5[0]); i++)
    h5[i].getinfo();

  // new 创建对象 返回指针对象
  Human *ph = new Human;
  (*ph).getinfo();
  delete ph;
  cout << ph << endl;
  ph = NULL; // 设置为空
  cout << ph << endl;

  Human *ph2 = new Human();
  (*ph2).getinfo();
  delete ph2;
  ph2 = NULL;

  Human *ph3 = new Human(22, "i am pengpeng");
  (*ph3).getinfo();
  delete ph3;
  ph3 = NULL;

  Human *ph4 = new Human[3];
  for (int i = 0; i < 3; i++)
    ph4[i].getinfo();
  delete[] ph4;
  ph4 = NULL;

  Human *ph5 = new Human[3]{Human(22, "张飞"), Human(20, "赵云"), Human(25, "关羽")};
  for (int i = 0; i < 3; i++)
    ph5[i].getinfo();
  delete[] ph5;
  ph5 = NULL;

  return 0;
}
