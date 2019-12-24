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

  bool is_empty();
};

bool LinkedList::is_empty()
{
  return (header==tail);
}

main()
{
  LinkedList l1,l2;
  int t;

  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_front(10);
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_front(100);
  cout << (l1.is_empty() ? "yes" : "no") << endl;

  cout << (l2.is_empty() ? "yes" : "no") << endl;
  l2.append(100);
  cout << (l2.is_empty() ? "yes" : "no") << endl;
  l2.append(1000);
  cout << (l2.is_empty() ? "yes" : "no") << endl;
}

