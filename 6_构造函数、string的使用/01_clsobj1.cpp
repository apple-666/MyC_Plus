// 构造函数
#include <iostream> 
#include <cstring>
using namespace std;
class Human {
public:
    Human(int age = 0,const char* name = "null"){
        // 在this所指向的内存空间中 定义m_age(给m_age分配内存空间)初值为随机数
        // 在this所指向的内存空间中 定义m_name(给m_name分配内存空间)初值为随机数
        cout << "Human类的构造函数被调用" << endl;
        this->m_age = age;
        strcpy( this->m_name, name );
    }
//  void setinfo( /* Human* this */ int age=0, const char* name="无名" ) { 
//      this->m_age = age;
//      strcpy( this->m_name, name );
//  }
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 成员变量
    char m_name[256]; // 成员变量
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main( void ) {
    Human h(22,"张飞"); // 定义h(给h分配内存空间),利用h.Human(22,"张飞")
    h.getinfo( );

    Human apple(22,"鹏鹏");
    apple.getinfo( );


//  h.setinfo( 22, "zhangfei" ); 
//  h.getinfo( ); 

    return 0;
}

