#include <iostream> 
using namespace std;
// û���麯��������
// ������������funcʱ
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
      ���� ��������ָ�� ֻ�ܵ��� �������ͨ��Ա����
      ���� ��������ָ�� ָ���Ϊ�������,���õ�ҲΪ�������ͨ��Ա����
      �ܽ�: ������ָ�������ͨ��Ա����ʱ, ������ �򵥴ֱ��� ����ָ������� ��ȷ�������ĸ��� ��ͨ��Ա����
    */
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    // һ������ ������������ͨ��Ա���� �������������
//  ps->foo( ); // error
    return 0;
}





