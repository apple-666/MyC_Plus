/**
 * ����ָ��:
 * �����Ǹ������,���뿪������ʱ,�������������ͷŶ�̬�ڴ�
 * 
 * �������ָ��ʹ��: ���ؽ�����* �� ��ӷ��ʳ�Ա������->
 *    (*ptr).foo() (�ѵ�ַ)���÷��� �� .
 *    ptr->foo()   ָ����÷�ʽ�� ->
*/

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

class Auto_ptr {
public:
  Auto_ptr(A* a): pa(a) {
  }
  ~Auto_ptr() {
    delete pa;
    pa = NULL;
  }
  A& operator*(){
    return *pa;
  }
  A* operator->(){
    return pa;
  }
  Auto_ptr(Auto_ptr& that):pa(that.pa){
     // ����ָ����ֿ���ʱ,
     // ֻ����һ��ָ����Ч(ָ�����Ķѵ�ַ,������double free)
    that.pa = NULL;
  }
private:
  A* pa; // ָ��new�Ķ��ڴ��ַ
};

int main() {
  // Auto_ptr pau = new A; // pau ָ��new A�Ķ��ڴ�
  Auto_ptr pau(new A);
  (*pau).foo(); // pau.operator*().foo()
  pau->foo(); // pau.operator->().foo() ��д������operator

  Auto_ptr pau2 = pau;
  // pau->foo(); // 
  return 0;
}