/*
�麯����Ӧ��
  ��̬����ת��: ����ָ��/���� ת����� ������ʱ��ȡ�� ��Ϣ����ת����
  ָ��Ķ������ͺ�Ҫת�ɵĶ���������ͬ�� �ɹ�,����ʧ��

*/
#include <iostream>
using namespace std;
class A
{ // ��Ϊ���麯��,���Ա���������A����Ϣ,������һ���麯����   "A"...|A::foo�ĵ�ַ
  virtual void foo() {} // Ҫ���麯�����ܶ�̬ת
};
class B : public A
{ // ����������B����Ϣ,������һ���麯����   "B"...|A::foo�ĵ�ַ
};
class C : public B
{ // ����������C����Ϣ,������һ���麯����   "C"...|A::foo�ĵ�ַ
};
class D
{ // ����������D����Ϣ,�������麯����(��Ϊû���麯��)
};
int main(void)
{
  B b;
  A *pa = &b; //��->С,��ʽת��
  B *pb;
  C *pc;
  D *pd;
  cout << "-----dynamic_cast������ȫ�����Ͻ���-----" << endl;
  pb = dynamic_cast<B *>(pa); // paָ�����B��,���Կ���ת��Bָ��
  //�����̣� paָ��b���ڴ�ռ� �����ָ�� ���麯���� ����������B�����Ϣ Ҫת��Ҳ��B���
  cout << "A* pa ---> B* pb: " << pb << endl; // �ɹ�
  pc = dynamic_cast<C *>(pa);
  cout << "A* pa ---> C* pc: " << pc << endl; //��ָ�� ʧ��
  pd = dynamic_cast<D *>(pa); // ��̬ת����
  cout << "A* pa ---> D* pd: " << pd << endl; //��ָ�� ʧ��

  cout << "-----static_cast(���Ͻ�)-----" << endl;
  pb = static_cast<B *>(pa);
  // ������: ��������� A*-->B* �ķ��� B*-->A* ������ʽ,�ǾͿ��Թ�
  cout << "A* pa ---> B* pb: " << pb << endl;
  pc = static_cast<C *>(pa);
  cout << "A* pa ---> C* pc: " << pc << endl; // ����,û�в������
//  pd = static_cast<D*>(pa); // D ���������� û����staticת��
//  cout << "A* pa ---> D* pd: " << pd << endl;
  return 0;
}
