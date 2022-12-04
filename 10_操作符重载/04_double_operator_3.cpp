/**
 * 重载运算符 比较类运算符
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
    bool operator==( /* Human* this */  const Human& r ) { 
        return this->m_name == r.m_name && this->m_age == r.m_age;
    }
    bool operator!=( /* Human* this */  const Human& r ) { 
        return !(*this==r); // 引用刚重载的==
        // return this->m_name != r.m_name || this->m_age != r.m_age;
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"apple"), b(20,"赵云"); // 非常左值
    const Human c(22,"apple"), d(32,"马超"); // 常左值

    if( a==c) {
      cout<<"两者相等"<<endl;
    }else {
      cout<<"两者不相等"<<endl;
    }
    cout<< (a==c) <<endl;
    cout<< (a!=c) <<endl;
    return 0;
}



