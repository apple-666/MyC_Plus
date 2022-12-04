/**
 * ��������� �Ƚ��������
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
    bool operator==( /* Human* this */  const Human& r ) { 
        return this->m_name == r.m_name && this->m_age == r.m_age;
    }
    bool operator!=( /* Human* this */  const Human& r ) { 
        return !(*this==r); // ���ø����ص�==
        // return this->m_name != r.m_name || this->m_age != r.m_age;
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"apple"), b(20,"����"); // �ǳ���ֵ
    const Human c(22,"apple"), d(32,"��"); // ����ֵ

    if( a==c) {
      cout<<"�������"<<endl;
    }else {
      cout<<"���߲����"<<endl;
    }
    cout<< (a==c) <<endl;
    cout<< (a!=c) <<endl;
    return 0;
}



