/**
 * 单例模式 - 懒汉式单例
 */
#include <iostream>
using namespace std;
// 设计一个类,保证用户在使用这个类时,只能出现一个对象

class Singleton
{
public:
  static Singleton &getInstance()
  {
    if (s_instance == nullptr)
    {
      // no.3 创建一个对象, 并让指针指向对象
      s_instance = new Singleton();
      cout << "new 实例" << endl;
    }
    ++s_counter;
    return *s_instance; // 返回指针指向的对象
  }
  void releaseInstance()
  {
    if (--s_counter == 0) // no.4 多线程下防止提前delete
    {
      delete s_instance;
      s_instance = nullptr; // delete空指针是安全的
      cout << "销毁对象" << endl;
    }else {
      cout<<"对象正在被其他线程使用中"<< endl;
    }
  }

private:
  Singleton(){};
  Singleton(const Singleton &that){};

  // no.1 是: 指向对象的指针
  static Singleton *s_instance;
  static int s_counter;
};

// no.2 指针型的static定义
Singleton *Singleton::s_instance = nullptr;
int Singleton::s_counter = 0;

int main()
{
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  cout << "&s1:" << &s1 << ", &s2:" << &s2 << endl;

  s1.releaseInstance();
  s2.releaseInstance();


  Singleton &s3 = Singleton::getInstance();

  return 0;
}
