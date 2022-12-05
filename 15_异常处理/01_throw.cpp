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
  cout << "foo出错前的几百行代码 ";
  A a;
  FILE *pFile = fopen("./cfg", "r");
  if (!pFile)
    throw "foo出错了";
  cout << "foo出错后的几百行代码" << endl;
} 


void bar()
{
  cout << "bar出错前的几百行代码 ";
  A b;
  foo();
  cout << "bar出错后的几百行代码" << endl;
} 


void hum()
{
  cout << "hum出错前的几百行代码 ";
  A c;
  bar();
  cout << "hum出错后的几百行代码" << endl;
}


int main(void)
{
  cout << "main出错前的几百行代码 ";
  A d;
  try
  {
    hum();
  }
  catch (const char* e) 
  {
    cout << "main中捕获异常信息: " << e << endl;
  }
  cout << "main出错后的几百行代码" << endl;
  return 0;
} // d.~A()  释放d本身所占内存空间
