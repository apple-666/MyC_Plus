/*
ģ����ػ��﷨:
1,ȫ���ػ�
  1.1 ȫ���ػ� �������ػ�
  1.2 ��Ա�ػ� ���������ػ�
2,�ֲ��ػ�
  ��ʽ�࣬��������

*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T, class D>
class A
{
public:
  static void foo()
  {
    cout << "T D" << endl;
  }
};

// �ֲ��ػ� ��ʽһ
template <class T>
class A<T, int>
{
public:
  static void foo()
  {
    cout << "T int" << endl;
  }
};


// �ֲ��ػ� ��ʽ��
template <class T>
class A<T, T>
{
public:
  static void foo()
  {
    cout << "T T" << endl;
  }
};

int main()
{
  A<int,double>::foo();
  // A<double>::foo(); //error ������ֻ��һ�����͵� 
  A<double,int>::foo(); // ʹ���˾ֲ��ػ���
  // A<int,int>::foo(); // ��ʽ1,2������ �г�ͻ

  return 0;
}