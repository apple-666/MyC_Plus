/*
���������в��������쳣
��Ϊ} �����ǻ�ִ������,
�����try{�쳣1}�������׳��쳣2�� ����쳣ͬʱ����,�ᱨ��

�����������о� ������쳣
*/

#include <iostream> 
#include <cstdio>
using namespace std;
void foo( ) {
    throw "foo�������׳����쳣";
}
void bar( ) {
    throw "bar�������׳����쳣";
}
class A {
public:
    ~A( ) {
        try { // ��ǰ������쳣
            bar( );
        }
        catch( const char* e ) {
            cout << "���������в����쳣��Ϣ: " << e << endl;
        }
    }
};
int main( void ) {
    try {
        A a; // ����a,����a.A()
        foo( ); // �쳣1

    }// �쳣2 (�����쳣�е�) .����ͬʱ����2���쳣�ǲ�����ġ���Ϊ eֻ����1��,�޷�ʶ��2��
    catch( const char* e ) {
        cout << "main�в����쳣��Ϣ: " << e << endl;
    }
    return 0;
}



