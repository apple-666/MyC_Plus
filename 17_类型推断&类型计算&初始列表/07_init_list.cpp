/*
�б��ʼ��:׷�����д����һ���� (��Ϊ��ʼ����:= () {} )
���� ����{��ʼֵ}
{����}      ��ʼ��
{�������}  �����ʼ��
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
  // �������ͱ���
  int a{123};
  cout << a << endl;

  // ����
  int b[]{1, 2, 3};
  cout << b[0] << " " << b[1] << " " << b[2] << endl;

  // �ṹ��
  Student s{"apple", 21, {2000, 2, 18}};
  cout << s.m_name << ' ' << s.m_age << ' ' << s.m_bday.m_year << '-' << s.m_bday.m_month << '-'
       << s.m_bday.m_day << endl;

  // �Զ�����
  Human h{21, "apple"}; // ����h.Human()����
  cout << "����:" << h.m_name << ", ����:" << h.m_age << endl;

  // �Զ������ָ��
  Human *ptr_h{new Human{22, "pear"}};
  cout << ptr_h->m_name << " " << ptr_h->m_age << endl;
  delete ptr_h;
  ptr_h = NULL; // ����Ϊ��ָ��

  // ָ������
  Human *ptr_h_s{new Human[3]{Human{1, "aa"}, Human{2, "bb"}, Human{3, "cc"}}};
  cout << ptr_h_s[0].m_name << endl;
  delete[] ptr_h_s;
  ptr_h_s = NULL;

  return 0;
}