/**
 * 单例模式-恶汉模式 : 程序启用就创建实例
 * 多次使用这个类,只适用同一个实例
 */

#include <iostream>
using namespace std;

class Singleton
{
public:
  static Singleton& getInstance() 
  //no.4  用了static,就可以用类名去调该方法
  //no.5  &: 用别名代替,这样就不会返回匿名对象,用的是同一个实例
  {
    return s_instance;
  }

private:
  //no.1 让构造私有,禁止定义对象
  Singleton() {} 

  //no.6 防止克隆,让拷贝构造函数也私有化
  Singleton(const Singleton &that)
  {
  }
  
  //no.2  不是本类对象,是全局作用域的对象,还要在全局作用域中加定义
  static Singleton s_instance; 
};

//no.3 在全局定义 类型 类型::instance
Singleton Singleton::s_instance;

int main()
{
  // 为同一个实例
  // no.7 只能用&别名接收,不然会触发克隆(但被私有了所以会报错)
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  Singleton &s3 = Singleton::getInstance();
  cout << "&s1:" << &s1 << ", &s2:" << &s2 << ", &s3:" << &s3 << endl;
  return 0;
}