// �������챻���õ�ʱ��(ֻҪ�ж����¡���)
#include <iostream> 
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="����" ) {
        //��int m_age;������m_age,��ֵΪ�����
        //��string m_name;������m_name,����m_name.string()
        m_age =  age;
        m_name = name; 
    }
    Human( const Human& that ) { 
        //��int m_age;������m_age,��ֵΪ�����
        //��string m_name;������m_name,����m_name.string()
        cout << "Human��Ŀ������캯��������" << endl;
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
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
void foo( Human v ) { // �� Human &v �Ͳ��´��
}
Human bar( ) {
    Human m;
    return m;
}
int main( void ) {
    Human h2(22,"�ŷ�"); 

    Human h3(h2); // -->�����������캯��

    foo( h3 ); // --> �����������캯�� ���ú���ʽ,����Բ�������һ�ݣ��β�����&�����Ͳ��´����

    Human h4 = /*|����Human����|*/bar( ); // --> ����2��2�ο������캯��(���ᱻ�������Ż�)
    // ��һ��:return n��һ������Human �ڶ���:Human h4=*.Human(��������)

    
    // -fno-elide-constructors (���ѡ�����Ҫ�� ������ ��Ҫ�Ż��������)
    return 0;
}



