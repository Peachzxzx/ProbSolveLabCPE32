/*
LANG: C++
TASK: mid62_virus
*/
#include <cstdio>
#include <vector>
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
void printInfo(Node *node)
{
	Node *nowNode = node;
	nowNode = nowNode->next;
	while (nowNode->val != 0)
	{
		printf("%d\n",nowNode->val);
		nowNode = nowNode->next;
	}
}
Node *newDoublyCircularLinkedList(int val=0)
{
	if (val==0){
		Node *N = new Node(val);
		N->next = N;
		N->prev = N;
		return N;
	}
	else{
		Node *N = new Node(val);
		Node *Header = new Node(0,N,N);
		N->next = Header;
		N->prev = Header;
		return Header;
	}
}

bool isEmpty(Node *node){return (node->next==node && node->prev==node);}

void append(Node *headNode,int val)
{
	Node *headLast = headNode->prev;
	Node *appendNode = new Node(val);
	headLast->next = appendNode;
	appendNode->prev = headLast;
	appendNode->next = headNode;
	headNode->prev = appendNode;
}
}
using namespace nodeOpt;
int main()
{
    Node* nn = newDoublyCircularLinkedList();
    int N,M,a,b,pos = 0;
    
    scanf("%d %d",&N,&M);
    int qwe = N;
    while (N--)
    {
        scanf(" %d",&a);
        append(nn,a);
    }
    Node* PP=nn->next;
    while (M--)
    {
        scanf(" %d",&a);
        switch (a)
        {
        case 1:
            PP=nn->next;
            break;
        case 2:
            if (PP->next->val) PP = PP->next;
            else PP = nn->next;
            break;
        case 3:
            scanf(" %d",&b);
            append(PP,b);
            break;
        case 4:
            scanf(" %d",&b);
            append(PP->next,b);
            break;
        }
    }
    printInfo(nn);
}
