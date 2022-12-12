/*
 * 单链表：  Node(数据成员+指针) 
 */
#include <iostream>
using namespace std;

struct ListNode
{
  double value;
  ListNode *next;
};

int main()
{
  // head
  ListNode *head = nullptr;
  head = new ListNode();
  head->value = 1;
  head->next = nullptr;
  ListNode *node2 = new ListNode();
  node2->value = 2;
  node2->next = nullptr;
  head->next = node2;
  ListNode *node3 = new ListNode();
  node3->value = 3;
  node3->next = nullptr;
  node2->next = node3;

  cout << head->value << " -> " << head->next->value << " -> " << head->next->next->value << endl;
  return 0;
}
