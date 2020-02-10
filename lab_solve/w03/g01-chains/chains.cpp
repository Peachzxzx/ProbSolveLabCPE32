/*
LANG: C++
TASK: chains
*/
#include <stdio.h>

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
	Node *headFirst = headNode->next;
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
	if (isEmpty(node)){
		printf("");
		return;
	}
	Node *nowNode = node;
	while (nowNode->val != 0)
	{
		nowNode = nowNode->next;
	}
	nowNode = nowNode->next;
	while (nowNode->val != 0)
	{
		printf("%d",nowNode->val);
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
		;
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
	Node *headLast = headNode->prev;
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
		;
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

void insertAfter(Node **headNode,Node **insertNode,int val)
{
	Node *nowNode = (*headNode);
	while (nowNode->val != val)
	{
			nowNode = nowNode->next;
	}
	Node *nextNode = nowNode->next;
	Node *insertLast = (*insertNode)->prev;
	Node *insertFirst;
	if ((*insertNode)->val == 0){
		nowNode->next = (*insertNode)->next;
		(*insertNode)->next->prev = nowNode;
		nextNode->prev = insertLast;
		insertLast->next = nextNode;
		(*insertNode) = ((*insertNode)->next);
	}
	else 
	{
		nowNode->next = (*insertNode);
		(*insertNode)->prev = nowNode;
		nextNode->prev = insertLast;
		insertLast->next = nextNode;
		(*insertNode) = ((*insertNode));
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
}

namespace nodeArray
{
typedef struct Array
{
    nodeOpt::Node *list;
    int index;
	Array *next;
	Array *prev;
	Array(int index, nodeOpt::Node *list=0, Array *next=0, Array *prev=0)
		: index(index), list(list), next(next), prev(prev) {}
} Array;

Array *newArray(int index=0)
{
    Array *Header = new Array(0);
    if (index==0){
        Header->next = Header;
        Header->prev = Header;
    }
    else
    {
        Array *A = new Array(index);
        A->next = Header;
        A->prev = Header;
        Header->prev = A;
        Header->next = A;  
    }
    return Header;
}

nodeOpt::Node *nodePosition(Array *A, int val)
{
	Array *nowAt = A->next;
    while (nowAt->index != 0)
    {
        nodeOpt::Node *listNow = nowAt->list->next;
        do
        {
            if (listNow->val == val)
                return listNow;
            else
                listNow = listNow->next;
        } while (listNow->val != 0);
        nowAt = nowAt->next;
    }
	return nodeOpt::newHeadDoublyCircularLinkedList();
}

void printArray(Array *A)
{
	Array *nowAt = A->next;
    for (int i=1;i<=(A->prev->index);i++)
    {
        printf("%d | ",i);
        nodeOpt::printInfo(nowAt->list);
		printf("\n");
        nowAt = nowAt->next;
    }
}

void appendArray(Array *headArray)
{
    int mostIndex = headArray->prev->index;
    Array *headLast = headArray->prev;
	Array *appendNode = new Array(++mostIndex);
	headLast->next = appendNode;
	appendNode->prev = headLast;
	appendNode->next = headArray;
	headArray->prev = appendNode;
}
}

main()
{
    nodeOpt::Node *Result = nodeOpt::newHeadDoublyCircularLinkedList();
    nodeOpt::Node *Position = Result;
	nodeOpt::Node *PositionArray = nodeOpt::newHeadDoublyCircularLinkedList();
	int N, loop, length,count = 1;
    char command;
	scanf("%d %d",&N,&loop);
    nodeArray::Array *listArray = nodeArray::newArray();
    nodeArray::Array *nowAt = listArray;
    for (int i=0; i<N;i++)
    {
        nodeArray::appendArray(listArray);
        nowAt = nowAt->next;
        scanf(" %d",&length);
        nowAt->list = nodeOpt::newHeadDoublyCircularLinkedList();
        nodeOpt::Node *listNow = nowAt->list;
        for (int i=0;i<length;i++)
		    nodeOpt::append(listNow,count++);
    }
	nodeArray::Array *nowAtArray = listArray->next;
	nodeOpt::Node *posInArray = nowAtArray->list->next;
	for (int i=1;i<=listArray->next->list->prev->val;i++)
		nodeOpt::append(Result,i);
	Position = Result->next;
	nodeOpt::append(PositionArray,Position->val);
	int v;
	for (int i=0;i<loop;i++)
	{
		scanf(" %c",&command);
        switch (command)
        {
        case 'B':
            if (Position->prev->val != 0)
			{
				Position = Position->prev;
				nodeOpt::append(PositionArray,Position->val);
			}
            break;
        case 'F':
            if (Position->next->val != 0)
			{
				Position = Position->next;
				nodeOpt::append(PositionArray,Position->val);
			}
            break;
        case 'C':
			scanf(" %d",&v);
            nodeOpt::Node *memPos = nodeArray::nodePosition(listArray,v);
			nodeOpt::deleteAfter(Result,Position->val);
			nodeOpt::Node *copy = nodeOpt::copyNode(memPos);
			nodeOpt::Node *copyhead = copy;
			while (copyhead->val != 0)
				copyhead = copyhead->next;
			copyhead = copyhead->next;
			while (copyhead->val != 0)
			{
				if (nodeOpt::isMember(Result,copyhead->val))
				{
					nodeOpt::Node *del = copyhead;
					copyhead = copyhead->next;
					nodeOpt::deleteAt(Result,del->val);
				}
				else
					copyhead = copyhead->next;
			}
			nodeOpt::insertLast(Result,copy);
			Position = Position->next;
			nodeOpt::append(PositionArray,Position->val);
            break;
        }
	}
	nodeOpt::printInfo(PositionArray);
}