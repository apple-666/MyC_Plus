// ����(���)��һ�����ṩ�޲ι���
#include <iostream> 
using namespace std;
class A { 
public:
    A( int i=0 ) { // һ�������(���)�ṩһ���޲εĹ��캯��
        //��int m_i;��
        m_i = i;
    }
private:
    int m_i;
};
class Human {
public:
//  �����û���ṩ�κι��캯��,���������ṩһ���޲εĹ��캯��
/*  Human( ) {
       ��int m_age;������m_age,��ֵΪ�����
       ��string m_name;������m_name,����m_name.string()
       ��A m_a;������m_a,����m_a.A()
    }*/
    Human( int age=0, const char* name="����" ) {
        //��int m_age;������m_age,��ֵΪ�����
        //��string m_name;������m_name,����m_name.string()
        //��A m_a;������m_a,����m_a.A()
        cout << "Human��ȱʡ���캯��������" << endl;
        m_age =  age;
        m_name = name; 
    }
    void getinfo( /* Human* this */ ) { 
        cout << "����: " << this->m_name << ", ����: " << this->m_age << endl;
    }
private:
    int m_age; // �������͵ĳ�Ա���� 
    string m_name; // �����͵ĳ�Ա����
    A m_a; // �����͵ĳ�Ա����
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main( void ) {
    Human h; // ����h,����h.Human() --> (����,0)
    h.getinfo( );

    Human h2(22,"�ŷ�"); // ����h2,����h2.Human(22,"�ŷ�") --> (�ŷ�,22)
    h2.getinfo( );
    return 0;
}



