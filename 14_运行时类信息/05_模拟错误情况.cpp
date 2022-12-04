#include <iostream> 
#include <cstdio>
using namespace std;
class A {
public:
    A() {   cout << "A() is invoked" << endl;   }
    ~A() {   cout << "~A() is invoked" << endl;   }
};

int foo( ) {
    cout << "foo����ǰ�ļ����д��� ";
    A a;
    FILE* pFile = fopen( "./cfg", "r" );
    if( !pFile ) 
        return -1; // (1) �����ݷ��ظ������� (2) ��ת���һ�����
    cout << "foo�����ļ����д���" << endl;
    return 0;
} // a.~A()    �ͷ�a������ռ�ڴ�ռ�

int bar( ) {
    cout << "bar����ǰ�ļ����д��� ";
    A b;
    if( foo()==-1 )
        return -1;
    cout << "bar�����ļ����д���" << endl;
    return 0;
} // b.~A()  �ͷ�b������ռ�ڴ�ռ�

int hum( ) {
    cout << "hum����ǰ�ļ����д��� ";
    A c;
    if( bar()==-1 )
        return -1;
    cout << "hum�����ļ����д���" << endl;
    return 0;
} // c.~A()  �ͷ�c������ռ�ڴ�ռ�

int main( void ) {
    cout << "main����ǰ�ļ����д��� ";
    A d;
    if( hum()==-1 )
        return -1;
    cout << "main�����ļ����д���" << endl;
    return 0;
} // d.~A()  �ͷ�d������ռ�ڴ�ռ�




