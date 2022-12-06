/*
ģ���ͳ�Ա����: ��ģ����ĳ�Ա������ ������ģ�嶨���
*/

#include <iostream>
using namespace std;

template <class T>
class Array
{
public:
  T m_arr[10];
  T &operator[](int i) { return m_arr[i]; }
};

template <class T2>
class Sum
{
public:
  Sum(Array<T2>& s):m_s(s){} //����
  T2 value(){
    T2 sum = 0;
    for(int i=0; i<10; i++) sum+=m_s[i];
    return sum;
  }
private:
  Array<T2> m_s; // ģ���ͳ�Ա����
};

int main(){
  Array<int> a1; // a1������[10]
  for(int i=0; i<10; i++) a1[i] = i;
  Sum<int> s1(a1);
  cout<<s1.value()<<endl;
  return 0;
}