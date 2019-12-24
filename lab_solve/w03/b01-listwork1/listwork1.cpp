/*
LANG: C++
TASK: listwork1
*/
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

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
  LinkedList();
  valueType get_front();
  void delete_front();
  void deleteAt(valueType x);
  bool is_empty();
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}
void LinkedList::append(valueType x)
{
  ListNode* res = new ListNode(x);
  tail->next = res;
  tail = tail->next;
}

valueType LinkedList::get_front()
{
  return (header->next->val);
}

bool LinkedList::is_empty()
{
  return (header==tail);
}

void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::delete_front()
{
  if(is_empty()) {
    throw "Error: list is empty.";
  }
  ListNode* front = header->next;
  header->next = front->next;
  tail = header;
  while (tail->next!=0)
    tail = tail->next;
  delete front;
}

void LinkedList::deleteAt(valueType x){
  ListNode* now = header;
  for (int i = 0 ; i<x-1;++i){
    if(now->next==0)
      return;
    else
    {
      now = now->next;
    }
  }
  ListNode* res = now->next;
  if (now->next == 0){
    
  } else {
    now->next = now->next->next;
  }
  delete res;
}
void LinkedList::insert_front(valueType x)
{
  ListNode* res = new ListNode(x);
  res->next = header->next;
  header->next = res;
  if (tail->next!=NULL){
    tail = tail->next;
  }
}
main()
{
  LinkedList l1;
  int count;
  char a;
  int b;
  cin >> count;
  for (int i = 0;i<count;++i){
      cin>>a>>b;
      switch (a)
      {
      case 'I':
        l1.insert_front(b);
        break;
      case 'D':
        l1.deleteAt(b);
        break;
      }
  }
  l1.print_list();
}

