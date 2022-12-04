/**
 * ��������� +
*/

#include<iostream>
using namespace std;

class Human {
public:
  Human(int t_age,const char* t_name):age(t_age),name(t_name){

  }
  void getinfo(){
    cout<<"name:"<<name<<" age:"<<age<<endl;
  }

  // д��һ:
    // Human operator+(const Human& t) {
  //   return Human(t.age+this->age,(this->name+"+"+t.name).c_str());
  // }
private:
  int age;
  string name;

  //����Ԫ�����ܷ����ڲ�˽�б���
  // ������Ԫ����
  friend Human operator+(const Human& t,const Human& t2);
};
Human operator+(const Human& t,const Human& t2) {
  return Human(t.age+t2.age,(t2.name+"+"+t.name).c_str());
}

int main() {
  Human a(22,"apple");
  Human b(33,"pear");
  Human c = a+b;
  c.getinfo();
  return 0;
}