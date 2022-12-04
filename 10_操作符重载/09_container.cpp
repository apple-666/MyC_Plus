/**
 * �����������:
 *  operator []
 *  �ǳ�����Ҫ���շǳ�����  �������ó�����
 */ 

#include <iostream>
using namespace std;

class Stack{
public:
  Stack():size(0){}
  void put(int x){
    data[size++] = x;
  }
  int pop(){
    return data[size--];
  }
  // ������: ֻ���ڳ����� size_t ��׼���е�unsigned ���int
  const int& operator[](size_t idx) const {
    if(idx<size) return data[idx];
    return -1;
  }

  // �ǳ����� ����& �ͱ��뷵����ֵ,ͬʱʵ����[i]��ֵ 
  int& operator[](size_t idx){
    return data[idx];
  }
private:
  int size;
  int data[100];
};

int main() {
  Stack st;
  st.put(1);
  st.put(2);
  cout<<"�ǳ���----------"<<endl;
  cout<<"��ֵ"<<endl;
  cout<<st[0]<<endl;
  cout<<st[1]<<endl;
  cout<<"����: "<<st.pop()<<endl;
  cout<<st[0]<<endl;
  cout<<st[1]<<endl;
  cout<<"��ֵ"<<endl;
  int i1 = 0;
  cout<<st[i1]<<endl;

  cout<<"����-----------"<<endl;
  const int idx = 1;
  cout<<st[idx]<<endl;

  cout<<"[]��ֵ"<<endl;
  st[1] = 199;
  cout<<st[1]<<endl;

  // ������
  cout<<"������---------"<<endl;
  const Stack const_st = st;
  cout<<const_st[0]<<endl;
  return 0;
}