#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

main()
{
  ListNode* n1 = new ListNode(10);
  ListNode* n2 = new ListNode(7);
  ListNode* n3 = new ListNode(20);
  ListNode* n4 = new ListNode(32);
  ListNode* n5 = new ListNode(1);

  n2->next = n1;
  n1->val = 32;
  n3->next = n2;
  n2->val = 20;
  n4->next = n3;
  n3->val = 10;
  n5->next = n4;
  n4->val = 7;
  n5->val = 1;

  ListNode* p = n5;
  while(p!=0) {
    cout << p->val << endl;
    p = p->next;
  }
}