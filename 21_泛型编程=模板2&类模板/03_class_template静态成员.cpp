/*
类模板: 也有对应的静态成员
类模板  -类1  -类1对象a    (类1所有对象共享静态资源)
             -类1对象b
        -类2  -类2对象a   (类2所有对象共享静态资源)
             -类2对象b
}
*/
#include <iostream>
using namespace std;

template <class T>
class AppleL
{
public:
  static void print()
  {
    cout << "s_i :" << s_i << ", i :" << i;
    // 用地址证明 多个类用的是同一个静态变量
    cout << "   s_i地址:" << &s_i << ", i地址:" << &i << endl;
  }
  static int s_i;
  static T i;
};

// 静态资源一定要提前赋值
template <class T> int AppleL<T>::s_i=100;
template <class T> T AppleL<T>::i = 200; 

int main()
{
  AppleL<int> x, y;
  x.print();
  y.print();
  AppleL<int>::print();

  cout<<"类不同 地址不同"<<endl;
  AppleL<float> x2, y2;
  x2.print();
  y2.print();
  AppleL<float>::print();
  return 0;
}