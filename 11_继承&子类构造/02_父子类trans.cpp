/*

*/
#include <iostream>
using namespace std;

class Base
{
public:
  int m_a;
  void foo() { cout << "Base::foo" << endl; }

protected:
  int m_b;
  void bar() { cout << "Base::bar" << endl; }

private:
  int m_c;
  void hum() { cout << "Base::hum" << endl; }
};

class Son :public Base
{
public:
  void fun()
  {
  }

private:
  int m_d;
};

int main()
{
  Son son;
  // ����ת���� ��Χ��С(��Ϊ��������>=��������) ��������ʽת��
  Base far = son;
  // ����ָ��ת����ָ�� ��Χ��С(��Ϊ��������>=��������) ��������ʽת��
  Base* farr = &son;
  Base& farrr = son;

  // ָ�뱾��ֻռ4�ֽ�,ָ������;�����ָ����۽�(�������͵��ֽ�)�Ͳ���(+1 = +n�ֽ�)
  // ����ת���� Ҫǿ��ת�� 
  Base* far2 = &son;
  Base& far3 = son;
  Son* son2 = static_cast<Son*>(far2);
  Son& son3 = static_cast<Son&>(far3);
  return 0;
}
