/**
 * ����ģʽ - ����ʽ����
 */
#include <iostream>
using namespace std;
// ���һ����,��֤�û���ʹ�������ʱ,ֻ�ܳ���һ������

class Singleton
{
public:
  static Singleton &getInstance()
  {
    if (s_instance == nullptr)
    {
      // no.3 ����һ������, ����ָ��ָ�����
      s_instance = new Singleton();
      cout << "new ʵ��" << endl;
    }
    ++s_counter;
    return *s_instance; // ����ָ��ָ��Ķ���
  }
  void releaseInstance()
  {
    if (--s_counter == 0) // no.4 ���߳��·�ֹ��ǰdelete
    {
      delete s_instance;
      s_instance = nullptr; // delete��ָ���ǰ�ȫ��
      cout << "���ٶ���" << endl;
    }else {
      cout<<"�������ڱ������߳�ʹ����"<< endl;
    }
  }

private:
  Singleton(){};
  Singleton(const Singleton &that){};

  // no.1 ��: ָ������ָ��
  static Singleton *s_instance;
  static int s_counter;
};

// no.2 ָ���͵�static����
Singleton *Singleton::s_instance = nullptr;
int Singleton::s_counter = 0;

int main()
{
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  cout << "&s1:" << &s1 << ", &s2:" << &s2 << endl;

  s1.releaseInstance();
  s2.releaseInstance();


  Singleton &s3 = Singleton::getInstance();

  return 0;
}
