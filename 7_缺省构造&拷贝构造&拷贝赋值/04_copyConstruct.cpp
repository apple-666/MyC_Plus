// ��������
/**
 * ��������: 1,func��������һ�� 2,ֻ��һ�������͵Ĳ���
*/
#include <iostream> 
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="����" ) {
        //��int m_age;������m_age,��ֵΪ�����
        //��string m_name;������m_name,����m_name.string()
        cout << "Human��ȱʡ���캯��������" << endl;
        m_age =  age;
        m_name = name; 
    }
//  �����û���ṩ�������캯��,���������ṩһ��Ĭ�ϵĿ������캯��
/*  Human( const Human& that ) { 
       ��int m_age=that.m_age;������m_age,��ֵΪthat.m_age
       ��string m_name=that.m_name;������m_name,����m_name.string(that.m_name)
    }*/
    Human(const Human& that){ // const ����:�ȿ��Խ��ճ���Ҳ���Էǳ��� &���ã����⸴�Ʋ���,�������
      m_age = that.m_age;
      m_name = that.m_name;
    }

    void getinfo( /* Human* this */ ) { 
        cout << "����: " << this->m_name << ", ����: " << this->m_age << endl;
    }
private:
    int m_age; // �������͵ĳ�Ա���� 
    string m_name; // �����͵ĳ�Ա����
};

int main( void ) {
    Human h; // ����h,����h.Human() --> (����,0)
    h.getinfo( );

    Human h2(22,"�ŷ�"); // ����h2,����h2.Human(22,"�ŷ�") --> (�ŷ�,22)
    h2.getinfo( );

    Human copH(h2);
    copH.getinfo( );
    return 0;
}



