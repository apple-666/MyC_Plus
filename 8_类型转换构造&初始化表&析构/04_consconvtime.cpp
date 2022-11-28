// 类型转换构造函数被调用的时间
#include <iostream> 
using namespace std;
class Cat {
public:
    Cat( const char* name ) : m_name(name) { // 类型转换构造
        //【string m_name(name);】
        cout << "Cat类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
private:
    string m_name;
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
void foo( Cat c ) {}
Cat bar( ) {
    return "小花"; // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小花");-->触发类型转换构造函数
                   // return 匿名Cat类对象
}
int main( void ) {
//    Cat smallwhite("小白"); // 定义smallwhite,利用smallwhite.Cat("小白")-->触发类型转换构造函数
    Cat smallwhite = "小白";// 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小白")-->触发类型转换构造函数
                            // Cat smallwhite=匿名Cat类对象

    foo( "小黑" ); // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小黑")-->触发类型转换构造函数
                   // foo( 匿名Cat类对象 )
    /*||*/bar( );
    return 0;
}





