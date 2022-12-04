/**
 * ���� << >> �������������
 * cout Ϊ ���������
 *  <<   Ҫ��: operator<<(ostream,<T>) 
 *  1,�������:�ǳ���ֵ�����������
 *  2,�Ҳ�����:��ֵ����ֵ
 *  3,return: �����������
 * 
 * >> Ҫ��  operator>>( istream, a )
 *  Human�಻��Ϊconst Ҫ����
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
  // ostream�Ǳ�׼ģ������,ֻ�ܷ���ȫ������

private:
  int m_age;
  string m_name;
  friend ostream &operator<<(ostream &os, const Human &that);
  friend istream &operator>>(istream &is, Human &that);
};

// ostream &operator<<(ostream &os, int) {} ʵ�ַ�ʽ��������
ostream &operator<<(ostream &os, const Human &that)
{
  os << "name:" << that.m_name << " age:" << that.m_age;
  return os;
}
istream& operator>>( istream& is, Human& that ) {
    is >> that.m_name>>that.m_age;
    return is;
}
int main(void)
{
  Human a(22, "apple"), b(20, "����"); // �ǳ���ֵ
  cout << a << endl;
  cout << Human(23, "apple") << endl
       << endl
       << endl; // ���ص�����ֵ�������п��Խ��д���
  cin>>a;
  cout<<a<<endl;
  return 0;
}
