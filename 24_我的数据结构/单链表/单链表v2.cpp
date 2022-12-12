/*
 * 单链表：  Node(数据成员+指针) 
   加构造函数
   算法编程题常用的写法
 */
#include <iostream>
using namespace std;

struct ListNode
{
  double value;
  ListNode *next;
  ListNode(){}
  ListNode(double value1,ListNode *next1):value(value1),next(next1){}
};

int main()
{
  // head
  ListNode *head = nullptr;
  head = new ListNode(1,nullptr);
  ListNode *node2 = new ListNode(2,nullptr);
  head->next = node2;
  ListNode *node3 = new ListNode(3,nullptr);
  node2->next = node3;

  // 循环在头节点前加节点
  for(int i=4;i<10;i++) {
    head = new ListNode(i,head);
  }

  ListNode *ptr = head;
  while(ptr!=nullptr){
    cout<<ptr->value;
    ptr = ptr->next;
    if(ptr!=nullptr) cout<<"->";
  }

  return 0;
}
