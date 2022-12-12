/*
 * 单链表：  Node(数据成员+指针) 
   构造(加默认参数的)
 */
#include <iostream>
#include<vector>
using namespace std;

struct ListNode
{
  double value;
  ListNode *next;
  ListNode(const double &value1=0, ListNode *next1=nullptr):value(value1),next(next1){}
};

int main()
{
  // head
  ListNode *head=nullptr; // 必须赋值。

  // 头节点后插入
  for(int i=5;i;i--) {
    ListNode *node=new ListNode(i);
    if(head) {
      node->next=head;
    }
    head = node;
  }
  // 从头打印节点
  cout<<"原链表:";
  ListNode *ptr = head;

  while(ptr){
    cout<<ptr->value;
    ptr = ptr->next;
    if(ptr) cout<<" -> ";
  }

  // 链表反转
  // 0->1->2
  vector<int> stk;
  ListNode *p = head;
  while(p){
    stk.push_back(p->value);
    p = p->next;
  }
  ListNode *h = new ListNode();
  ListNode *t = h;
  while(stk.size()){
    int v = stk[stk.size()-1];
    stk.pop_back();
    ListNode *node = new ListNode(v);
    t->next = node;
    t = node;
  }
  cout<<endl<<"链表反转:";
  ListNode *t2 = h->next;
  while(t2){
    cout<<t2->value;
    t2 = t2->next;
    if(t2) cout<<" -> ";
  }

  return 0;
}
