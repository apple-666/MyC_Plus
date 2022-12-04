/**
 * ��������� +=
*/
#include <iostream> 
using namespace std;
class Human { 
public:
    Human( int age=0, const char* name="����" ) : m_age(age),m_name(name) {
    }
    void getinfo( ) {
        cout << "����: " << m_name << ", ����: " << m_age << endl;
    }
    Human& operator+=( /* Human* this */  const Human& r ) { 
        this->m_age = this->m_age+r.m_age;
        this->m_name = this->m_name+"+"+r.m_name;
        return *this;
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"�ŷ�"), b(20,"����"); // �ǳ���ֵ
    const Human c(25,"����"), d(32,"��"); // ����ֵ
/*
    a += b; // a.operator+=(b)  ��  operator+=(a,b)
    a.getinfo( );

    a += c; // a.operator+=(c)  ��  operator+=(a,c)
    a.getinfo( );

    a += Human(45, "����"); // a.operator+=(Human(45,"����"))  ��  operator+=(a,Human(45,"����"))
    a.getinfo( );
*/
    ((a+=b)+=c)+=Human(45,"����");
    a.getinfo( );

    /*
    int a=10, b=20;
    const int c=30, d=40;
    a += b;
    a += c;
    a += 5;
    */
    return 0;
}



