/***
 * ����ת�����캯��
 * explicit: ����ת������,��������ؼ��ʾͱ���ǿ��ת��static_cast
 * frient: ��Ԫ����, ��Ԫ���Է��ʱ���˽������
 * è -> ת�� -> ��
 */
#include <iostream> 
using namespace std;

class Cat
{
public:
  // ����ת������
  explicit Cat(const char *name) : m_name(name)
  {
    cout << "Cat�������ת�����캯��������" << endl;
  }
  void talk()
  {
        cout << m_name << ": ����~~~" << endl;

  }

private:
  string m_name;
  friend class Dog; // ��Ԫ����: ��Dog�ܷ���cat��private����
};

class Dog
{
public:
  Dog(const char *name) : m_name(name)
  {
  }
  // ����ת�����캯��
  explicit Dog(const Cat &that) : m_name(that.m_name)
  {
    cout << "Dog�������ת�����캯��������" << endl;
  }

  void talk()
  {
        cout << m_name << ": ����~~~" << endl;

  }

private:
  string m_name;
};

#include <iostream>
using namespace std;
int main(void)
{ 
  Cat qw("С��");
  qw.talk();

  // Dog qw1(qw); // ok
  // qw1.talk();
  //  Dog bigyellow = qw; //  ok ���� ����Dog�����, ���� ����Dog�����.Dog( smallwhite )
  //  bigyellow.talk();                             // Dog bigyellow = ����Dog�����;
  
  
   // ok ����explicit,��һ��Ҫǿ��ת��
   Dog qw2 = static_cast<Dog>(qw);
  qw2.talk();

  // static_cast<Dog>(qw).talk();

  return 0;
}
