#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
using namespace std;
int main(){
//    queue<int> q;
//    queue<int,deque<int> > q;
//    queue<int,vector<int> > q;  // 队列的底层容器不能使用vector,vector中没有pop_front函数
    queue<int,list<int> > q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    while(!q.empty()){
        cout << q.front() << endl; // 输出队首数据
        q.pop();  //  出队
    }
    return 0;
}
