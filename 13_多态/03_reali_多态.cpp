/*
ʵ�ֶ�̬����:
1,������virtual�ĺ���
2,���า���˻���ͬ������,�û���ָ��/���� ָ������ȥ�����麯��
*/

#include <iostream>
using namespace std;

class Base{
  public:
    Base(){
      cout<<"no1,Base::����";
      this->same1();// �ǻ�����õ�
      
    }
    ~Base(){
      cout<<"Base:����"<<endl;
    }
    void foo(/*Base* this */) { // ����ָ��ָ�������same1
      this->same1(); // ��������õ�
    }
    virtual void same1(){
      cout<<"Base::same1"<<endl;
    }
};

class Derived:public Base{
  public:
    Derived(){
      //no.1 Base(); ����.Base
      //no.2 Derived ����.Derived;
      cout<<"no2,Derived::����"<<endl;
    }
    ~Derived(){
      cout<<"Derived::����"<<endl;
    }
    void same1() {
      cout<<"Derived::same1"<<endl;
    }
};

int main(){

  // Base bse;
  // bse.foo();

  Derived der;
  // der.same1();

  der.foo();// foo(&der) ���õĻ����foo
  return 0;
}