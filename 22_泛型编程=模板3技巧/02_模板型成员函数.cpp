/*
ģ���ͳ�Ա����: ��ģ����ĳ�Ա������ ��������ģ�嶨��� ����ģ�����к���ģ�壩
*/
#include <iostream>
using namespace std;

template <class T>
class One
{
public:
  // ģ���ͳ�Ա���� = ����ģ�� (ֱ�Ӷ���)
  // template <class T2>
  // void coutt()
  // {
  //   cout << "template<T> template<T2>����ģ��" << endl;
  // }

  // �ⲿ����
  template <class T2>
  void coutt();
};

// �ⲿ����
template <class T>
template <class T2>
void One<T>::coutt()
{
  cout << "template<T> template<T2>����ģ��" << endl;
}

int main()
{

  One<int> o;
  o.coutt<float>();
  return 0;
}