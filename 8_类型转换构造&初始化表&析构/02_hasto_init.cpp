// 在初始化表中: 如果类中有const属性,一定要放进去,其他普通变量可以不放进去
#include <iostream>
#include <cstring>
using namespace std;
class Human
{
public:
  void getinfo(/* Human* this */)
  {
    cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << ", 成绩:" << this->m_score
         << ", 名字的长度: " << m_len << endl;
  }
  Human(int age = 0, const char *name = "无名", float score = 0.0)
    : m_age(age), m_score(score),m_name(name),m_len(strlen(name))
  {
    cout << "Human类缺省构造函数被调用" << endl;
  }
  Human(const Human &that)
    : m_age(that.m_age), m_score(that.m_score), m_name(that.m_name),m_len(that.m_len)
  { // that.arg  访问对象用.  访问指针用->
    cout << "Human类的拷贝构造函数被调用" << endl;
  }

private:
  int m_len; // 保存名字字符串的长度
  int m_age;
  string m_name;       // 保存名字字符串
  const float m_score; // 常量型成员变量
  //  int m_len;
};

int main(void)
{

  // Human h2(22, "张飞", 88.5); // 定义h2,利用h2.Human(22,"张飞",88.5)
  // h2.getinfo();

  // Human h3(h2); //= h2; 定义h3,利用h3.Human(h2) --> h3维护的数据 和 h2维护的数据 内容相同
  // h3.getinfo();

  return 0;
}
