// ���ֿռ�Ƕ��
#include <iostream> 
using namespace std;

namespace ns1 {
    int g_value = 100;
    namespace ns2 {
        int g_value = 200;
        namespace ns3 {
            int g_value = 300;
            namespace ns4 {
                int g_value = 400;
            }
        }
    }
}

int main( void ) {
    // namespace ns_four = ns1::ns2::ns3::ns4; // ���ֿռ����

    // cout << ns_four::g_value << endl;

    // cout<< ns1::ns2::ns3::ns4::g_value<<endl;
    namespace ns_my = ns1::ns2::ns3::ns4;

    cout<<ns_my::g_value<<endl;

    return 0;
}





