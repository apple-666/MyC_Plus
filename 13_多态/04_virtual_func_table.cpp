/*
���ܶ�̬ - �麯����
ԭ��
  1,ʹ��virtual,������ָ��,ָ��ָ���Ӧ����麯����
  2,��̬�󶨺���: ָ��paָ��b���� + pa.func()
    1. ����pa�ҵ�b������ռ�ڴ�ռ�
    2. ��b������ռ�ڴ�ռ��� ��ȡ ���ָ��
    3. �������ָ�� �ҵ� ����������B����Ϣ�������麯����
    4. ���麯������ ��ȡ �麯���� ��ڵ�ַ
    5. ���� ��������ڵ�ַ ���� ����
������:
  ��̬��,û��ʹ������,���ܻ�ȱʧ
*/

#include <iostream>
using namespace std;

// A�麯����洢: A::foo A::bar
class A
{
public:
  virtual void foo() { cout << "A::foo" << endl; }
  virtual void bar() { cout << "A::bar" << endl; }
};

// B�麯����洢: B::foo A::bar
class B : public A
{
public:
  void foo() { cout << "B::foo" << endl; }
};

int main(void)
{
  /*
    ��Ϊ��virtual���Ի�� ���ָ��ָ���Ӧ����麯����
  */
  A a;
  cout << "û�г�Ա��������A���ڴ��С:" << sizeof(a) << endl;
  B b;
  cout << "û�г�Ա��������B���ڴ��С:" << sizeof(b) << endl;

  /*
  �õ����ָ��(����Ϊָ��ָ������ָ��,�����Ƕ���ָ��)
  ����  &a ��aȡ��ַ Ϊ����ָ����
        void(***)() תΪ����voidָ��
        *(void(***)()) ������ָ������ñ�Ϊ����ָ��
  */
  void (**v_ptr)() = *((void (***)())(&a));
  v_ptr[0](); // =a.foo()
  v_ptr[1](); // =a.bar()

  void (**v_ptr2)() = *((void (***)())(&b));
  v_ptr2[0](); // =b.foo()
  return 0;
}
