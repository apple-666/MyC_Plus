// 常对象  与  常函数
/***
 * 常对象： 不可变的对象 const修饰
 * 常函数： function中的thist 有常属性 有const
*/
#include <iostream> 
using namespace std;
class Integer {
public:
    // 普通的非const函数
    void setinfo( /* Integer* this */ int i ) { // 非常函数
        m_i = i; 
    }
    void getinfo( /* Integer* this */ ) { // 非常函数
        cout << "非常函数getinfo:" << m_i << endl;
    }

    // const函数
    // const对象不应该有set的权限，所以不可修改赋值, 硬要修改，就要强制转换成 非常指针
    void setinfo(/* const Integer* this */ int i ) const { // 非常函数
       // 强制转换成 非常指针
       const_cast<Integer*>(this)->m_i = i;
       cout<<"set 常函数"<<endl;
    }
    void getinfo( /* const Integer* this */) const {
        // const_cast<Integer*>(this)->m_i = 11111;
        cout<<"常函数："<< m_i<<endl;
    }
private:
    /*mutable*/ int m_i; // 用mutable也是 编译中常指针转了非常指针
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main( void ) {
    Integer ix; // ix为 非常对象
    ix.setinfo( 8888 );
    ix.getinfo( ); // getinfo( &ix )-->实参类型为 Integer*

    const Integer cix = ix ; // cix为 常对象
    cix.setinfo( 2222 );
    cix.getinfo( ); // getinfo( &cix )-->实参类型为 const Integer*
    return 0;
}



