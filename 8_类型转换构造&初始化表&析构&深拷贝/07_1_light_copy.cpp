// ǳ����(ȱ��)
#include <iostream> 
#include <cstring>
using namespace std;

class String {
public:
  char* c_str() {return m_str;}
  void inpt(const char* str) {
    strcpy(m_str, str);
  }
  String (const char* str) : m_str(new char[strlen(str)+1]){ // Ϊconst����,Ҫ��ʼ���ռ� 
    strcpy(m_str,str);
  }
  // �������캯��
  String (const String& that): m_str(that.m_str) {
    
  }
  ~String(/*String * this*/) {
    delete [] this->m_str; // c++��һ���� new+delete
  }
private:
  char* m_str;
};

int main( void ) {
    String a("apple");

    /**
     * ����ͨ����������,����ǳ����
     * a,b ָ������һ����,��Ϊֻ�����˵�ַ,û�п���ָ�������
     * a������bͬʱҲ������
     */
    String b(a); 
    cout<<a.c_str()<<endl;
    cout<<b.c_str()<<endl;
    a.inpt("i am  Apple");
    cout<<a.c_str()<<endl;
    cout<<b.c_str()<<endl;

    return 0;
} 
// s1.~String() s2.~String() s3.~String()   �ͷ�s1/s2/s3������ռ�ڴ�ռ�




