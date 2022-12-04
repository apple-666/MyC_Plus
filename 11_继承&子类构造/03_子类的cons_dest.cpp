/*
子类的构造函数和析构函数
*/

#include <iostream>
using namespace std;

class Farther
{
public:
  // 构造 (有默认的)
  Farther(int age = 1, const char *name = "null") : m_age(age), m_name(name){};

  // 拷贝构造 (有默认的)
  Farther(const Farther &that) : m_age(that.m_age), m_name(that.m_name)
  {
    cout << "~~~拷贝构造函数" << endl;
  };

  // 拷贝赋值构造 (使用& 减少一次拷贝构造)
  Farther &operator=(const Farther &that)
  {
    this->m_age = that.m_age + 1;
    this->m_name = that.m_name;
    cout << "~~~拷贝赋值函数" << endl;
    return *this;
  }

  // 析构
  ~Farther()
  {
    cout << "~~~析构函数" << endl;
  }

  void getInfo()
  {
    cout << "age:" << m_age << " name:" << m_name;
  }

private:
  int m_age;
  string m_name;
};

class Son : public Farther
{
public:
  void getInfo()
  {
    Farther::getInfo();
    cout << ", 成绩: " << m_score << ", 评语: " << m_remark << endl;
  }
  // 构造
  Son(int age = 0, const char *name = "null", float score = 1.0, const char *remark="null")
      : Farther(age, name), m_score(score), m_remark(remark)
  {
    cout << "son 构造函数" << endl;
  }

  // 拷贝构造
  Son(const Son& that):Farther(that),m_score(that.m_score),m_remark(that.m_remark){
    cout<<"son 拷贝构造函数"<<endl;
  }

  // 拷贝赋值(默认的都实现了)
  Son& operator=(const Son& that){
    Farther& lv = *this;
    const Farther& rv = that;
    lv = rv; // 调用父类的 lv.operator=(rv)
    this->m_score = that.m_score;
    this->m_remark = that.m_remark;
    cout<<"子类的拷贝赋值构造"<<endl;
    return *this;
  }

  // 析构
  ~Son(){
    cout<<"Son 析构函数"<<endl;
  }

private:
  float m_score;
  string m_remark;
};

int main()
{

  // Farther far(22, "apple");
  // far.getInfo();

  // Farther far2(far);
  // far2.getInfo();

  // Farther far3;
  // far3 = far; // 使用拷贝赋值: far3.operator= ()  再把匿名拷贝到 = 后面
  // far3.getInfo();
  // Farther far4 = far; // 使用拷贝构造


  Son son1(33,"farther",100.0,"优秀");
  son1.getInfo();

  Son son2(son1); // 拷贝构造 (父类拷贝构造 + 子类的拷贝构造)
  son2.getInfo(); // 父类的析构 + 子类的析构

  Son s3;
  s3 = son1;// 拷贝赋值函数 son2.operator=(son1)
  s3.getInfo(); 
  return 0;
}
