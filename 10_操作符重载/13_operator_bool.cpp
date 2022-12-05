/*
类对象转bool类型
*/
#include <iostream>
#include <cstdio>
using namespace std;

class A
{

public:
  A(int i) : m_i(i)
  {
  }
  operator bool() const
  {
    cout << "A:bool()" << endl;
    return this->m_i;
  }

private:
  int m_i;
};

int main() {
  A a(0);
  bool b = a; // bool b = a.operator bool() 
  cout<<b<<endl;
  if(b) cout<<"yes"<<endl;
  return 0;
}
