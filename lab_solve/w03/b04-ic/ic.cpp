/*
LANG: C++
TASK: ic
*/
#include <iostream>

using namespace std;

namespace nodeOpt
{
typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
	Node(int val=0, Node *next=0, Node *prev=0)
		: val(val), next(next), prev(prev) {}
} Node;

bool isEmpty(Node *node);

Node *newHeadDoublyCircularLinkedList(int val=0)
{
	if (val==0){
		Node *N = new Node(val);
		N->next = N;
		N->prev = N;
		return N;
	}
	else
	{
		Node *N = new Node(val);
		Node *Header = new Node(0,N,N);
		N->next = Header;
		N->prev = Header;
		return Header;
	}
}

void insertLast(Node *headNode,Node *insertNode)
{
	Node *headLast = headNode->prev;
	Node *insertLast = insertNode->prev;
	Node *insertFirst = insertNode->next;
	insertLast->next = headNode;
	insertFirst->prev = headLast;
	headLast->next = insertFirst;
	headNode->prev = insertLast;
	delete insertNode;
}

void printInfo(Node *node)
{
	if (isEmpty(node))
	{
		cout <<endl;
		return;
	}
	Node *nowNode = node;
	while (nowNode->val != 0)
		nowNode = nowNode->next;
	nowNode = nowNode->next;
	while (nowNode->val != 0)
	{
		cout << nowNode->val << endl;
		nowNode = nowNode->next;
	}
}

void reverseList(Node *node)
{
	if (isEmpty(node))
		return;
	Node *nowNode = node;
	while (nowNode->val != 0)
		nowNode = nowNode->next;
	do
	{
		Node *next = nowNode->next;
		Node *prev = nowNode->prev;
		nowNode->next = prev;
		nowNode->prev = next;
		nowNode = next;
	} while (nowNode->val != 0);
}

void deleteAfter(Node *node,int val)
{
	if (isEmpty(node))
		throw "list is empty";
	Node *nowNode = node->next;
	while (nowNode->val != val)
	{
		if (nowNode->val == 0)
			return;
		else
			nowNode = nowNode->next;	
	}
	if (nowNode->next == node)
		return;
	Node *deleteNode = nowNode->next;
	nowNode->next = node;
	node->prev = nowNode;
	nowNode = deleteNode;
	do
	{
		deleteNode = nowNode->next;
		delete nowNode;
		nowNode = deleteNode;
	} while (deleteNode->val != 0);
}

void insertFirst(Node *headNode,Node *insertNode)
{
	Node *headFirst = headNode->next;
	Node *insertLast = insertNode->prev;
	Node *insertFirst = insertNode->next;
	headNode->next = insertFirst;
	insertFirst->prev = headNode;
	insertLast->next = headFirst;
	headFirst->prev = insertLast;
	delete insertNode;
}

void deleteAt(Node *node,int val)
{
	if (isEmpty(node))
		throw "list is empty";
	Node *nowNode = node->next;
	while (nowNode->val != 0)
		nowNode = nowNode->next;
	nowNode = nowNode->next;
	while (nowNode->val != val)
	{
		if (nowNode->val == 0)
			return;
		else
			nowNode = nowNode->next;
	}
	nowNode->prev->next = nowNode->next;
	nowNode->next->prev = nowNode->prev;
	delete nowNode;
}

bool isEmpty(Node *node) {return (node->next==node && node->prev==node);}

void append(Node *headNode,int val)
{
	Node *headLast = headNode->prev;
	Node *appendNode = new Node(val);
	headLast->next = appendNode;
	appendNode->prev = headLast;
	appendNode->next = headNode;
	headNode->prev = appendNode;
}

void insertAfter(Node *headNode,Node *insertNode,int val)
{
	Node *nowNode = headNode;
	while (nowNode->val != val)
		nowNode = nowNode->next;
	Node *nextNode = nowNode->next;
	Node *insertLast = insertNode->prev;
	if (insertNode->val == 0)
	{
		nowNode->next = insertNode->next;
		insertNode->next->prev = nowNode;
		nextNode->prev = insertLast;
		insertLast->next = nextNode;
		insertNode = (insertNode->next);
	}
	else 
	{
		nowNode->next = insertNode;
		insertNode->prev = nowNode;
		nextNode->prev = insertLast;
		insertLast->next = nextNode;
	}
}

Node *copyNode(Node *A)
{
	Node *nowA = A;
	Node *B = newHeadDoublyCircularLinkedList();
	if (nowA->val == 0)
		nowA = nowA->next;
	while (nowA->val != 0)
	{
		append(B,nowA->val);
		nowA = nowA->next;
	}
	return B;
}

bool isMember(Node *A, int val)
{
	Node *list = A->next;
	while (list->val != 0)
	{
		if (list->val == val)
			return true;
		list = list->next;
	}
	return false;
}

void lastToFirst(Node *A)
{
	Node *first = A->next;
	Node *last = A->prev;
	last->prev->next = A;
	A->prev = last->prev;
	last->next = first;
	first->prev = last;
	last->prev = A;
	A->next = last;
}

void firstToLast(Node *A)
{
	Node *first = A->next;
	Node *last = A->prev;
	first->next->prev = A;
	A->next = first->next;
	first->next = A;
	A->prev = first;
	last->next = first;
	first->prev = last;
}
}


nodeOpt::Node *icArray = nodeOpt::newHeadDoublyCircularLinkedList();

int main()
{
    ios::sync_with_stdio(false);
    int optNum,icNum,temp;
    char in[2];
    cin >> optNum;
    while (optNum --> 0)
    {
        cin >> in;
        switch (in[1])
        {
        case 'i':
            cin >> icNum;
            switch (in[0])
            {
                case 'l':
                    nodeOpt::insertFirst(icArray,nodeOpt::newHeadDoublyCircularLinkedList(icNum));
                    break;
                case 'r':
					nodeOpt::insertLast(icArray,nodeOpt::newHeadDoublyCircularLinkedList(icNum));
                    break;
            }
            break;
        case 'r':
            switch (in[0])
            {
                case 'l':
					// temp = icArray->prev->val;
					// nodeOpt::deleteAt(icArray,temp);
					// nodeOpt::insertFirst(icArray,nodeOpt::newHeadDoublyCircularLinkedList(temp));
					nodeOpt::firstToLast(icArray);
                    break;
                case 'r':
					// temp = icArray->next->val;
					// nodeOpt::deleteAt(icArray,temp)
					nodeOpt::lastToFirst(icArray);
                    break;
            }
            break;
        }
    }
	//nodeOpt::reverseList(icArray);
	nodeOpt::printInfo(icArray);
}