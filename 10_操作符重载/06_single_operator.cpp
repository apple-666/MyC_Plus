/**
 * 单目运算符 ++ --
 *   前置++a: 非常左值,return本身,是个左值
  *  后置a++: 非常左值,开辟匿名空间(存放旧值),是个右值
 */
#include <iostream>
using namespace std;
class Human
{
public:
  Human(int age = 0, const char *name = "无名") : m_age(age), m_name(name)
  {
  }
  void getinfo()
  {
    cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
  }
  Human& operator++(/* Human* this */) // 用了引用,就不会返回无名内存,返回对应的引用的
  {
    // c_str是char类
    // 方法一  适合无引用,return 一个右值
    // return Human(this->m_age + 1, this->m_name.c_str());

    // 方法二
    this->m_age = this->m_age + 1;
    return *this;
  }

  Human operator++(/* Human* this */ int) // 没用引用,返回无名内存
  {
    // c_str是char类 return一个右值(为旧数据)
    Human old = *this; 
    this->m_age = m_age + 1;
    return old;
  }

private:
  int m_age;
  string m_name;
};
int main(void)
{
  Human a(22, "apple"), b(20, "赵云"); // 非常左值
  (++a).getinfo(); // Human operator++

  (b++).getinfo();
  b.getinfo(); 
  // const int d = 1; 为常左值
  // cout<< d++<< endl; error
  // cout<<++d<<endl; error

  // 前置++a: 非常左值,return本身,是个左值
  // 后置a++: 非常左值,开辟匿名空间(存放旧值),是个右值
  
#if 0                                  // 是符合条件就把内容编译进去,而不是运行阶段的
      int a
#endif
  return 0;
}
