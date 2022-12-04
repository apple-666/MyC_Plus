// 操作符重载
#include <iostream>
#include <cstring>
using namespace std;

class Human
{
public:
  Human(int age, const char* name = "初始值") : m_age(age), m_name(name)
  {
  }
  void getinfo()
  {
    cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
  }
  Human add(Human r) {
    return Human(this->m_age+r.m_age,(this->m_name+"+"+r.m_name).c_str());
  }
  Human sub(Human r) {
    return Human(this->m_age-r.m_age,(this->m_name+"-"+r.m_name).c_str());
  }
private:
  int m_age;
  string m_name;
};

int main() {
  Human a(22,"apple");
  a.getinfo();
  Human b(24,"bigApple");

  Human na = a.add(b);
  na.getinfo();

  Human  res = a.add(b).sub(a.add(b)); // a + b - ( a + d ); --> a.operator+(b).operator-(c.operator-(d))
  res.getinfo();
  return 0;

}