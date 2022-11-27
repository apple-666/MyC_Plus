#include "Human.hpp"
#include <iostream>

using namespace std;

Human::Human(int age,const char* name) {
  cout<<"构造"<<endl;
}
// 在方法名之前加 Human::
void Human::getinfo() {
  cout<<"getINFO()"<<endl;
}