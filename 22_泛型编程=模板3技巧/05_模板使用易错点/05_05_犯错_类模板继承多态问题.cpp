/*
��ģ��̳к�Ķ�̬����
  ��ģ�����ͨ�����������麯�� ��virtual����
  ��ģ��ĳ�Աģ�庯���������麯�� �޷���virtual
    (��Ϊ���麯������ʵ������ģ��ʱ�Ͳ��������Ǻ���ģ���ʵ�������ڱ���֮������˲Ż����)
*/

#include <iostream>
using namespace std;


template<class T>
class Base{
  public:
    virtual void foo(){
      cout<<"Base:::::"<<endl;
    }
};

template<class T,class D> class Derived:public Base<T>{
  public:
    void foo(){
      cout<<"Derived::foo:"<<endl;
    }
};


int main()
{
  Derived<int,double> d;
  Base<int>* b = &d;
  b->foo();

  return 0;
}