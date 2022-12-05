/*
&& ��Ӧ�� �� ʵ��ת�� ��������

���µ�ԭ�����ÿ�������Ϳ�����ֵ   ->  ��������String&&  ��ת�ƿ��������ת�ƿ�����ֵ ���ܸ���
  String c = String("pera"); // c.String( String() )
  d = String("pear");

*/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
  String(const char *psz = "null") : m_psz(new char[strlen(psz) + 1])
  {
    strcpy(m_psz, psz);
  }
  ~String()
  {
    delete[] this->m_psz;
  }
  char *c_str()
  {
    return m_psz;
  }

  //��� ��Դ�ؽ�
  String(const String &that) : m_psz(new char[strlen(that.m_psz) + 1])
  {
    strcpy(m_psz, that.m_psz);
    cout << "String���������캯��������" << endl;
  }
  // ת�忽�����캯�� ��Դת��
  String(String &&that) : m_psz(that.m_psz)
  {
    // ����ǳ����������ֵ��dead �������ַ
    // ����ԭ������ֵ ����Ҫ���� ���� ��Ϊnull
    that.m_psz = NULL;
    cout << "String���ת�ƹ��캯��������" << endl;
  }

  // �����ֵ����  ��delete�����ٸ�ֵ
  String operator=(String &that)
  {
    cout << "String�������ֵ����������" << endl;
    if (this != &that)
    {
      // char *old = this->m_psz; // �ⲽ����
      delete[] m_psz;
      this->m_psz = new char[strlen(that.m_psz) + 1];
      strcpy(this->m_psz, that.m_psz);
    }
    return *this;
  }
  // ת�忽����ֵ����
  String &operator=(String &&that)
  {
    cout << "String���ת�Ƹ�ֵ����������" << endl;
    delete[] this->m_psz; // ��ֵ ��delete
    this->m_psz = that.m_psz;
    that.m_psz = nullptr; // ��ֵ null
    return *this;
  }

private:
  char *m_psz;
};

int main()
{
  String a("apple");

  // �������
  String b = a;
  //ת�ƿ������캯�� "pear"Ϊ��ֵ����ͨ����˷����� ��ת�ƿ����������
  String c = String("pera"); // c.String( String() )
  // �����ֵ
  String d;
  d = a; // d.operator=(a)
  // ת�ƿ�����ֵ����
  d = String("pear");
  return 0;
}