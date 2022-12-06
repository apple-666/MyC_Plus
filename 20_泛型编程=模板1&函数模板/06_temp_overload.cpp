/*
函数模板的重载
匹配相同 用普通函数
使用<> 强行用模板函数
*/
#include<iostream>
using namespace std;

void Max(int x,int y){
  cout<<"普通函数"<<endl;
}

template<class T>
void Max(T a,T b){
  cout<<"模板函数"<<endl;
}

int main(){
  Max(1,2);
  Max<>(1,2);

  Max(1.0,2.0);
  return 0;
}
