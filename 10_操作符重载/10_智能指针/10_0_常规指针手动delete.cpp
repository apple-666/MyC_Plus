#include<iostream>
#include<fcntl.h>
using namespace std;

class A{
public:
  A() : m_f(open("./file.txt",O_CREAT|O_RDWR,0644)) { //0AAA 文件权限
    cout<<"打开一个文件"<<endl;
  }
  ~A() {
    close(m_f);
    cout<<"关闭文件"<<endl;
  }
  void foo() {
    write(m_f,"apple come",10);
    cout<<"向文件写入数据"<<endl;
  }
private:
  int m_f;
};

int main() {
  /**
   * 常规指针离开本身作用域(这里是main作用域),pa指针会被释放,
   * 但是指向的对象(动态内存)不会释放,会造成内存泄露,
   * 所以要手动delete(会调用析构函数)
  */
  A* pa = new A;
  (*pa).foo();
  pa->foo(); 
  delete pa; // 会调用析构函数 pa->~A() 。 栈对象用{}可以清理,堆对象(动态内存)要用delete
  return 0;
}