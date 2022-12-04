#include <iostream> 
using namespace std;
// 没有虚函数的世界
// 父子类有重名func时
class Shape {
public:
    void Draw( ) {  cout << "Shape::Draw" << endl;  }
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
      利用 基类类型指针 只能调用 基类的普通成员函数
      即便 基类类型指针 指向的为子类对象,调用的也为基类的普通成员函数
      总结: 当利用指针调用普通成员函数时, 编译器 简单粗暴的 根据指针的类型 来确定调用哪个类 普通成员函数
    */
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    // 一旦调用 子类所特有普通成员函数 将引发编译错误
//  ps->foo( ); // error
    return 0;
}





