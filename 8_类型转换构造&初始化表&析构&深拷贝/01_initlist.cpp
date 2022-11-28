/***
 * 初始化表：
 * 在() {} 中 加变量初始化表: :m_age(形参a),m_name(形参b) 
*/
#include <iostream> 
using namespace std;
class Human {
public:
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
    Human( int age=0, const char* name="无名" ) :m_age(age),m_name(name) {
        cout << "Human类缺省构造函数被调用" << endl;
        m_age =  age;
        m_name = name; 
    }
    Human( const Human& that ):m_age(that.m_age),m_name(that.m_name)  { 
        cout << "Human类的拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }
//  如果类没有提供拷贝赋值函数,编译器将提供一个默认的拷贝赋值函数
/*  Human& operator=( const Human& that ) {
        this->m_age = that.m_age;
        this->m_name = that.m_name; // string类拷贝赋值函数
        return *this;
    }*/
    Human& operator = (const Human& that ) {
      this->m_name = that.m_name;
      this->m_age = that.m_age;
      return *this;
    }
private:
    int m_age; // 基本类型的成员变量 
    string m_name; // 类类型的成员变量
};


int main( void ) {
    Human h; // 定义h,利用h.Human() --> (无名,0)
    cout << "h被赋值前: ";
    h.getinfo( );

    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") --> (张飞,22)
    h2.getinfo( );

    Human h3(h2); //= h2; 定义h3,利用h3.Human(h2) --> h3维护的数据 和 h2维护的数据 内容相同
    h3.getinfo( );

    h = h3; // h.operator=(h3) 拷贝赋值函数 --> h维护的数据 和 h3维护的数据 内容相同
    cout << "h被赋值后: ";
    h.getinfo( );

    return 0;
}



