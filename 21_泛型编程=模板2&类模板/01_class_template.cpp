/*
类模板写法:
template<class T>
class 类名{
public...
..

使用:
类名<T> 类对象
}

外部定义 类函数:
template<class T>
返回值类型 类名<T>::函数(){

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

    // 可以外部定义
    T add();
  private:
    T m1;
    T m2;
};

template<class T>
T AppleL<T>::add(){
  return m1+m2;
}
// class AppleL<int> {} 创建的类的实例

int main(){

  AppleL<int> a1(1,2);
  cout<<a1.add()<<endl;

  AppleL<float> a2(1.0,2.004);
  cout<<a2.add()<<endl;

  AppleL<double> a3(1.050,2.000);
  cout<<a3.add()<<endl;
  return 0;
}