// 拷贝构造
/**
 * 拷贝构造: 1,func名和类名一样 2,只有一个本类型的参数
*/
#include <iostream> 
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        cout << "Human类缺省构造函数被调用" << endl;
        m_age =  age;
        m_name = name; 
    }
//  如果类没有提供拷贝构造函数,编译器将提供一个默认的拷贝构造函数
/*  Human( const Human& that ) { 
       【int m_age=that.m_age;】定义m_age,初值为that.m_age
       【string m_name=that.m_name;】定义m_name,利用m_name.string(that.m_name)
    }*/
    Human(const Human& that){ // const 作用:既可以接收常数也可以非常数 &作用：避免复制操作,提高性能
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

int main( void ) {
    Human h; // 定义h,利用h.Human() --> (无名,0)
    h.getinfo( );

    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") --> (张飞,22)
    h2.getinfo( );

    Human copH(h2);
    copH.getinfo( );
    return 0;
}



