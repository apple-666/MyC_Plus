/**
 * ����ģʽ-��ģʽ : �������þʹ���ʵ��
 * ���ʹ�������,ֻ����ͬһ��ʵ��
 */

#include <iostream>
using namespace std;

class Singleton
{
public:
  static Singleton& getInstance() 
  //no.4  ����static,�Ϳ���������ȥ���÷���
  //no.5  &: �ñ�������,�����Ͳ��᷵����������,�õ���ͬһ��ʵ��
  {
    return s_instance;
  }

private:
  //no.1 �ù���˽��,��ֹ�������
  Singleton() {} 

  //no.6 ��ֹ��¡,�ÿ������캯��Ҳ˽�л�
  Singleton(const Singleton &that)
  {
  }
  
  //no.2  ���Ǳ������,��ȫ��������Ķ���,��Ҫ��ȫ���������мӶ���
  static Singleton s_instance; 
};

//no.3 ��ȫ�ֶ��� ���� ����::instance
Singleton Singleton::s_instance;

int main()
{
  // Ϊͬһ��ʵ��
  // no.7 ֻ����&��������,��Ȼ�ᴥ����¡(����˽�������Իᱨ��)
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  Singleton &s3 = Singleton::getInstance();
  cout << "&s1:" << &s1 << ", &s2:" << &s2 << ", &s3:" << &s3 << endl;
  return 0;
}