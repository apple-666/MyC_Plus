// C++语言的一些复合的数据类型
#include <iostream>
#include <cstring>
using namespace std;

void TestStruct()
{
    struct Stu{
        int age;
        char name[299];
        void getinfo() {
            cout<<"age:"<<age<<" name:"<<name<<endl;
        }
    };
    Stu s;
    s.age = 22;
    // s.name = "apple"; //  char 数组不能直接赋值
    strcpy(s.name, "apple");
    s.getinfo();

}

void TestUnion()
{
    union  // 可以命名，不命名代表 内部的各个成员变量共用同一块空间地址
    {
        int i;
        char c[4];
    };
    i = 0x11224433; // 十六进制 
    // hex 按十六进制打印   intel芯片，是小端字节序，后面的33是低数位占低地址
    cout << hex << (int)c[0] << ' ' << (int)c[1] << ' ' << (int)c[2] << ' ' << (int)c[3] << endl;
    cout << hex <<i<<endl;
}

void TestEnum()
{
    enum Size
    {
        big,
        middle,
        small
    };
    Size idx = middle;
    cout << idx << endl;
}

void TestBool()
{
    bool a = "";         // "fds"; // 0.00000001; // 123; // true;
    bool b = 0.00000000; // 0.00000000; // 0;   // false;
    cout << "a=" << a << ", b=" << b << endl;
}
int main(void)
{
    // TestBool();
    // TestEnum();

     TestUnion( );
    //  TestStruct( );
    return 0;
}
