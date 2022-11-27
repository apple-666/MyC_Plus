// 哑元 函数的参数有数据类型，没有参数名
#include <iostream> 
using namespace std;

void foo( int ) {
    // 函数内部 不能获取 用户传递的 实参数据
    cout << "foo(int)" << endl;
    // 高精尖的人工智能算法,不需要根据用户传递的数据，也可以得出正确结果
}

void foo( ) {
    cout << "foo()" << endl;
}

int main( void ) {
    foo( 10 );

    foo( );
    return 0;
}

