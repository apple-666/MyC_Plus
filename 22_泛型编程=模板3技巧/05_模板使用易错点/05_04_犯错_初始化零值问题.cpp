/*
������ ��Ĭ�ϵĹ����ʼ��ֵ
�������� û��

���������
  T t = T(); ʹ��ȱʡ��ʼ�� ��������:Integer() �ù���
                             ��������:int()   Ĭ�ϳ�ʼ��
*/

#include <iostream>
using namespace std;

class Integer{
  public:
    Integer():m_i(100){}
  private:
    int m_i;
    friend ostream& operator<<(ostream& os,Integer const& i);
};

ostream& operator<<(ostream& os,Integer const& i)
{
  os<<i.m_i;
  return cout;
}
template<class T> 
void print(){
  // T t; ��������
  T t = T(); // ȱʡ��ʼ��
  cout<<t<<endl;
}

int main()
{
  print<int>();   // û�г�ʼ��
  print<double>(); // û�г�ʼ��
  print<Integer>(); // �����г�ʼ��

  return 0;
}