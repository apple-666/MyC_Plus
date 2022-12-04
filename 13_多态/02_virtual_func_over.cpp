/*
virtual 虚函数形成覆盖
在公共基类使用virtual 那子类同名func会默认带上virtual,形成覆盖关系 
*/

#include <iostream> 
using namespace std;

class Shape {
public:
    virtual void Draw( ) {  cout << "Shape::Draw" << endl;  }
    int m_x;
    int m_y;
};
class Rect : public Shape {
public:
    void Draw( ) {  cout << "Rect::Draw" << endl;   } 
    int m_rx;
    int m_ry;
};
class Circle : public Shape {
public:
    void Draw( ) {  cout << "Circle::Draw" << endl; }
    void foo( ) {}
    int m_radius;
};
// 以上代码模拟的是类的设计者(例如: 类库、别人设计的类、自己设计的类)
// ---------------------------------------
// 以下代码模拟的是用户
int main( void ) {
    cout << "----利用 对象 调用 非虚的成员函数----" << endl;
    // 哪个类对象 就调用 哪个类的 普通成员函数(对象的子恰性)
    Shape s;
    s.Draw( ); // Shape::Draw
    Rect r;
    r.Draw( ); // Rect::Draw
    Circle c;
    c.Draw( ); // Circle::Draw
    cout << "----利用 指针 调用 非虚的成员函数----" << endl;
    
    /*
      使用了virtual
      在公共基类使用:指针指向的对象的类型 来确定调用哪个类 虚成员函数
    */
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    return 0;
}





