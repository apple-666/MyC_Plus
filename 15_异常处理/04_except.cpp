/*
�쳣˵��:
д��function��ͷ throw(���п����쳣������)
  ��function�ڲ�,throw�ľͱ������������ڵ�
û���쳣˵��:��ŵ�����ڲ������׳��κ����͵��쳣
�쳣˵��Ϊ��:��ŵ�����ڲ������׳��κ����͵��쳣
*/

#include <iostream> 
#include <cstdio>
using namespace std;

// û���쳣˵��:��ŵ�����ڲ������׳��κ����͵��쳣
void foo1( ) { 
    throw "hello world"; // 3.14; //-1;
}

// �쳣˵��Ϊ��:��ŵ�����ڲ������׳��κ����͵��쳣
void bar1( ) throw( ) { 
    // throw -1;
}

void foo( ) throw( int ,double, const char* ) { // ��ʽ�׳��쳣
    // ...
    throw 1;
    throw 2.2;
    throw "hello world"; // 3.14; //-1;
    // ...
}

void bar( ) throw( int, double, const char* ) { // ��ʽ�׳��쳣 ҲҪȫ�����쳣��Ϣ
    foo( );
}

int main( void ) {
    try {
//        foo( );
        bar( );
    }
    catch( int& e ) {
        cout << "1-�����쳣��Ϣ: " << e << endl;
    }
    catch( double& e ) {
        cout << "2-�����쳣��Ϣ: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3-�����쳣��Ϣ: " << e << endl;
    }
    return 0;
}



