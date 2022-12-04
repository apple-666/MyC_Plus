/**
 * 容器相关重载:
 *  operator []
 *  非常容器要接收非常对象  常容器用常数据
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
  // 常函数: 只用于常容器 size_t 标准库中的unsigned 类的int
  const int& operator[](size_t idx) const {
    if(idx<size) return data[idx];
    return -1;
  }

  // 非常函数 用了& 就必须返回左值,同时实现了[i]赋值 
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
  cout<<"非常数----------"<<endl;
  cout<<"右值"<<endl;
  cout<<st[0]<<endl;
  cout<<st[1]<<endl;
  cout<<"弹出: "<<st.pop()<<endl;
  cout<<st[0]<<endl;
  cout<<st[1]<<endl;
  cout<<"左值"<<endl;
  int i1 = 0;
  cout<<st[i1]<<endl;

  cout<<"常数-----------"<<endl;
  const int idx = 1;
  cout<<st[idx]<<endl;

  cout<<"[]赋值"<<endl;
  st[1] = 199;
  cout<<st[1]<<endl;

  // 常容器
  cout<<"常容器---------"<<endl;
  const Stack const_st = st;
  cout<<const_st[0]<<endl;
  return 0;
}