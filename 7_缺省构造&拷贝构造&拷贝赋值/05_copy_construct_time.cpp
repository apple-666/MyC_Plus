// 拷贝构造被调用的时间(只要有对象克隆情况)
#include <iostream> 
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        m_age =  age;
        m_name = name; 
    }
    Human( const Human& that ) { 
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        cout << "Human类的拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 基本类型的成员变量 
    string m_name; // 类类型的成员变量
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
void foo( Human v ) { // 用 Human &v 就不会拷贝
}
Human bar( ) {
    Human m;
    return m;
}
int main( void ) {
    Human h2(22,"张飞"); 

    Human h3(h2); // -->触发拷贝构造函数

    foo( h3 ); // --> 触发拷贝构造函数 调用函数式,都会对参数拷贝一份（形参用了&别名就不会拷贝）

    Human h4 = /*|匿名Human对象|*/bar( ); // --> 触发2次2次拷贝构造函数(但会被编译器优化)
    // 第一次:return n出一个匿名Human 第二次:Human h4=*.Human(匿名对象)

    
    // -fno-elide-constructors (这个选项可以要求 编译器 不要优化构造过程)
    return 0;
}



