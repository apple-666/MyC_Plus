/**
 * 智能指针:
 * 标准库的智能指针(使用了类模板) + #include < memory>
 * 使用函数：auto_ptr;
 * auto_ptr<class> apple_tpr(new class);
 */

#include <iostream>
#include <fcntl.h>
#include <memory>

using namespace std;

class A
{
public:
  A() : m_f(open("./file.txt", O_CREAT | O_RDWR, 0644))
  { // 0AAA 文件权限
    cout << "打开一个文件" << endl;
  }
  ~A()
  {
    close(m_f);
    cout << "关闭文件" << endl;
  }
  void foo()
  {
    write(m_f, "apple come", 10);
    cout << "向文件写入数据" << endl;
  }

private:
  int m_f;
};

int main()
{
  auto_ptr<A> pau(new A);
  (*pau).foo();
  pau->foo();

  auto_ptr<A> pbu = pau; // 定义pbu,利用pbu.Auto_ptr( pau )
  (*pbu).foo();
  pbu->foo();
  //  (*pau).foo( ); // pau已经失效
  return 0;
}