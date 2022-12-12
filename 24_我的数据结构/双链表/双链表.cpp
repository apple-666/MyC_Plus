/*
 * ˫����  Node(���ݳ�Ա+ǰ��ָ��)
   ����(��Ĭ�ϲ�����)
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
  // ListNode *head=nullptr; // ���븳ֵ��
  ListNode *head1 = new ListNode; // ���븳ֵ��

  // ѭ����ͷ�ڵ�ǰ�ӽڵ�
  for (int i = 1; i < 6; i++)
  {
    ListNode *node = new ListNode(1,nullptr,head1);
    head1->prev = node;
    head1 = node;
  }
  // ��ͷ��ӡ�ڵ�
  ListNode *ptr = head1;
  cout << "����1 ͷ�ڵ�ǰ����:";
  while (ptr)
  {
    cout << ptr->value;
    ptr = ptr->next;
    if (ptr)
      cout << " -> ";
  }

  cout << endl<< "����1 ����+�������:";
  ListNode *ptr3 = head1;
  bool zdir = true; // ���������
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

  ListNode *head2 = new ListNode; // ���븳ֵ��

  // ѭ����ͷ�ڵ��ӽڵ�
  for (int i = 1; i < 6; i++)
  {
    ListNode *node = new ListNode(2,head2,head2->next);
    // 0 -> 1  
    head2->next = node;
    if(node->next)  node->next->prev = node;
  }

  // ��ͷ��ӡ�ڵ�
  cout << endl
       << "����2 ͷ�ڵ�����:";
  ListNode *ptr2 = head2;
  while (ptr2)
  {
    cout << ptr2->value;
    ptr2 = ptr2->next;
    if (ptr2)
      cout << " -> ";
  }

  cout << endl<< "����2 ����+�������:";
  ListNode *ptr4 = head2;
  bool zdir2 = true; // ���������
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
