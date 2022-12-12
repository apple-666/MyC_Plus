/*
 * ������  Node(���ݳ�Ա+ָ��) 
   �ӹ��캯��
   �㷨����ⳣ�õ�д��
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

  // ѭ����ͷ�ڵ�ǰ�ӽڵ�
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
