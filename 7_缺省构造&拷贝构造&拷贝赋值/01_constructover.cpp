// ���캯��������
#include <iostream> 
#include <cstring>
using namespace std;
class Human {
public:
/*  Human( ) {
        // ���� m_age,m_name
        cout << "1. Human() --> ";
        m_age = 0;
        m_name = "����";
    }
    Human( int age ) {
        // ���� m_age,m_name
        cout << "2. Human(int) --> ";
        m_age = age;
        m_name = "����";
    }*/
    Human( int age=0, const char* name="����" ) {
        // ���� m_age,m_name
        cout << "3. Human(int,const char*) --> ";
        m_age = age;
        this-> m_name = name;
    }
    void getinfo( /* Human* this */ ) { 
        cout << "����: " << this->m_name << ", ����: " << this->m_age << endl;
    }
private:
  int m_age;
  string m_name;
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main( void ) {
    Human h; // ����h,����h.Human()
    h.getinfo( );

    Human h2(22); // ����h2,����h2.Human(22)
    h2.getinfo( );

    Human h3( 22, "�ŷ�" ); // ����h3,����h3.Human(22,"�ŷ�")
    h3.getinfo( );
    return 0;
}



