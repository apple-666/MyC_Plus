#include <iostream> 
namespace ICBC {
    int g_money = 0;
    void save( int money ) {
        g_money += money;
    }    
}
namespace CCB {
    int g_money = 0;
    void save( int money ) { // 连 声明 带 定义
        g_money += money;
    } 
    void pay( int money ) ; // 声明
}

void CCB::pay( int money ) { // 定义
    g_money -= money;
}

namespace ICBC { // 同名的名字空间可以写很多,编译器将合并为一个名字空间
    void pay( int money ) {
        g_money -= money;
    }
}

int main( void ) {
    ICBC::save( 10000 );
    ICBC::pay( 3000 );
    std::cout << "工行卡余额: " << ICBC::g_money << std::endl;
    
    CCB::save( 8000 );
    CCB::pay( 3000 );
    std::cout << "建行卡余额: " << CCB::g_money << std::endl;
    return 0;
}





