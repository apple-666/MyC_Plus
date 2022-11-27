#ifndef __HUMAN_H
#define __HUMAN_H
// 默认的头文件写法, 为了防止重复编译
// 头文件写申明语句

class Human
{
public:
  Human(int age = 0, const char *name = "NULL");
  void getinfo();

private:
  int m_age;
  char m_name[100];
};

#endif