/*
����ģ���ж��α���:
1 ���ģ�屾����﷨��
2 ʵ����������ʱ�ٴμ�麯�����﷨

������ʽ�ƶ�: max(1,2) �ƶ�Ϊ max<int>(1,2)
*/
#include <iostream>
using namespace std;

class A
{
public:
  void func()
  {
    cout << "A::func()" << endl;
  }
};

template <typename T>
void foo()
{
  // 1,��ʶ�������Ǵ��ڵ� a,b,func()
  // abc();//error


  // 2,��֪���� ���õķ���Ҫ����
  A a;
  // a.abc();   // error ������
  a.func(); //  ok   ����


  // 3,T���� ��һ�α���ٶ�����
  T t;
  // t.abc();   // �ڶ��α���ʱ��error
  t.func();

  // 4,T���� ���÷������ܳ���<>
  // t.ab<c>(); // ���ǲ��ܳ���<>   error
}

int main(void)
{
  foo<A>();
  return 0;
}
