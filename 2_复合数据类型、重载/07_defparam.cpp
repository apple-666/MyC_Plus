// 缺省参数:函数的形参有默认值
#include <iostream> 
using namespace std;

void foo( int a, double b, float c, short d, char e='A' ) {
    cout << e << endl;
}

int main( void ) {
    foo( 3, 6.28, 6.2, 2 );
    foo( 3, 6.28, 6.2, 2, 'B' );
    return 0;
}

