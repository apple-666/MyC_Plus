/*
��ģ�壺 �ص㣺�ֲ���ɹ���
  ֻ��ʹ���� ʵ����,��Ա����,����
  ��Ӧ�Ĺ���,��Ա����,�����Żᱻ��ӽ���ģ��

}
*/
#include <iostream>
using namespace std;

class Integer
{
public:
  Integer(const int &i2 = 1) : i1(i2) {}
  Integer operator+(Integer that)
  {
    return that.i1 + i1;
  }
  int i1;
};

template <class T>
class AppleL
{
public:
  AppleL(const T &a1, T const &a2) : m1(a1), m2(a2) {}
  // T add(){
  //   return m1 + m2;
  // }

  // �����ⲿ����
  T add();

private:
  T m1;
  T m2;
};

template <class T>
T AppleL<T>::add()
{
  return m1 + m2;
}
// class AppleL<int> {} ���������ʵ��

int main()
{

  Integer i1(1);
  Integer i2(2);
  AppleL<Integer> ai(i1, i2);
  ai.add();
  return 0;
}