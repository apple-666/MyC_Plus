//���� 
// ��Ա�������������������, ������������
// ��̬��Ա����: ��Ŀ::  ����ʽ����+����
//    ��ռ��Ŀռ�,�ǽ��̼���������,��ʼ���Ͷ�����ȫ��������
#include <iostream>
using namespace std;

class A {
public:
    int m_i;
    static int m_a; // ���� �ܰ��� ����ľ�̬���� ��Ϊ��Ա����
};

int A::m_a = 1111; // ������ʽ���������еľ�̬��Ա����

int main( void ) {
    A a; // ����a(��a�����ڴ�ռ�)-->������Ҫ����aռ���ڴ�ռ��С
    cout << "a�Ĵ�С:" << sizeof(a) << endl; // 4
    cout<<A::m_a<<endl;

    a.m_a = 22;
    cout<<a.m_a<<endl;
    return 0;
}
