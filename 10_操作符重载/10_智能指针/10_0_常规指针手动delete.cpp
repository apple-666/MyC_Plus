#include<iostream>
#include<fcntl.h>
using namespace std;

class A{
public:
  A() : m_f(open("./file.txt",O_CREAT|O_RDWR,0644)) { //0AAA �ļ�Ȩ��
    cout<<"��һ���ļ�"<<endl;
  }
  ~A() {
    close(m_f);
    cout<<"�ر��ļ�"<<endl;
  }
  void foo() {
    write(m_f,"apple come",10);
    cout<<"���ļ�д������"<<endl;
  }
private:
  int m_f;
};

int main() {
  /**
   * ����ָ���뿪����������(������main������),paָ��ᱻ�ͷ�,
   * ����ָ��Ķ���(��̬�ڴ�)�����ͷ�,������ڴ�й¶,
   * ����Ҫ�ֶ�delete(�������������)
  */
  A* pa = new A;
  (*pa).foo();
  pa->foo(); 
  delete pa; // ������������� pa->~A() �� ջ������{}��������,�Ѷ���(��̬�ڴ�)Ҫ��delete
  return 0;
}