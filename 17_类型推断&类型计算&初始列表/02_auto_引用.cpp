// auto �� ���� ����ʹ��
// ͬ����Ϊ����,��ַ��ͬ
#include <iostream> 
#include <typeinfo>
using namespace std;


int main( void ) {
    int a = 10;
    const int b = 10;

    auto c = a;
    // auto:int      c:int
    cout << "c������: " << typeid(c).name() << endl; // i
    cout << "&c: " << &c << ", &a: " << &a << endl;  // ��ַ��ͬ
    c++; // �������

    auto& d = a;
    // auto: int      d: int&
    cout << "d������: " << typeid(d).name() << endl; // i
    cout << "&d: " << &d << ", &a: " << &a << endl;  // ��ַ��ͬ
    d++; // �������

    // ���ָ���������Ƶ�,����Ŀ����г�����,������Զ��Ƶ�const
    auto& e = b;
    // auto: const int      e: const int&
    cout << "e������: " << typeid(d).name() << endl; // i
    cout << "&e: " << &e << ", &b: " << &b << endl;  // ��ַ��ͬ
//  e++; // ���������

    return 0;
}






