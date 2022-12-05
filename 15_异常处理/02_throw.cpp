/*
�쳣�����еĿ�������:
���һ: 2��
  A a; throw a; ����һ��a����׼����
  try catch(A e)�ӱ�׼�⿽��һ��a��e��
�����: 0�� (ʹ�����ü���)
  throw A(); A�����һ���Ķ��� (���������� ���Ա�gcc++�Ż�)
  thr catch(A& e) 

*/

#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
  A() {}
  A(const A &that) { cout << "A��Ŀ������캯��������" << endl; }
  ~A() {}
  const char *getInfo()
  {
    string msg = "I am A";
    return msg.c_str();
  }
};

void foo()
{
  //  A a;
  // throw a; // ��¡

  throw A(); // g++�������Ż�
}

int main(void)
{
  try
  {
    foo();
  }
  catch (A& e)
  {
    cout << "�����쳣:" << e.getInfo() << endl;
    // ...
  }
  return 0;
}
