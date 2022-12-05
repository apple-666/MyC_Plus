/*
析构函数中不建议抛异常
因为} 括号是会执行析构,
如果在try{异常1}中析构抛出异常2会 多个异常同时出现,会报错

尽量在析构中就 捕获掉异常
*/

#include <iostream> 
#include <cstdio>
using namespace std;
void foo( ) {
    throw "foo函数中抛出的异常";
}
void bar( ) {
    throw "bar函数中抛出的异常";
}
class A {
public:
    ~A( ) {
        try { // 提前解决掉异常
            bar( );
        }
        catch( const char* e ) {
            cout << "析构函数中捕获异常信息: " << e << endl;
        }
    }
};
int main( void ) {
    try {
        A a; // 定义a,利用a.A()
        foo( ); // 异常1

    }// 异常2 (析构异常中的) .现在同时出现2个异常是不允许的。因为 e只接受1个,无法识别2个
    catch( const char* e ) {
        cout << "main中捕获异常信息: " << e << endl;
    }
    return 0;
}



