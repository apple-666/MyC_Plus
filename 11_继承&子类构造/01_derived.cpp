/**
 * ���ּ̳з�ʽ:  ԭʼ���-> ���±��
 *  :public      ���ֲ���
 *  :protected   pub->protect ��������    ������ģ����� �ڲ����ܵ���,����ͨ��������ã�
 *  :private     ȫ��private
 * �̳���������ص�:
(1) ������� �ڲ����� �����Ӷ���
(2) �����ڲ� ���Է��� ����� ��˽��(����/����)��Ա(����/����)
�����fun �ڶ����  

Ȩ�ޱ�Ƿ�:
�������ڲ����ʸ������,����ԭʼ���
�������ⲿ���ʸ������,�������±�� (�ö������ʱ)
*/
#include <iostream>
using namespace std;

class Base
{
public:
  int m_a;
  void foo() { cout << "Base::foo" << endl; }

protected:
  int m_b;
  void bar() { cout << "Base::bar" << endl; }

private:
  int m_c;
  void hum() { cout << "Base::hum" << endl; }
};

class Son :public Base
{
public:
  void fun()
  {

    // ������Է��ʸ���� ����,������Ա
    cout << m_a << endl;
    // Base::foo();
    cout << m_b << endl;
    bar();
    // cout<<m_c<<endl; // ����˽�г�Աû������
    // hum();
  }
  // void foo(){
  //   cout<<"�����foo"<<endl;
  // }

private:
  int m_d;
  // void bar(){
  //   cout<<"�����bar"<<endl;
  // }
};

int main()
{
  Base b;
  cout<<"Base��Ĵ�С:"<<sizeof(b)<<endl;
  Son a;
  cout<<"����Ĵ�С(�����˸����):"<<sizeof(a)<<endl;
  a.foo();
  a.Base::foo(); // ֻ��public�̳п��� ���ⲿ����
  return 0;
}
