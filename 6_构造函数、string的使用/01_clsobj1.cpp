// ���캯��
#include <iostream> 
#include <cstring>
using namespace std;
class Human {
public:
    Human(int age = 0,const char* name = "null"){
        // ��this��ָ����ڴ�ռ��� ����m_age(��m_age�����ڴ�ռ�)��ֵΪ�����
        // ��this��ָ����ڴ�ռ��� ����m_name(��m_name�����ڴ�ռ�)��ֵΪ�����
        cout << "Human��Ĺ��캯��������" << endl;
        this->m_age = age;
        strcpy( this->m_name, name );
    }
//  void setinfo( /* Human* this */ int age=0, const char* name="����" ) { 
//      this->m_age = age;
//      strcpy( this->m_name, name );
//  }
    void getinfo( /* Human* this */ ) { 
        cout << "����: " << this->m_name << ", ����: " << this->m_age << endl;
    }
private:
    int m_age; // ��Ա����
    char m_name[256]; // ��Ա����
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main( void ) {
    Human h(22,"�ŷ�"); // ����h(��h�����ڴ�ռ�),����h.Human(22,"�ŷ�")
    h.getinfo( );

    Human apple(22,"����");
    apple.getinfo( );


//  h.setinfo( 22, "zhangfei" ); 
//  h.getinfo( ); 

    return 0;
}

