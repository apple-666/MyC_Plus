// ���ͼ��� �� �����Ƶ� ������͵�ȷ�� ����Ӿ�׼
#include <iostream>
#include <typeinfo>
using namespace std;


int main( void ) {
    const int a = 10;
    
    auto b = a;
    // b: int
    cout << "b������: " << typeid(b).name() << endl; // i
    cout << "b=" << b << ", a=" << a << endl; // b�ĳ�ʼֵ �� a��ͬ
    b++; // �������

    decltype(a) c = a;
    // c: const int
    cout << "c������: " << typeid(c).name() << endl; // i
    cout << "c=" << c << ", a=" << a << endl; // c�ĳ�ʼֵ �� a��ͬ
//  c++; // ���������
    return 0;
}
