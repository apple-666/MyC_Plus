/**
 * class���� ֮���ת��: A -> B
 *  ����һ��(��������)����ת�����캯�� A��дfriend + B��д����Dog(Cat)
 *  ������: ����ת������������ A��д����������
*/

#include<iostream>
using namespace std;

class Dog; // ��ʽ���� ���� Dog�Ǹ�class (����16�е�Dog)

class Cat{
public:
  Cat(const char* name): m_name(name) {}
  // ����ת������������
  operator Dog() const; // ���� ����д����(��Ϊ��û�б��뵽Dog)
  void talk(){
    cout<<"name:"<<m_name<<" ������"<<endl;
  }
private:
  string m_name;
};

class Dog{
public:
  Dog(const char* name):m_name(name) {}

  // ����ת�����캯�� 
  // Dog(const Cat& cat):m_name(cat.m_name) {
  //       cout << "Dog�������ת�����캯��������" << endl;
  // }
  void talk(){
    cout<<"name:"<<m_name<<" ������"<<endl;
  }
private:
  string m_name;
};

Cat::operator Dog()const {
  cout<<"Cat�������ת������������������"<<endl;
  return Dog(this->m_name.c_str());
}

int main(){
  Cat a1("huahua");
  a1.talk();

  /**
   * ����һ:
   *  .Dog(Cat a1) ����ת�����캯�� 
   * ������:
   *  a1.operator Dog() ����ת������������
  */
  Dog a2 = a1; 
  a2.talk();

  return 0;
}
