// 必须要自定义析构的情况
// 动态资源: 在程序运行期间存在的资源

#include <iostream>
using namespace std;

class A {
public:
  A(int i=0):m_i(i),m_p(new int) {
        //【int* m_p=new int;】定义m_i,初值为指向一块堆内存(动态资源)
  }
  ~A(){
    delete m_p; 
    cout<<"在析构中删除动态资源"<<endl;
  }// 释放m_i / m_p本身所占内存空间

private:
  int m_i;
  int* m_p;
};

int main( void ) {
  A a;
  return 0;

}