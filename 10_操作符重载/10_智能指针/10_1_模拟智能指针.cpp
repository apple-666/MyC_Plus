/**
 * 智能指针:
 * 本质是个类对象,当离开作用域时,在析构函数中释放动态内存
 * 
 * 让类对象当指针使用: 重载解引用* 和 间接访问成员操作符->
 *    (*ptr).foo() (堆地址)调用方法 用 .
 *    ptr->foo()   指针调用方式用 ->
*/

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

class Auto_ptr {
public:
  Auto_ptr(A* a): pa(a) {
  }
  ~Auto_ptr() {
    delete pa;
    pa = NULL;
  }
  A& operator*(){
    return *pa;
  }
  A* operator->(){
    return pa;
  }
  Auto_ptr(Auto_ptr& that):pa(that.pa){
     // 智能指针出现拷贝时,
     // 只能有一个指针有效(指向对象的堆地址,来避免double free)
    that.pa = NULL;
  }
private:
  A* pa; // 指向new的堆内存地址
};

int main() {
  // Auto_ptr pau = new A; // pau 指向new A的堆内存
  Auto_ptr pau(new A);
  (*pau).foo(); // pau.operator*().foo()
  pau->foo(); // pau.operator->().foo() 重写这两个operator

  Auto_ptr pau2 = pau;
  // pau->foo(); // 
  return 0;
}