/*
try ��׽˳���ǰ����ϵ��¶��������ŵ�
catch 1
catch 2
�ܽ�: catch ��ƥ��ķ���ǰ��
*/

#include <iostream>
#include <cstdio>
using namespace std;

class A
{
};
class B : public A
{
};

void foo()
{
  throw B(); // �׳���Ϊ�������
}
int main(void)
{
  try
  {
    foo();
  }
  catch( B& e ) { // ����Ϊ ������������
      cout << "2. B&" << endl;
  }
  catch (A &e)
  { // ����Ϊ ������������ ����& ���Խ�����������(��Ϊ���෶Χ>���� ���Դ�������ʽת���ɻ���)
    cout << "1. A&" << endl;
  }
  // catch (B &e)
  // { // ����Ϊ ������������
  //   cout << "2. B&" << endl;
  // }
  return 0;
}
