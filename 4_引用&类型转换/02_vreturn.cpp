// 
/***
 * 引用作为返回值: fun() = return 指的变量（不能为局部变量）
*/
#include <iostream>
using namespace std;

int g_value = 0;
int &foo()
{ // 非常引用型返回值
    return g_value;
}
const int &fooo()
{ // 常引用型返回值
    return g_value;
}
int &bar()
{
    static int s_value = 0; // 这句代码是程序一启动就执行,而且执行一次. 不是每次调用bar函数都执行
    cout << "s_value=" << s_value << endl;
    return s_value;
}

int &hum()
{
    int *pn = new int;
    return *pn;
}

int &fun(int &x)
{
    return x;
}
/*
int& boo( ) {
    int m = 0;
    return m;
}*/

int main(void)
{   
    // foo为引用型函数
    foo() = 100; // 通过 非常引用型返回值,可以修改目标内存
    cout << "g_value=" << g_value << endl;
    foo() = 200; // 通过 非常引用型返回值,可以修改目标内存
    cout << "g_value=" << g_value << endl;

    // fooo() = 111; 无法修改const型function
    cout << "g_value=" << g_value << endl;

    cout<<"bar()::"<<endl;
    bar() = 123;
    cout << "g_value=" << g_value << endl;
    bar() = 124;
    cout << "g_value=" << g_value << endl;

    cout<<"hum():::"<<endl;
    hum() = 101;
    cout<<"hum():"<<hum()<<endl;

    cout<<"\n"<<"fun()::"<<endl;
    int f_val = 100;
    fun(f_val) = 101;
    cout<<"f_val:"<<f_val<<endl;
    return 0;
}
