// ���ֿռ�����
#include <iostream> 
using namespace std;

namespace ns {
    int g_value = 0;
}
//int g_value = 0;
using ns::g_value; // �����д��뿪ʼ,ns�е�g_value���뵱ǰ������(�൱�ڶ���)
int main( void ) {
 int g_value = 0;
//  using ns::g_value; // �����д��뿪ʼ,ns�е�g_value���뵱ǰ������(�൱�ڶ���)
    g_value = 8888; 
    cout << "ns::g_value= " << ns::g_value << endl;
    cout<<"main������е�"<<g_value<<endl;
    return 0;
}





