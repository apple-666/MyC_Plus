// 必须(最好)给一个类提供无参构造
#include <iostream> 
using namespace std;
class A { 
public:
    A( int i=0 ) { // 一个类必须(最好)提供一个无参的构造函数
        //【int m_i;】
        m_i = i;
    }
private:
    int m_i;
};
class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参的构造函数
/*  Human( ) {
       【int m_age;】定义m_age,初值为随机数
       【string m_name;】定义m_name,利用m_name.string()
       【A m_a;】定义m_a,利用m_a.A()
    }*/
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        //【A m_a;】定义m_a,利用m_a.A()
        cout << "Human类缺省构造函数被调用" << endl;
        m_age =  age;
        m_name = name; 
    }
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 基本类型的成员变量 
    string m_name; // 类类型的成员变量
    A m_a; // 类类型的成员变量
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main( void ) {
    Human h; // 定义h,利用h.Human() --> (无名,0)
    h.getinfo( );

    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") --> (张飞,22)
    h2.getinfo( );
    return 0;
}



