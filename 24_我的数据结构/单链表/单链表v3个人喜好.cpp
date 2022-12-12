/*
 * 单链表：  Node(数据成员+指针) 
   构造(加默认参数的)
 */
#include <iostream>
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

  // 循环在头节点前加节点
  for(int i=1;i<6;i++) {
    head = new ListNode(i,head);
  }

  // 循环在尾节点后加节点
  ListNode *tail = head; 
  while(tail->next){ // 先找到尾部的节点
    tail = tail->next;
  }
  for(int i=-1;i>-6;i--){
    tail->next = new ListNode(i);
    tail= tail->next;
  }

  // 从头打印节点
  ListNode *ptr = head;
  while(ptr){
    cout<<ptr->value;
    ptr = ptr->next;
    if(ptr) cout<<" -> ";
  }

  return 0;
}
