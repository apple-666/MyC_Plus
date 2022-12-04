/*
ʹ��delete��������������
����������(�����붯̬�ڴ���������):
    �����಻��������ʱ,A a = new B,delete a; ֻ��ɾ��A��Ķ��ڴ�,B���ڴ�й¶
    ����Ҫ��virtual ������������,ʵ�����า�ǻ������������
���ۣ�����Ϊ���ཨ����������
*/

#include <iostream> 
#include <typeinfo>
using namespace std;
class A {
public:
    A() : m_a(new int) {
        //��int* m_a=new int;������m_a,��ֵΪָ��һ����ڴ�(��̬��Դ)
        cout << "A() is invoked - ������һ����ڴ�:" << m_a << endl;
    }
    virtual ~A( ) { // �� ��������
        delete m_a;
        cout << "~A() is invoked - �ͷ���һ����ڴ�:" << m_a << endl;
    } // �ͷ� m_a ������ռ�ڴ�ռ�
private:
    int* m_a;
};
class B : public A {
public:
    B() : m_b(new int) {
        cout << "B() is invoked - ������һ����ڴ�:" << m_b << endl;
    }
    ~B() {
        delete m_b;
        cout << "~B() is invoked - �ͷ���һ����ڴ�:" << m_b << endl;
         // ���� �����Ӷ���,���� �����Ӷ���.~A()
    } 
private:
    int* m_b;
};
int main( void ) {
    A* p = new B; // ���� B��Ѷ������� B��Ѷ���.B()
    delete p; // ����ָ��p->��������( ~B() )     �ͷ�B��Ѷ�������ռ�ڴ�ռ�
    return 0;
} 





