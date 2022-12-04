/**
 * ��Ŀ����� ++ --
 *   ǰ��++a: �ǳ���ֵ,return����,�Ǹ���ֵ
  *  ����a++: �ǳ���ֵ,���������ռ�(��ž�ֵ),�Ǹ���ֵ
 */
#include <iostream>
using namespace std;
class Human
{
public:
  Human(int age = 0, const char *name = "����") : m_age(age), m_name(name)
  {
  }
  void getinfo()
  {
    cout << "����: " << m_name << ", ����: " << m_age << endl;
  }
  Human& operator++(/* Human* this */) // ��������,�Ͳ��᷵�������ڴ�,���ض�Ӧ�����õ�
  {
    // c_str��char��
    // ����һ  �ʺ�������,return һ����ֵ
    // return Human(this->m_age + 1, this->m_name.c_str());

    // ������
    this->m_age = this->m_age + 1;
    return *this;
  }

  Human operator++(/* Human* this */ int) // û������,���������ڴ�
  {
    // c_str��char�� returnһ����ֵ(Ϊ������)
    Human old = *this; 
    this->m_age = m_age + 1;
    return old;
  }

private:
  int m_age;
  string m_name;
};
int main(void)
{
  Human a(22, "apple"), b(20, "����"); // �ǳ���ֵ
  (++a).getinfo(); // Human operator++

  (b++).getinfo();
  b.getinfo(); 
  // const int d = 1; Ϊ����ֵ
  // cout<< d++<< endl; error
  // cout<<++d<<endl; error

  // ǰ��++a: �ǳ���ֵ,return����,�Ǹ���ֵ
  // ����a++: �ǳ���ֵ,���������ռ�(��ž�ֵ),�Ǹ���ֵ
  
#if 0                                  // �Ƿ��������Ͱ����ݱ����ȥ,���������н׶ε�
      int a
#endif
  return 0;
}
