/*
lambda ���ʽ:
[�����](�βα�)-> ��������{������};
ԭ��:
  1,����һ����
  2,�ඨ��С���Ų�����
  3,���������������
auto f = [](int x,int y)->int {return x>y?x:y;};

class xx{
  public:
    int operator()(int x,int y){
      return x>y?x:y;
    }
};
auto f = xx{}
f(1,2) -> f.operator()(1,2);
*/
#include <iostream>
#include <typeinfo>
using namespace std;

int Max(int x, int y)
{
  return x > y ? x : y;
}

int main(void)
{
  int a = 10, b = 20;
  cout << Max(a, b) << endl;

  auto f = [](int x, int y) -> int
  { return x > y ? x : y; };
  cout << f(10, 20) << endl;
  cout << "f������:" << typeid(f).name() << endl;

  // ��д
  auto f2 = [](int x, int y)
  { return x > y ? x : y; }; // ����ֵʡ��
  cout << f2(10, 20) << endl;
  /*
  ��дԭ��
    class xx{
      public:
        auto operator()(int x,int y) ->decltype(x>y?x:y){
          return x>y?x:y;
        }
    };
  */
  cout <<  [](int x, int y)
  { return x > y ? x : y; }(a,b)<< endl;


  cout<<"lambdaû�з���ֵ��"<<endl;
  auto f3 = [](){cout<<"������һ��-------"<<endl;};
  f3();
  //��д ʡ��()
  auto f4 = []{cout<<"������һ��-------"<<endl;};
  f4();

  return 0;
}
