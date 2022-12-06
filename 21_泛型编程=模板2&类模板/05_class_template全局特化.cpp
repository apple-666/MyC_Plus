/*
ģ����ػ��﷨:
1,ȫ���ػ�
  1.1 ȫ���ػ� �������ػ�
  1.2 ��Ա�ػ� ���������ػ�
2,�ֲ��ػ�


ȫ��
template<>
class AppleL<�ػ�����>{

}

��Ա
template<>
����ֵ���� ���� <���Ͳ���1...>::func��(){}
*/

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class CMath
{
public:
  CMath(T const &t1, T const &t2) : m_t1(t1), m_t2(t2) {}
  T add()
  {
    return m_t1 + m_t2;
  }

private:
  T m_t1;
  T m_t2;
};

// ȫ���ػ�
// template <>
// class CMath<char* const>
// {
// public:
//   CMath<char* const>(char* const& t1, char* const& t2) : m_t1(t1), m_t2(t2) {}
//   char* const add()
//   {
//     return strcat(m_t1, m_t2);
//   }

// private:
//   char* const m_t1;
//   char* const m_t2;
// };

template<> char* const CMath <char* const>::add(){
  return strcat(m_t1, m_t2);
}

int main()
{

  CMath<int> m1(1, 2);
  cout << m1.add() << endl;
  CMath<double> m2(1.1, 2.2);
  cout << m2.add() << endl;

  char c1[10] = "apple", c2[10] = " come";
  CMath<char* const > m3(c1, c2); // const �ɼӿɲ���
  cout<<m3.add()<<endl; // ����ָ��û�����
  return 0;
}