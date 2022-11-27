// ������  ��  ������
/***
 * ������ ���ɱ�Ķ��� const����
 * �������� function�е�thist �г����� ��const
*/
#include <iostream> 
using namespace std;
class Integer {
public:
    // ��ͨ�ķ�const����
    void setinfo( /* Integer* this */ int i ) { // �ǳ�����
        m_i = i; 
    }
    void getinfo( /* Integer* this */ ) { // �ǳ�����
        cout << "�ǳ�����getinfo:" << m_i << endl;
    }

    // const����
    // const����Ӧ����set��Ȩ�ޣ����Բ����޸ĸ�ֵ, ӲҪ�޸ģ���Ҫǿ��ת���� �ǳ�ָ��
    void setinfo(/* const Integer* this */ int i ) const { // �ǳ�����
       // ǿ��ת���� �ǳ�ָ��
       const_cast<Integer*>(this)->m_i = i;
       cout<<"set ������"<<endl;
    }
    void getinfo( /* const Integer* this */) const {
        // const_cast<Integer*>(this)->m_i = 11111;
        cout<<"��������"<< m_i<<endl;
    }
private:
    /*mutable*/ int m_i; // ��mutableҲ�� �����г�ָ��ת�˷ǳ�ָ��
};
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main( void ) {
    Integer ix; // ixΪ �ǳ�����
    ix.setinfo( 8888 );
    ix.getinfo( ); // getinfo( &ix )-->ʵ������Ϊ Integer*

    const Integer cix = ix ; // cixΪ ������
    cix.setinfo( 2222 );
    cix.getinfo( ); // getinfo( &cix )-->ʵ������Ϊ const Integer*
    return 0;
}



