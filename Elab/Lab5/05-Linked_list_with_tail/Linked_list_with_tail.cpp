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
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
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

void LinkedList::append(valueType x)
{
  ListNode* res = new ListNode(x);
  tail->next = res;
  tail = tail->next;
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
  LinkedList list;
  int t;

  cin >> t;
  for(int i = 0; i < t; i++) {
    int dir, val;
    cin >> dir >> val;
    if(dir == 1) {
      list.insert_front(val);
    } else {
      list.append(val);
    }
  }
  list.print_list();
}

