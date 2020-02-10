#include <stdio.h>
#include <new>
using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
	Node(int val=0, Node *next=0, Node *prev=0)
		: val(val), next(next), prev(prev) {}
} Node;

void append(Node *headNode,int val)
{
	Node *headLast = headNode->prev;
	Node *appendNode = new Node(val);
	headLast->next = appendNode;
	appendNode->prev = headLast;
	appendNode->next = headNode;
	headNode->prev = appendNode;
}

void printInfo(Node *node)
{
	Node *nowNode = node;
	while (nowNode->val != 0)
	{
		printf("%d ",nowNode->val);
		nowNode = nowNode->next;
	}
    printf("\n");
}

char findVal(Node **A[], int chainNumber, Node **thisPos, Node **thisPos2, int *val)
{
    while (chainNumber--)
    {
    
    }
}


int main()
{    
    int chainNumber, commandNumber, dnaCount = 1, dnaLength , dnaTail; // สร้างตัวแปรที่จำเป็นในการสร้าง dnaChain
    char command;
    scanf("%d %d",&chainNumber,&commandNumber); // รับค่าจำนวนสายและความยาวของคำสัง่
    Node **dnaChain = new Node *[chainNumber]; // สร้าง Array 2 มิติเก็บค่า
    Node *thisPos,*thisPos2; // สร้างตัวชี้ที่มิติที่ 1 และ 2
    Node **dnaRecycleBins = new Node *[commandNumber];
    int resultArray[commandNumber], backwardIndex, resultIndex; 
    for (int i = 0; i<chainNumber; i++) // loops รับค่า
    {
        scanf(" %d",&dnaLength); // รับค่่ความยาวสาย
        thisPos = dnaChain[i] = new Node(0); // ให้ตัวชี้มิติที่หนึ่งชี้ที่ตำแหน่งปัจจุบัน
        thisPos->next = thisPos; // กำหนดค่า Header
        thisPos->prev = thisPos; // กำหนดค่า Header
        for (int j = 0; j<dnaLength; j++) // loops เก็บค่า
            append(thisPos,dnaCount++);  // เก็บค่าใส่ Array ตำแหน่งที่ i
    }
    thisPos = dnaChain[0];
    thisPos2 = thisPos->next;
    backwardIndex = 0;
    resultIndex = 0;
    resultArray[0] = 1;
    while (commandNumber-->0)
    {
        scanf(" %c",&command);
        switch (command)
        {
        case 'B':
            
            break;
        case 'F':
            if (thisPos->next->val == 0)
            {
                resultArray[resultIndex++] = thisPos->val;
            }
            else
            {
                resultArray[resultIndex++] = thisPos->next->val;
            }
            break;
        case 'C':
			scanf(" %d",&dnaTail);
            printf("C %d\n",dnaTail);
            break;
        }
    }
}