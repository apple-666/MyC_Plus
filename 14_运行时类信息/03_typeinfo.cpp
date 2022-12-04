/*
��ȡ��������
typeid������ 
  1,����ʱ��ȡ����������Ϣ
  2,�޷���ȡ ������� ��������Ϣ
typeid��ȡ������:
  �����:
    ����ָ��ָ��Ķ�������
  �������:
    ָ�뱾�������
*/
#include <iostream>
#include <typeinfo>
using namespace std;

class A
{ // ����������A����Ϣ,������һ���麯����  "A"...|A::foo�ĵ�ַ
public:
  virtual void foo() {}
};
class B : public A
{ // ����������B����Ϣ,������һ���麯����  "B"...|A::foo�ĵ�ַ
};

int main()
{

  B b; // |���ָ��| --> ����������B����Ϣ�������麯����
  A *pa = &b;
  A &ra = b;


  cout << typeid(*pa).name() << endl; // pa-->b������ռ�ڴ�ռ�-->���ָ��-->����������B����Ϣ�������麯����-->"B"
  cout << typeid(ra).name() << endl;  //  ra-->b������ռ�ڴ�ռ�-->���ָ��-->����������B����Ϣ�������麯����-->"B"

  int a;
  const type_info &inf = typeid(a);
  // 1. ��ȡ����m��������Ϣ
  // 2. ����һ��type_info��Ķ���
  // 3. �� ��ȡ��m��������Ϣ ���浽 type_info������ ����˽�г�Ա������
  // 4. ������� type_info������ ������
  cout << "����" << inf.name() << endl;
  cout << typeid(a).name() << endl;

  int bb;
  double d;
  float f;
  cout << (typeid(a) == typeid(bb)) << endl; // typeid(m).operator==( typeid(cm) )
  cout << (typeid(bb) == typeid(d)) << endl; // typeid(m).operator==( typeid(cm) )
}