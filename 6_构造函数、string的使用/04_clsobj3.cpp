// ���������ķ���
#include <iostream>
#include <cstring>
using namespace std;
class Human
{
public:
  Human(/* Human* this */ int age = 0, const char *name = "����"); // ����
  void getinfo(/* Human* this */);                                 // ����
private:
  int m_age;        // ����
  char m_name[256]; // ����
};

Human::Human(/* Human* this */ int age, const char *name)
{ // ����
  // ��this��ָ����ڴ�ռ��� ����m_age(��m_age�����ڴ�ռ�)��ֵΪ�����
  // ��this��ָ����ڴ�ռ��� ����m_name(��m_name�����ڴ�ռ�)��ֵΪ�����
  cout << "Human��Ĺ��캯��������" << endl;
  this->m_age = age;
  strcpy(this->m_name, name);
}
void Human::getinfo()
{ // ����
  cout << "����: " << m_name << ", ����: " << m_age << endl;
}

int main()
{
  Human(11, "pengpeng").getinfo();

  // ��ѡ
  Human h(22, "zhangfa ");
  h.getinfo();

  Human h2;
  h2.getinfo();

  Human h3[3];
  for (int i = 0; i < 3; i++)
    h3[i].getinfo();

  // ������ѡ
  Human h4[3] = {Human(1, "peng"), Human(2, "peng2"), Human(3, "peng3")};
  for (int i = 0; i < 3; i++)
    h4[i].getinfo();

  Human h5[3] = {Human(1, "peng"), Human(2, "peng2"), Human(3, "peng3")};
  for (int i = 0; i < sizeof(h5) / sizeof(h5[0]); i++)
    h5[i].getinfo();

  // new �������� ����ָ�����
  Human *ph = new Human;
  (*ph).getinfo();
  delete ph;
  cout << ph << endl;
  ph = NULL; // ����Ϊ��
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

  Human *ph5 = new Human[3]{Human(22, "�ŷ�"), Human(20, "����"), Human(25, "����")};
  for (int i = 0; i < 3; i++)
    ph5[i].getinfo();
  delete[] ph5;
  ph5 = NULL;

  return 0;
}
