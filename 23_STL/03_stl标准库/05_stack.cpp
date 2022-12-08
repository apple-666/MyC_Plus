#include<iostream>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

int main(){

  // deque、list、vector可以作为stack的底层容器.默认是deque
  stack<int,list<int>> s;
  s.push(1);
  s.push(3);
  s.push(111);
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}