/*
��ģ��: Ҳ�ж�Ӧ�ľ�̬��Ա
��ģ��  -��1  -��1����a    (��1���ж�����̬��Դ)
             -��1����b
        -��2  -��2����a   (��2���ж�����̬��Դ)
             -��2����b
}
*/
#include <iostream>
using namespace std;

template <class T>
class AppleL
{
public:
  static void print()
  {
    cout << "s_i :" << s_i << ", i :" << i;
    // �õ�ַ֤�� ������õ���ͬһ����̬����
    cout << "   s_i��ַ:" << &s_i << ", i��ַ:" << &i << endl;
  }
  static int s_i;
  static T i;
};

// ��̬��Դһ��Ҫ��ǰ��ֵ
template <class T> int AppleL<T>::s_i=100;
template <class T> T AppleL<T>::i = 200; 

int main()
{
  AppleL<int> x, y;
  x.print();
  y.print();
  AppleL<int>::print();

  cout<<"�಻ͬ ��ַ��ͬ"<<endl;
  AppleL<float> x2, y2;
  x2.print();
  y2.print();
  AppleL<float>::print();
  return 0;
}