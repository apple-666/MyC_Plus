/*
��ʯ�̳�
�����㣺
  ��������
  ����м�����
  �������
���ڵ����⣺�ڻ���������ж����������
������::�����޶����Ž��,�����Ƽ�
��Ϊ,�е�ҵ�񹫹�����ı���Ӧ����ͳһ��
�������: ��̳�
*/

#include <iostream>
using namespace std;

class UpType // ��������
{
public:
  int m_up;
};

class MidType1 : public UpType //�м�����
{
public:
  int m_mid1;
};

class MidType2 : public UpType
{
public:
  int m_mid2;
};

class DownType : public MidType1, public MidType2 // �������
{
public:
  int m_dow;
};

int main(){
  DownType down;
  cout<<"��ײ�class:��size:"<<sizeof(down)<<endl;
  // �ڴ�ֲ�: |m_mid1 + m_up|m_mid2 + m_up|m_down|
  // 20 = 4*5 = down + (mid1+top) + (mid2+top)
   
  // down.m_up = 1; //error
  down.MidType1::m_mid1 = 1;
  down.MidType1::m_up = 1;
  return 0;
}