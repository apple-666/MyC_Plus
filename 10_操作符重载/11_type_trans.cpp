/**
 * �Զ��� ����ת��
 * ��������ת -> class���� ������ת�����캯��
 * int -> integer
 * integer -> int
*/

#include<iostream>
using namespace std;

class Integer {
public:
  Integer(int i):m_i(i){ // int -> integer ����ת�����캯��
  }
  operator int( /*const Integer* this */) const { // ����ת������������ 
      return this->m_i;
  }

private:
  int m_i;
  friend ostream& operator<<(ostream& os,const Integer& that);
};

ostream& operator<<(ostream& os,const Integer& that){
  os<<"Integer:"<<that.m_i<<endl;
  return os;
}


int main() {
  int a = 1;
  Integer b = a;//int->Integer ת��������Integer����.Integer(int n) ����ת�����캯��
                // a.operator Integer() a��int��,����϶�û���������
  // Integer c = Integer(a) // ����һ��һ��
  cout<<b<<endl;

  int c = b; //Integer->int ת��������int����.int(Integer B) ����û���������
             // Ӧ���� b.operator int() ����ת�����캯��
  cout<<c<<endl;
  return 0;
}