// �ڳ�ʼ������: ���������const����,һ��Ҫ�Ž�ȥ,������ͨ�������Բ��Ž�ȥ
#include <iostream>
#include <cstring>
using namespace std;
class Human
{
public:
  void getinfo(/* Human* this */)
  {
    cout << "����: " << this->m_name << ", ����: " << this->m_age << ", �ɼ�:" << this->m_score
         << ", ���ֵĳ���: " << m_len << endl;
  }
  Human(int age = 0, const char *name = "����", float score = 0.0)
    : m_age(age), m_score(score),m_name(name),m_len(strlen(name))
  {
    cout << "Human��ȱʡ���캯��������" << endl;
  }
  Human(const Human &that)
    : m_age(that.m_age), m_score(that.m_score), m_name(that.m_name),m_len(that.m_len)
  { // that.arg  ���ʶ�����.  ����ָ����->
    cout << "Human��Ŀ������캯��������" << endl;
  }

private:
  int m_len; // ���������ַ����ĳ���
  int m_age;
  string m_name;       // ���������ַ���
  const float m_score; // �����ͳ�Ա����
  //  int m_len;
};

int main(void)
{

  // Human h2(22, "�ŷ�", 88.5); // ����h2,����h2.Human(22,"�ŷ�",88.5)
  // h2.getinfo();

  // Human h3(h2); //= h2; ����h3,����h3.Human(h2) --> h3ά�������� �� h2ά�������� ������ͬ
  // h3.getinfo();

  return 0;
}
