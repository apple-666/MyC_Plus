#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
using namespace std;
int main(){
//    queue<int> q;
//    queue<int,deque<int> > q;
//    queue<int,vector<int> > q;  // ���еĵײ���������ʹ��vector,vector��û��pop_front����
    queue<int,list<int> > q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    while(!q.empty()){
        cout << q.front() << endl; // �����������
        q.pop();  //  ����
    }
    return 0;
}
