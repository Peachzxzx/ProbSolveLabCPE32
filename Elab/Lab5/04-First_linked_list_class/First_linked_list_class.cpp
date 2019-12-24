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
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
}

LinkedList::~LinkedList()
{
  free_list();
}

void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::insert_front(valueType x)
{
  ListNode* res = new ListNode(x);
  res->next = header->next;
  header->next = res;
}

void LinkedList::free_list()
{
  ListNode* res = header->next;
  ListNode* nexts;
  while(res!=NULL){
    nexts = res->next;
    delete res;
    res = nexts;
  }
}

main()
{
  LinkedList list;
  for(int i=0; i<10; i++) {
    list.insert_front(i);
  }
  list.print_list();
}