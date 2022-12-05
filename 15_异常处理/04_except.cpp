/*
异常说明:
写在function开头 throw(所有可能异常的类型)
  在function内部,throw的就必须是以上以内的
没有异常说明:承诺函数内部可能抛出任何类型的异常
异常说明为空:承诺函数内部绝不抛出任何类型的异常
*/

#include <iostream> 
#include <cstdio>
using namespace std;

// 没有异常说明:承诺函数内部可能抛出任何类型的异常
void foo1( ) { 
    throw "hello world"; // 3.14; //-1;
}

// 异常说明为空:承诺函数内部绝不抛出任何类型的异常
void bar1( ) throw( ) { 
    // throw -1;
}

void foo( ) throw( int ,double, const char* ) { // 显式抛出异常
    // ...
    throw 1;
    throw 2.2;
    throw "hello world"; // 3.14; //-1;
    // ...
}

void bar( ) throw( int, double, const char* ) { // 隐式抛出异常 也要全部的异常信息
    foo( );
}

int main( void ) {
    try {
//        foo( );
        bar( );
    }
    catch( int& e ) {
        cout << "1-捕获异常信息: " << e << endl;
    }
    catch( double& e ) {
        cout << "2-捕获异常信息: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3-捕获异常信息: " << e << endl;
    }
    return 0;
}



