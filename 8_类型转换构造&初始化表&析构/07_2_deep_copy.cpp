// 针对指针型变量,用深拷贝解决浅拷贝
#include <iostream> 
#include <cstring>
using namespace std;

class String {
public:
  char* c_str() {return m_str;}
  void inpt(const char* str) {
    strcpy(m_str, str);
  }

  // =""  可以不赋值
  String (const char* str="") : m_str(new char[strlen(str)+1]){ // 为const类型,要初始化空间 
    strcpy(m_str,str);
  }
  // 拷贝构造函数
  String (const String& that):m_str(new char[strlen(that.m_str)+1]) {
    // 加两行: 复制数据 成了深拷贝
    // 1,初始化表 申请空间
    // 2,strcpy 数据内容
    strcpy(m_str,that.m_str);
  }
  // 拷贝赋值函数: 没有初始化表
  String& operator = (const String& that){
    
    if( this!=&that){ // 取消自赋值 (this指针== that的地址)
      delete []m_str; // 先delete 初始的 "\0". 否则会造成内存泄露
      this->m_str = new char[strlen(that.m_str) + 1];
      strcpy(this->m_str,that.m_str);
    }
    // strcpy(this->m_str,that.m_str); //这样不行吗,是的, 因为会造成内存泄露


    // this->m_str = that.m_str; //这行 只复制了指针,没有复制内容,是浅拷贝 (this:String* this  that:是别名,那属性)
    return *this;
  }

  // 析构函数
  ~String(/*String * this*/) {
    delete [] this->m_str; // c++中一般用 new+delete
  }
private:
  char* m_str;
};

int main( void ) {
    String a("apple");

    /**
     * 要用深拷贝情况: 1,拷贝构造时
     */
    String b(a); 
    cout<<a.c_str()<<";a内存地址:"<<(void*)a.c_str()<<endl;
    cout<<b.c_str()<<";b内存地址:"<<(void*)b.c_str()<<endl;
    a.inpt("i am  Apple");
    cout<<a.c_str()<<";a内存地址:"<<(void*)a.c_str()<<endl;
    cout<<b.c_str()<<";b内存地址:"<<(void*)b.c_str()<<endl;

    /**
     * 2, 拷贝赋值时
     * 
     */
    String c; //构造中是 ="" 维护了一个"\0"
    c = b;
    cout<<b.c_str()<<";在拷贝赋值中 b内存地址:"<<(void*)b.c_str()<<endl;
    cout<<c.c_str()<<";在拷贝赋值中 c内存地址:"<<(void*)c.c_str()<<endl;


    return 0;
} 
// s1.~String() s2.~String() s3.~String()   释放s1/s2/s3本身所占内存空间




