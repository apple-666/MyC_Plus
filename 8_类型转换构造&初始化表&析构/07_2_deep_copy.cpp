// ���ָ���ͱ���,��������ǳ����
#include <iostream> 
#include <cstring>
using namespace std;

class String {
public:
  char* c_str() {return m_str;}
  void inpt(const char* str) {
    strcpy(m_str, str);
  }

  // =""  ���Բ���ֵ
  String (const char* str="") : m_str(new char[strlen(str)+1]){ // Ϊconst����,Ҫ��ʼ���ռ� 
    strcpy(m_str,str);
  }
  // �������캯��
  String (const String& that):m_str(new char[strlen(that.m_str)+1]) {
    // ������: �������� �������
    // 1,��ʼ���� ����ռ�
    // 2,strcpy ��������
    strcpy(m_str,that.m_str);
  }
  // ������ֵ����: û�г�ʼ����
  String& operator = (const String& that){
    
    if( this!=&that){ // ȡ���Ը�ֵ (thisָ��== that�ĵ�ַ)
      delete []m_str; // ��delete ��ʼ�� "\0". ���������ڴ�й¶
      this->m_str = new char[strlen(that.m_str) + 1];
      strcpy(this->m_str,that.m_str);
    }
    // strcpy(this->m_str,that.m_str); //����������,�ǵ�, ��Ϊ������ڴ�й¶


    // this->m_str = that.m_str; //���� ֻ������ָ��,û�и�������,��ǳ���� (this:String* this  that:�Ǳ���,������)
    return *this;
  }

  // ��������
  ~String(/*String * this*/) {
    delete [] this->m_str; // c++��һ���� new+delete
  }
private:
  char* m_str;
};

int main( void ) {
    String a("apple");

    /**
     * Ҫ��������: 1,��������ʱ
     */
    String b(a); 
    cout<<a.c_str()<<";a�ڴ��ַ:"<<(void*)a.c_str()<<endl;
    cout<<b.c_str()<<";b�ڴ��ַ:"<<(void*)b.c_str()<<endl;
    a.inpt("i am  Apple");
    cout<<a.c_str()<<";a�ڴ��ַ:"<<(void*)a.c_str()<<endl;
    cout<<b.c_str()<<";b�ڴ��ַ:"<<(void*)b.c_str()<<endl;

    /**
     * 2, ������ֵʱ
     * 
     */
    String c; //�������� ="" ά����һ��"\0"
    c = b;
    cout<<b.c_str()<<";�ڿ�����ֵ�� b�ڴ��ַ:"<<(void*)b.c_str()<<endl;
    cout<<c.c_str()<<";�ڿ�����ֵ�� c�ڴ��ַ:"<<(void*)c.c_str()<<endl;


    return 0;
} 
// s1.~String() s2.~String() s3.~String()   �ͷ�s1/s2/s3������ռ�ڴ�ռ�




