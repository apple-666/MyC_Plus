// ����Ҫ�Զ������������
// ��̬��Դ: �ڳ��������ڼ���ڵ���Դ

#include <iostream>
using namespace std;

class A {
public:
  A(int i=0):m_i(i),m_p(new int) {
        //��int* m_p=new int;������m_i,��ֵΪָ��һ����ڴ�(��̬��Դ)
  }
  ~A(){
    delete m_p; 
    cout<<"��������ɾ����̬��Դ"<<endl;
  }// �ͷ�m_i / m_p������ռ�ڴ�ռ�

private:
  int m_i;
  int* m_p;
};

int main( void ) {
  A a;
  return 0;

}