// 浅拷贝(缺陷)
#include <iostream> 
#include <cstring>
using namespace std;

class String {
public:
  char* c_str() {return m_str;}
  void inpt(const char* str) {
    strcpy(m_str, str);
  }
  String (const char* str) : m_str(new char[strlen(str)+1]){ // 为const类型,要初始化空间 
    strcpy(m_str,str);
  }
  // 拷贝构造函数
  String (const String& that): m_str(that.m_str) {
    
  }
  ~String(/*String * this*/) {
    delete [] this->m_str; // c++中一般用 new+delete
  }
private:
  char* m_str;
};

int main( void ) {
    String a("apple");

    /**
     * 在普通拷贝函数中,出现浅拷贝
     * a,b 指向内容一样了,因为只拷贝了地址,没有拷贝指向的内容
     * a析构了b同时也会析构
     */
    String b(a); 
    cout<<a.c_str()<<endl;
    cout<<b.c_str()<<endl;
    a.inpt("i am  Apple");
    cout<<a.c_str()<<endl;
    cout<<b.c_str()<<endl;

    return 0;
} 
// s1.~String() s2.~String() s3.~String()   释放s1/s2/s3本身所占内存空间




