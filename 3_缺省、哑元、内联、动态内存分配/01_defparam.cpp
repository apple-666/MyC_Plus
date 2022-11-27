// 缺省参数:函数的形参有默认值
#include <iostream> 
using namespace std;

void foo( int a, double b=6.28, float c=6.2, short d=2, char e='A' ); // 声明


void foo( int a ) { // 连声明 带定义

}

int main( void ) {
    foo( 3, 6.28, 6.2, 2 );
    foo( 3, 6.28, 6.2, 2, 'B' );

//  foo( 10 ); // 匹配歧义
    return 0;
}

void foo( int a, double b, float c, short d, char e ) { // 定义
    cout << e << endl;
}
