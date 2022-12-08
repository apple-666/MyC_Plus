#include<iostream>
#include<set>
using namespace std;

int main(){
  set<int> st;
  st.insert(11);
  st.insert(1);
  st.insert(112);
  st.insert(2);
  for(auto i:st) cout<<i<<" ";
  cout<<endl;
  return 0;
}