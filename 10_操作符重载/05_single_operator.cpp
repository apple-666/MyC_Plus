/**
 * ��Ŀ����� -
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
    Human operator-( /*const Human* this */ ) const { 
        return Human(-this->m_age,("-"+this->m_name).c_str()); 
    }
private:
    int m_age;
    string m_name;
};
int main( void ) {
    Human a(22,"apple"), b(20,"����"); // �ǳ���ֵ
    Human res = -a;
    res.getinfo();
    (-b).getinfo();
    res = -Human(11,"small");
    res.getinfo();
    // (-a).getinfo();

    #if 0 // �Ƿ��������Ͱ����ݱ����ȥ,���������н׶ε�
      int a
    #endif 
    return 0;
}



