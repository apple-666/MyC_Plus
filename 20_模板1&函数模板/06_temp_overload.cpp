/*
����ģ�������
ƥ����ͬ ����ͨ����
ʹ��<> ǿ����ģ�庯��
*/
#include<iostream>
using namespace std;

void Max(int x,int y){
  cout<<"��ͨ����"<<endl;
}

template<class T>
void Max(T a,T b){
  cout<<"ģ�庯��"<<endl;
}

int main(){
  Max(1,2);
  Max<>(1,2);

  Max(1.0,2.0);
  return 0;
}
