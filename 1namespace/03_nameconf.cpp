#include <iostream> 
namespace ICBC {
    int g_money = 0;
    void save( int money ) {
        g_money += money;
    }    
}
namespace CCB {
    int g_money = 0;
    void save( int money ) { // �� ���� �� ����
        g_money += money;
    } 
    void pay( int money ) ; // ����
}

void CCB::pay( int money ) { // ����
    g_money -= money;
}

namespace ICBC { // ͬ�������ֿռ����д�ܶ�,���������ϲ�Ϊһ�����ֿռ�
    void pay( int money ) {
        g_money -= money;
    }
}

int main( void ) {
    ICBC::save( 10000 );
    ICBC::pay( 3000 );
    std::cout << "���п����: " << ICBC::g_money << std::endl;
    
    CCB::save( 8000 );
    CCB::pay( 3000 );
    std::cout << "���п����: " << CCB::g_money << std::endl;
    return 0;
}





