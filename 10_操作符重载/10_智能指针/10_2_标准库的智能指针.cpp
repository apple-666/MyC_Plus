/**
 * ����ָ��:
 * ��׼�������ָ��(ʹ������ģ��) + #include < memory>
 * ʹ�ú�����auto_ptr;
 * auto_ptr<class> apple_tpr(new class);
 */

#include <iostream>
#include <fcntl.h>
#include <memory>

using namespace std;

class A
{
public:
  A() : m_f(open("./file.txt", O_CREAT | O_RDWR, 0644))
  { // 0AAA �ļ�Ȩ��
    cout << "��һ���ļ�" << endl;
  }
  ~A()
  {
    close(m_f);
    cout << "�ر��ļ�" << endl;
  }
  void foo()
  {
    write(m_f, "apple come", 10);
    cout << "���ļ�д������" << endl;
  }

private:
  int m_f;
};

int main()
{
  auto_ptr<A> pau(new A);
  (*pau).foo();
  pau->foo();

  auto_ptr<A> pbu = pau; // ����pbu,����pbu.Auto_ptr( pau )
  (*pbu).foo();
  pbu->foo();
  //  (*pau).foo( ); // pau�Ѿ�ʧЧ
  return 0;
}