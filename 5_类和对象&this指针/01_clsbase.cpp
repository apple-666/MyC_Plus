// 类 与 对象
#include <iostream>
#include <cstring>
using namespace std;
// 类:抽取事物特征 规则
// struct

class Human
{
public:
    void setinfo(int age = 0, const char *name = "null名") // 一般传字符串常量，而不是字符串的指针，所以用const
    {
        if (!strcmp(name, "小二"))
        {
            cout << "不要取名为小二" << endl;
            return;
        }
        m_age = age;
        strcpy(m_name, name);
    }

    void getinfo()
    {
        cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
    }

private:
    int m_age;
    char m_name[100];
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main(void)
{
    // 定义h,给h分配内存空间 int+char = 104
    // 在h所占内存空间中 定义m_age(给m_age分配内存空间)初值为随机数
    // 在h所占内存空间中 定义m_name(给m_name分配内存空间)初值为随机数
    Human h;
    cout << "h对象的size：" << sizeof(h) << endl;
    char *a = "yeas!!";
    cout << "strcpy: a:" << a << endl;
    h.setinfo(22, a);
    h.getinfo();

    cout << "after: a: " << a << endl;
    // 使用了private所以，这里不能调用
    // h.m_age = 222;
    // strcpy(h.m_name, "张飞");
    //  strcpy( h.m_name, "小二" );
    // cout << "姓名: " << h.m_name << ", 年龄: " << h.m_age << endl;
    return 0;
}
