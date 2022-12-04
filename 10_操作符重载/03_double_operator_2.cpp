/**
 * 重载运算符 +=
*/
#include <iostream> 
using namespace std;
class Human { 
public:
    Human( int age=0, const char* name="无名" ) : m_age(age),m_name(name) {
    }
    void getinfo( ) {
        cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
    }
    Human& operator+=( /* Human* this */  const Human& r ) { 
        this->m_age = this->m_age+r.m_age;
        this->m_name = this->m_name+"+"+r.m_name;
        return *this;
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值
    const Human c(25,"关羽"), d(32,"马超"); // 常左值
/*
    a += b; // a.operator+=(b)  或  operator+=(a,b)
    a.getinfo( );

    a += c; // a.operator+=(c)  或  operator+=(a,c)
    a.getinfo( );

    a += Human(45, "黄忠"); // a.operator+=(Human(45,"黄忠"))  或  operator+=(a,Human(45,"黄忠"))
    a.getinfo( );
*/
    ((a+=b)+=c)+=Human(45,"黄忠");
    a.getinfo( );

    /*
    int a=10, b=20;
    const int c=30, d=40;
    a += b;
    a += c;
    a += 5;
    */
    return 0;
}



