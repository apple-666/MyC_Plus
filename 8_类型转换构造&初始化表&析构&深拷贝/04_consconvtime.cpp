// ����ת�����캯�������õ�ʱ��
#include <iostream> 
using namespace std;
class Cat {
public:
    Cat( const char* name ) : m_name(name) { // ����ת������
        //��string m_name(name);��
        cout << "Cat�������ת�����캯��������" << endl;
    }
    void talk( ) {
        cout << m_name << ": ����~~~" << endl;
    }
private:
    string m_name;
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
void foo( Cat c ) {}
Cat bar( ) {
    return "С��"; // ���� ����Cat�����,���� ����Cat�����.Cat("С��");-->��������ת�����캯��
                   // return ����Cat�����
}
int main( void ) {
//    Cat smallwhite("С��"); // ����smallwhite,����smallwhite.Cat("С��")-->��������ת�����캯��
    Cat smallwhite = "С��";// ���� ����Cat�����,���� ����Cat�����.Cat("С��")-->��������ת�����캯��
                            // Cat smallwhite=����Cat�����

    foo( "С��" ); // ���� ����Cat�����,���� ����Cat�����.Cat("С��")-->��������ת�����캯��
                   // foo( ����Cat����� )
    /*||*/bar( );
    return 0;
}





