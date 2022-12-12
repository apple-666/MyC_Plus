/*
 * ������  Node(���ݳ�Ա+ָ��) 
   ����(��Ĭ�ϲ�����)
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
  ListNode *head=nullptr; // ���븳ֵ��

  // ѭ����ͷ�ڵ�ǰ�ӽڵ�
  for(int i=1;i<6;i++) {
    head = new ListNode(i,head);
  }

  // ѭ����β�ڵ��ӽڵ�
  ListNode *tail = head; 
  while(tail->next){ // ���ҵ�β���Ľڵ�
    tail = tail->next;
  }
  for(int i=-1;i>-6;i--){
    tail->next = new ListNode(i);
    tail= tail->next;
  }

  // ��ͷ��ӡ�ڵ�
  ListNode *ptr = head;
  while(ptr){
    cout<<ptr->value;
    ptr = ptr->next;
    if(ptr) cout<<" -> ";
  }

  return 0;
}
