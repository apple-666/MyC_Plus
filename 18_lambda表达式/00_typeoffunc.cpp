/*
�����ڲ������б��ʽ,�Զ�����, �����к���
ȫ�ֺ����ͳ�Ա����:�ڲ��ı���˳��
  1,����class A   2,���뺯��
*/
#include <iostream>
#include <typeinfo>
using namespace std;

void foo()
{
  int a = 10;            // ok,�����ڲ����Զ������(�ֲ�����)
  cout << 2 * a << endl; // ok,�����ڲ������б��ʽ Ҳ������ ���

  // void bar( ) { // error, �����ڲ� ���ܶ��� ����
  //     cout << "bar() is invoked" << endl;
  // }
}

// ��Ա�����ڲ������͵ı���˳�� 1,����class A   2,���뺯��
int a;
void foo2(int b)
{
  int c;
  class A
  {
  public:
    void bar(int d)
    {
      a = 1;
      // b = 2;// ������˳�� �Ҳ���b
      // c = 2;//ͬ��
      d = 1;
    }
  };
}

// �ڲ�����,����class
int a2 = 1;
class A
{
public:
  void foo(int b)
  {
    // e = 1; // this ��A��
    class B
    {
      public:
        void bar(int c){
          a2 = 10;
          // b = 2;//error
          c = 2; 
          d = 1; // ��̬�ı��������ȿ�ʼ����
          
          // this->e = 1; // ��this->e Ҳ���У�this��B��
          // A::e = 1; // ���У�Ҫ�ö������
          // e = 1; // error Ҫָ����Ӧ�Ķ�����ܷ�����ͨ��Ա����
        }
    };
  }
private:
  static int d; // ��̬��Ա���������� �����ڶ���
  int e;        // ��ͨ��Ա���������������ڶ���
};

int
main(void)
{

  return 0;
}
