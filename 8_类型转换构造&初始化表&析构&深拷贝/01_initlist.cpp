/***
 * ��ʼ����
 * ��() {} �� �ӱ�����ʼ����: :m_age(�β�a),m_name(�β�b) 
*/
#include <iostream> 
using namespace std;
class Human {
public:
    void getinfo( /* Human* this */ ) { 
        cout << "����: " << this->m_name << ", ����: " << this->m_age << endl;
    }
    Human( int age=0, const char* name="����" ) :m_age(age),m_name(name) {
        cout << "Human��ȱʡ���캯��������" << endl;
        m_age =  age;
        m_name = name; 
    }
    Human( const Human& that ):m_age(that.m_age),m_name(that.m_name)  { 
        cout << "Human��Ŀ������캯��������" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }
//  �����û���ṩ������ֵ����,���������ṩһ��Ĭ�ϵĿ�����ֵ����
/*  Human& operator=( const Human& that ) {
        this->m_age = that.m_age;
        this->m_name = that.m_name; // string�࿽����ֵ����
        return *this;
    }*/
    Human& operator = (const Human& that ) {
      this->m_name = that.m_name;
      this->m_age = that.m_age;
      return *this;
    }
private:
    int m_age; // �������͵ĳ�Ա���� 
    string m_name; // �����͵ĳ�Ա����
};


int main( void ) {
    Human h; // ����h,����h.Human() --> (����,0)
    cout << "h����ֵǰ: ";
    h.getinfo( );

    Human h2(22,"�ŷ�"); // ����h2,����h2.Human(22,"�ŷ�") --> (�ŷ�,22)
    h2.getinfo( );

    Human h3(h2); //= h2; ����h3,����h3.Human(h2) --> h3ά�������� �� h2ά�������� ������ͬ
    h3.getinfo( );

    h = h3; // h.operator=(h3) ������ֵ���� --> hά�������� �� h3ά�������� ������ͬ
    cout << "h����ֵ��: ";
    h.getinfo( );

    return 0;
}



