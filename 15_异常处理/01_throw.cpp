/*
throw -1
try{
}catch(){
}

*/

#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
  A() { cout << "A() is invoked" << endl; }
  ~A() { cout << "~A() is invoked" << endl; }
};

void foo()
{
  cout << "foo����ǰ�ļ����д��� ";
  A a;
  FILE *pFile = fopen("./cfg", "r");
  if (!pFile)
    throw "foo������";
  cout << "foo�����ļ����д���" << endl;
} 


void bar()
{
  cout << "bar����ǰ�ļ����д��� ";
  A b;
  foo();
  cout << "bar�����ļ����д���" << endl;
} 


void hum()
{
  cout << "hum����ǰ�ļ����д��� ";
  A c;
  bar();
  cout << "hum�����ļ����д���" << endl;
}


int main(void)
{
  cout << "main����ǰ�ļ����д��� ";
  A d;
  try
  {
    hum();
  }
  catch (const char* e) 
  {
    cout << "main�в����쳣��Ϣ: " << e << endl;
  }
  cout << "main�����ļ����д���" << endl;
  return 0;
} // d.~A()  �ͷ�d������ռ�ڴ�ռ�
