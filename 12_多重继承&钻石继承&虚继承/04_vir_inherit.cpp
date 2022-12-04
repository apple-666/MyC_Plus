/*
��̳� virtual ��ʶ�� (���� class s:virtual public top)
  1,���Ա�֤��
    1,������������ڻ�۶�����ֻ����һ��
    2,�������������Ա�����м����๲��
���ʵ�֣�
  �м�������ָ��:�����м������׵�ַ�������������׵�ַ��ƫ����
*/


#include <iostream>
using namespace std;

class UpType // ���������
{
public:
  int m_age;
};

class MidType1 : virtual public UpType //�м�����
{
public:
  int m_mid1;
  void setAge(int age){ // ����Ƿ���top�Ķ���
    this->m_age = age; // ָ�����m_age
  }
  int getAge(){
    return this->m_age; // ����Ƿ���top�Ķ���
  }
};

class MidType2 : virtual public UpType
{
public:
  int m_mid2;
  int getAge2(){
    return this->m_age;
  }
};

class DownType : public MidType1, public MidType2 // �������
{
public:
  int m_dow;
  void foo(){
    m_age = 1;
  }
};

int main(){
  DownType down;
  cout<<"��������size��:"<<sizeof(down)<<endl; // size������,����һ���ֽ�
  /*
  �ڴ�ֲ��仯: 
  |m_mid1 + m_up |m_mid2 + m_up |m_down|  
  ->
  |m_mid1 + *this|m_mid2 + *this|m_down|m_up|
  */ 
  
  down.setAge(22);
  cout<<down.getAge()<<endl;
  cout<<down.getAge2()<<endl;
  down.m_age = 1; //error ��̳�û������
  return 0;
}