// 内联函数
#include <iostream>
using namespace std;

void foo(int x)
{ 
    cout << "foo(int): " << x << endl;
}

inline void bar(int x){
    cout<<"bar"<<endl;
}

#define printAll() cout<<"apple come on"<<endl;

// 跳转很耗时间
// 普通函数 ,main中调用一次函数，发生两次跳转
// inline函数，替换成二进制指令集，不发生跳转
//       特点： 二进制指令集太占内存，只适合频繁调用的简单的函数
// define 带参宏定义，预编译器阶段 将此处替换为纯文本内容,然后到了正式编译阶段再将文本内容替换为二进制指令集
int main(void)
{
    // 编译器将此处替换为跳转指令
    foo(10);
    foo(20); 
    foo(30); 

    // inline 内联
    bar(10);

    //
    printAll();
    return 0;
}
