/***
 * ��������Ͷ���ֿ�д
 */
#include <cstring>
#include <iostream>

using namespace std;

// ����
class Human
{
public:
  Human(int age = 0, const char *name = "xx"); // �������п���ָ��Ĭ��ֵ
  void getinfo();

private:
  int m_age;
  char m_name[100];
};

// ����
Human::Human(int age, const char *name ) // �ڶ����в���ָ��Ĭ��ֵ
{
  cout << "���챻����" << endl;
  this->m_age = age;
  strcpy(this->m_name, name);
}
void Human::getinfo()
{
  cout << "����: " << m_name << ", ����: " << m_age << endl;
}

int main(void)
{

  Human apple(22, "apple");
  apple.getinfo();
}