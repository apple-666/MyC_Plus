// 使用 string类对象
#include <iostream>
using namespace std;

int main(void)
{
  string s1("hello"); // 定义s1,利用s1.string("hello") ---> s1维护的字符串为"hello"
  cout << "s1:" << s1.c_str() << endl;
  cout << "s1:" << s1 << endl;

  string s2(s1);
  cout << s2.c_str() << endl;

  string s3; // 定义s3,利用s3.string() ---> s3维护的字符串为"\0"
  cout << "s3赋值前:" << s3.c_str() << endl;
  cout << "s3赋值前:" << s3 << endl;

  // 如果在赋值 并且"="两边的类型完全一致,将触发 operator= 这个函数的调用
  s3 = s2; // s3.operator=(s2) ---> s3维护的字符串 和 s2维护的字符串 内容相同
  cout << "s3赋值后:" << s3.c_str() << endl;
  cout << "s3赋值后:" << s3 << endl;

  // 如果“=”两边的类型不一致,编译器会将 “=”右边数据的类型 转成和 "="左边数据的类型 一致

  // 定义 匿名string类对象,利用匿名string类对象.string("hello")-->匿名string类对象维护的字符串为"hello"
  // string s4 = 匿名string类对象; --> s4维护的字符串 和 匿名string类对象维护的字符串 内容相同
  // ---> s4维护的字符串为"hello"
  string s4 = "hello";
  cout << "s4:" << s4.c_str() << endl;
  cout << "s4:" << s4 << endl;

  string s5;    // 定义s5,利用s5.string() ---> s5维护的字符串为"\0"
  s5 = "hello"; // 定义 匿名string类对象,利用 匿名string类对象.string("hello")-->匿名string类对象维护的字符串为"hello"
                // s5 = 匿名string类对象; --> s5维护的字符串 和 匿名string类对象维护的字符串 内容相同
                // --> s5维护的字符串为"hello"
  cout << "s5:" << s5.c_str() << endl;
  cout << "s5:" << s5 << endl;
}