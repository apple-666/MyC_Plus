#ifndef __HUMAN_H
#define __HUMAN_H
// Ĭ�ϵ�ͷ�ļ�д��, Ϊ�˷�ֹ�ظ�����
// ͷ�ļ�д�������

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