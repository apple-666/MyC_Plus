/*
����Ĺ��캯������������
*/

#include <iostream>
using namespace std;

class Farther
{
public:
  // ���� (��Ĭ�ϵ�)
  Farther(int age = 1, const char *name = "null") : m_age(age), m_name(name){};

  // �������� (��Ĭ�ϵ�)
  Farther(const Farther &that) : m_age(that.m_age), m_name(that.m_name)
  {
    cout << "~~~�������캯��" << endl;
  };

  // ������ֵ���� (ʹ��& ����һ�ο�������)
  Farther &operator=(const Farther &that)
  {
    this->m_age = that.m_age + 1;
    this->m_name = that.m_name;
    cout << "~~~������ֵ����" << endl;
    return *this;
  }

  // ����
  ~Farther()
  {
    cout << "~~~��������" << endl;
  }

  void getInfo()
  {
    cout << "age:" << m_age << " name:" << m_name;
  }

private:
  int m_age;
  string m_name;
};

class Son : public Farther
{
public:
  void getInfo()
  {
    Farther::getInfo();
    cout << ", �ɼ�: " << m_score << ", ����: " << m_remark << endl;
  }
  // ����
  Son(int age = 0, const char *name = "null", float score = 1.0, const char *remark="null")
      : Farther(age, name), m_score(score), m_remark(remark)
  {
    cout << "son ���캯��" << endl;
  }

  // ��������
  Son(const Son& that):Farther(that),m_score(that.m_score),m_remark(that.m_remark){
    cout<<"son �������캯��"<<endl;
  }

  // ������ֵ(Ĭ�ϵĶ�ʵ����)
  Son& operator=(const Son& that){
    Farther& lv = *this;
    const Farther& rv = that;
    lv = rv; // ���ø���� lv.operator=(rv)
    this->m_score = that.m_score;
    this->m_remark = that.m_remark;
    cout<<"����Ŀ�����ֵ����"<<endl;
    return *this;
  }

  // ����
  ~Son(){
    cout<<"Son ��������"<<endl;
  }

private:
  float m_score;
  string m_remark;
};

int main()
{

  // Farther far(22, "apple");
  // far.getInfo();

  // Farther far2(far);
  // far2.getInfo();

  // Farther far3;
  // far3 = far; // ʹ�ÿ�����ֵ: far3.operator= ()  �ٰ����������� = ����
  // far3.getInfo();
  // Farther far4 = far; // ʹ�ÿ�������


  Son son1(33,"farther",100.0,"����");
  son1.getInfo();

  Son son2(son1); // �������� (���࿽������ + ����Ŀ�������)
  son2.getInfo(); // ��������� + ���������

  Son s3;
  s3 = son1;// ������ֵ���� son2.operator=(son1)
  s3.getInfo(); 
  return 0;
}
