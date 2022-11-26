// 模拟实现一个大型程序 数据(收，处理，转发)等功能
#include <iostream> 
namespace NetWork {
    void recv( ) {
        std::cout << "recv data" << std::endl;
    }
    void send( ) {
        std::cout << "send data" << std::endl;
    }
}
namespace Compress {
    void zip( ) {
        std::cout << "zip data" << std::endl;
    }
    void unzip( ) {
        std::cout << "unzip data" << std::endl;
    }
}
namespace EncryPt {
    void dsa( ) {
        std::cout << "dsa data" << std::endl;
    }
    void dec( ) {
        std::cout << "dec data" << std::endl;
    }
}
int main( void ) {
    NetWork::recv( );
    Compress::unzip( );
    EncryPt::dec( );
    // ...对 明文数据 进行处理...
    EncryPt::dsa( );
    Compress::zip( );
    NetWork::send( );
    return 0;
}


