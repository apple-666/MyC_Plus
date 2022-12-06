/*
Ƕ������: T::B b �������ж���T��ľ�̬��Ա,������ȴ����������,����ǰ��һ��,�ᱨ��
T�������û���������ͣ���������������.

��ŷ���: ǰ��� class���� typename ������ ����
*/

#include<iostream>
using namespace std;

class A{

  public:
    class B{
      public:
        void foo() {
          cout<<"A::B.foo()"<<endl;
        }
    };
};

template<class T>
void print(){
  // T::B b; // ����Ƕ������
  class T::B b; // ����class �ܱ����Ǵ���������
  b.foo();
}

int main( void ) {
  print<A>(); // class A::B b; b.foo();
  // print<int>(); //error
  return 0;
}