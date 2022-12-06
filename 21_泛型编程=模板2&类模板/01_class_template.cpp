/*
��ģ��д��:
template<class T>
class ����{
public...
..

ʹ��:
����<T> �����
}

�ⲿ���� �ຯ��:
template<class T>
����ֵ���� ����<T>::����(){

}
*/
#include<iostream>
using namespace std;

template<class T>
class AppleL{
  public:
    AppleL(const T&  a1, T const& a2):m1(a1),m2(a2) {}
    // T add(){
    //   return m1 + m2;
    // }

    // �����ⲿ����
    T add();
  private:
    T m1;
    T m2;
};

template<class T>
T AppleL<T>::add(){
  return m1+m2;
}
// class AppleL<int> {} ���������ʵ��

int main(){

  AppleL<int> a1(1,2);
  cout<<a1.add()<<endl;

  AppleL<float> a2(1.0,2.004);
  cout<<a2.add()<<endl;

  AppleL<double> a3(1.050,2.000);
  cout<<a3.add()<<endl;
  return 0;
}