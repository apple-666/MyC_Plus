/*
类模板内嵌套 用递归实例化+重载[]操作符
eg
  类A<类A<T>> a; for( for(  ))
  AppleArr<AppleArr<int> > a2;

*/
#include <iostream>
using namespace std;

template<class T>
class AppleArr{
public:
  AppleArr(){}
  T& operator[](int i){
    return arr[i];
  }
private:
  T arr[20];
};


int main()
{
  AppleArr<int> a;
  for(int i=0; i<20; i++) a[i] = i;
  for(int i=0; i<20; i++) cout<<a[i]<<endl;

  AppleArr<AppleArr<int> > a2;
  for(int i=0; i<20; i++){
    for(int j=0; j<20; j++) {
      a2[i][j] = i+j;
      cout<<a2[i][j]<<endl;
    }
  }
  return 0;
}