/**
 * 单目运算符 -
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
    Human operator-( /*const Human* this */ ) const { 
        return Human(-this->m_age,("-"+this->m_name).c_str()); 
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"apple"), b(20,"赵云"); // 非常左值
    Human res = -a;
    res.getinfo();
    (-b).getinfo();
    res = -Human(11,"small");
    res.getinfo();
    // (-a).getinfo();

    #if 0 // 是符合条件就把内容编译进去,而不是运行阶段的
      int a
    #endif 
    return 0;
}



