/***
 * &引用,为地址变量
*/

#include <iostream> 
using namespace std;
    
int main( void ) {
    int a = 10;
    int& b = a; // 这并不是利用a的数据给b赋初值,而应该理解为 引用b是a所代表的内存的别名

    b = 20; // 对引用b赋值,其实就是在对引用b的目标内存(a)进行赋值
    cout<<"1,创建引用变量b"<<endl;
    cout << "a=" << a << ", b=" << b << endl; // 读取引用b的值,其实读取的为引用b的目标内存(a)的值
    cout << "&a:" << &a << ", &b:" << &b << endl; // 获取引用b的地址,其实获取的为引用b的目标内存(a)的地址

    int c = 30;
    b = c; // 不要理解为引用b的目标内存变为c,而应该理解为 用c的数据给 引用b的目标内存(a)赋值
    cout<<"2,给引用变量b赋值代表,目标地址赋值"<<endl;
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    cout << "&a:" << &a << ", &b:" << &b << ", &c:" << &c << endl;

    int& d = b;
    cout << "&a: " << &a << ", &b: " << &b << ", &d: " << &d << endl;

    const int e = 100;
//  int& f = e; // error, 别名不能比真名限定的更加宽松
    const int& newe = e;
    cout<<"\n"<<newe<<endl;
    return 0;
}

