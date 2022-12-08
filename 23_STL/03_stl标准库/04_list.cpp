#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void print(const char* msg,list<int>& ls){
  cout<<msg<<endl;
  for(auto const& i:ls){
    cout<<i<<" ";
  }
  // list������������[]
  // for(int i=0;i<ls.size();i++) {
  //   cout<<ls[i]<<" ";
  // }
  cout<<endl;
}

int main(){

  list<int> ls;
  for(int i=0;i<5;i++) ls.push_front(i);
  for(int i=0;i<5;i++) ls.push_back(100+i);
  print("�����β�ڵ�",ls);

  ls.insert(ls.begin(),4); // listû������ it+n
  print("�����:",ls);

  ls.unique();
  print("Ψһ����(�������ݲ��ظ�)",ls);

  ls.remove(0);
  print("ɾ��ָ�����ݺ�",ls);

  ls.sort();
  print("����",ls);

  ls.sort(greater<int>());
  print("greater�����",ls);

  return 0;
}