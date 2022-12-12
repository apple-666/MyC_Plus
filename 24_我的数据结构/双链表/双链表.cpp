/*
 * 双链表：  Node(数据成员+前后指针)
   构造(加默认参数的)
 */
#include <iostream>
using namespace std;

struct ListNode
{
  double value;
  ListNode *prev;
  ListNode *next;
  ListNode(const double &value1 = 0, ListNode *prev1 = nullptr, ListNode *next1 = nullptr) : value(value1), prev(prev1), next(next1) {}
};

int main()
{
  // head
  // ListNode *head=nullptr; // 必须赋值。
  ListNode *head1 = new ListNode; // 必须赋值。

  // 循环在头节点前加节点
  for (int i = 1; i < 6; i++)
  {
    ListNode *node = new ListNode(1,nullptr,head1);
    head1->prev = node;
    head1 = node;
  }
  // 从头打印节点
  ListNode *ptr = head1;
  cout << "链表1 头节点前插入:";
  while (ptr)
  {
    cout << ptr->value;
    ptr = ptr->next;
    if (ptr)
      cout << " -> ";
  }

  cout << endl<< "链表1 正向+反向遍历:";
  ListNode *ptr3 = head1;
  bool zdir = true; // 先正向后反向
  while (true)
  {
    cout << ptr3->value;
    if (zdir)
    {
      if (!ptr3->next)
      {
        zdir = false;
        ptr3 = ptr3->prev;
      }
      else
      {
        ptr3 = ptr3->next;
      }
    }
    else
    {
      if (!ptr3->prev)
      {
        break;
      }
      else
      {
        ptr3 = ptr3->prev;
      }
    }
    cout << " -> ";
  }

  ListNode *head2 = new ListNode; // 必须赋值。

  // 循环在头节点后加节点
  for (int i = 1; i < 6; i++)
  {
    ListNode *node = new ListNode(2,head2,head2->next);
    // 0 -> 1  
    head2->next = node;
    if(node->next)  node->next->prev = node;
  }

  // 从头打印节点
  cout << endl
       << "链表2 头节点后插入:";
  ListNode *ptr2 = head2;
  while (ptr2)
  {
    cout << ptr2->value;
    ptr2 = ptr2->next;
    if (ptr2)
      cout << " -> ";
  }

  cout << endl<< "链表2 正向+反向遍历:";
  ListNode *ptr4 = head2;
  bool zdir2 = true; // 先正向后反向
  while (true)
  {
    cout << ptr4->value;
    if (zdir2)
    {
      if (!ptr4->next)
      {
        zdir2 = false;
        ptr4 = ptr4->prev;
      }
      else
      {
        ptr4 = ptr4->next;
      }
    }
    else
    {
      if (!ptr4->prev)
      {
        break;
      }
      else
      {
        ptr4 = ptr4->prev;
      }
    }
    cout << " -> ";
  }

  return 0;
}
