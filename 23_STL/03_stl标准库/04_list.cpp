#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void print(const char* msg,list<int>& ls){
  cout<<msg<<endl;
  for(auto const& i:ls){
    cout<<i<<" ";
  }
  // list是链表不允许用[]
  // for(int i=0;i<ls.size();i++) {
  //   cout<<ls[i]<<" ";
  // }
  cout<<endl;
}

int main(){

  list<int> ls;
  for(int i=0;i<5;i++) ls.push_front(i);
  for(int i=0;i<5;i++) ls.push_back(100+i);
  print("添加首尾节点",ls);

  ls.insert(ls.begin(),4); // list没有重载 it+n
  print("插入后:",ls);

  ls.unique();
  print("唯一化后(相邻数据不重复)",ls);

  ls.remove(0);
  print("删除指定数据后",ls);

  ls.sort();
  print("升序",ls);

  ls.sort(greater<int>());
  print("greater降序后",ls);

  return 0;
}