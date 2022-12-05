/*
&& 的应用 ： 实现转移 提升性能

以下的原来是用拷贝构造和拷贝赋值   ->  现在用了String&&  是转移拷贝构造和转移拷贝赋值 性能更高
  String c = String("pera"); // c.String( String() )
  d = String("pear");

*/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
  String(const char *psz = "null") : m_psz(new char[strlen(psz) + 1])
  {
    strcpy(m_psz, psz);
  }
  ~String()
  {
    delete[] this->m_psz;
  }
  char *c_str()
  {
    return m_psz;
  }

  //深拷贝 资源重建
  String(const String &that) : m_psz(new char[strlen(that.m_psz) + 1])
  {
    strcpy(m_psz, that.m_psz);
    cout << "String类的深拷贝构造函数被调用" << endl;
  }
  // 转义拷贝构造函数 资源转移
  String(String &&that) : m_psz(that.m_psz)
  {
    // 类似浅拷贝。但右值会dead 不保存地址
    // 这是原来的右值 本就要消亡 所以 设为null
    that.m_psz = NULL;
    cout << "String类的转移构造函数被调用" << endl;
  }

  // 深拷贝赋值函数  先delete本身再赋值
  String operator=(String &that)
  {
    cout << "String类深拷贝赋值函数被调用" << endl;
    if (this != &that)
    {
      // char *old = this->m_psz; // 这步多余
      delete[] m_psz;
      this->m_psz = new char[strlen(that.m_psz) + 1];
      strcpy(this->m_psz, that.m_psz);
    }
    return *this;
  }
  // 转义拷贝赋值函数
  String &operator=(String &&that)
  {
    cout << "String类的转移赋值函数被调用" << endl;
    delete[] this->m_psz; // 左值 先delete
    this->m_psz = that.m_psz;
    that.m_psz = nullptr; // 右值 null
    return *this;
  }

private:
  char *m_psz;
};

int main()
{
  String a("apple");

  // 深拷贝构造
  String b = a;
  //转移拷贝构造函数 "pear"为右值用普通深拷贝浪费性能 用转移拷贝提高性能
  String c = String("pera"); // c.String( String() )
  // 深拷贝赋值
  String d;
  d = a; // d.operator=(a)
  // 转移拷贝赋值函数
  d = String("pear");
  return 0;
}