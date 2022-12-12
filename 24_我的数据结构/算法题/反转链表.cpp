/*
 * ������  Node(���ݳ�Ա+ָ��) 
   ����(��Ĭ�ϲ�����)
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
  ListNode *head=nullptr; // ���븳ֵ��

  // ͷ�ڵ�����
  for(int i=5;i;i--) {
    ListNode *node=new ListNode(i);
    if(head) {
      node->next=head;
    }
    head = node;
  }
  // ��ͷ��ӡ�ڵ�
  cout<<"ԭ����:";
  ListNode *ptr = head;

  while(ptr){
    cout<<ptr->value;
    ptr = ptr->next;
    if(ptr) cout<<" -> ";
  }

  // ����ת
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
  cout<<endl<<"����ת:";
  ListNode *t2 = h->next;
  while(t2){
    cout<<t2->value;
    t2 = t2->next;
    if(t2) cout<<" -> ";
  }

  return 0;
}
