/*
����ģ��������ʳ�Ա����ģ��

����ԭ�򣺵�һ�α���,����ú���,�޷�ʶ��<>,�޷�ʶ��Ϊ����ģ��

��ŷ���: ���ͺ�� .template  ˵����template ����ģ��
*/

#include<iostream>
using namespace std;

class A{
  public:
    template<class T> void foo(){
      cout<<"A::foo<T>()"<<endl;
    }
};

template<class D>
void print(){
  D d; // D��ģ����� 
  // d.foo<int>(); // ���� ����ģ��������ʳ�Ա����ģ��
  d.template foo<int>();
}

int main( void ) {
  print<A>();
  return 0;
}