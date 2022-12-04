/*
virtual �麯���γɸ���
�ڹ�������ʹ��virtual ������ͬ��func��Ĭ�ϴ���virtual,�γɸ��ǹ�ϵ 
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
// ���ϴ���ģ�������������(����: ��⡢������Ƶ��ࡢ�Լ���Ƶ���)
// ---------------------------------------
// ���´���ģ������û�
int main( void ) {
    cout << "----���� ���� ���� ����ĳ�Ա����----" << endl;
    // �ĸ������ �͵��� �ĸ���� ��ͨ��Ա����(�������ǡ��)
    Shape s;
    s.Draw( ); // Shape::Draw
    Rect r;
    r.Draw( ); // Rect::Draw
    Circle c;
    c.Draw( ); // Circle::Draw
    cout << "----���� ָ�� ���� ����ĳ�Ա����----" << endl;
    
    /*
      ʹ����virtual
      �ڹ�������ʹ��:ָ��ָ��Ķ�������� ��ȷ�������ĸ��� ���Ա����
    */
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    return 0;
}





