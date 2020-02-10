/*
LANG: C++
TASK: chains
*/
#include <stdio.h>
using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
	Node(int val=0, Node *prev=0, Node *next=0)
		: val(val), next(next), prev(prev) {}
} Node;

Node *search(Node **A[], int *Asize, int chainLength[], int *val)
{
	int left = 0, right = (*Asize) - 1, mid;
	Node **thisPos;
	while (left<=right)
	{
		mid = (left+right) / 2;
		thisPos = A[mid];
		if (thisPos[0]->val <= *val)
		{
			if (thisPos[chainLength[mid]]->val >= *val)
				return thisPos[(*val)-thisPos[0]->val];
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
}

int main()
{
	int chainNumber, commandNumber, dnaVal = 1, dnaLength; // สร้างตัวแปรที่จำเป็นในการสร้าง dnaChain
	scanf("%d %d",&chainNumber,&commandNumber); // รับค่าจำนวนสายและความยาวของคำสัง่
	Node ***dnaChain = new Node **[chainNumber]; // สร้าง Array 2 มิติเก็บค่า
	int dnaChainLength[chainNumber]; 
	Node *nowPosition, *prevPosition, *nextNext;
	int resultArray[commandNumber], resultIndex = 0, loopIterator;
	char command; 
	for (int i = 0; i<chainNumber; i++) // loops รับค่า
	{
		scanf(" %d",&dnaLength);
		dnaChainLength[i] = dnaLength - 1;
		dnaChain[i] = new Node *[dnaLength+1];
		dnaChain[i][0] = new Node(dnaVal++);
		for (loopIterator = 1; loopIterator<dnaLength; loopIterator++) // loops เก็บค่า
		{
			dnaChain[i][loopIterator] = new Node(dnaVal++,dnaChain[i][loopIterator-1]);
			dnaChain[i][loopIterator-1]->next = dnaChain[i][loopIterator];
		}
	}
	nowPosition = dnaChain[0][0];
	for (int loopIterator = commandNumber; loopIterator--;)
	{
		scanf(" %c",&command);
		switch (command)
		{
		case 'B':
			if (nowPosition->prev) nowPosition = nowPosition->prev; // ถ้ามีตัวต่อไปให้ขยับ
			break;
		case 'F':
			if (nowPosition->next) nowPosition = nowPosition->next; // ถ้ามีตัวก่อนหน้าให้ขยับ
			break;
		case 'C':
			scanf(" %d",&dnaVal);
			prevPosition = nowPosition; // เปลี่ยนตำแหน่งปลายสาย
			nowPosition = search(dnaChain, &chainNumber,dnaChainLength, &dnaVal); // หาตำแหน่งปลายสายใหม่
		/** ช้าเกินไป
		 *  if (nowPosition->prev)
		 *  {
		 *      Node *now = nowPosition, *next;
		 *      while (now)
		 *      {
		 *          next = now->prev;
		 *          now->next = now->prev;
		 *          now->prev = next;
		 *          now = now->next;
		 *      }
		 *  }
		 */
			if (prevPosition->next) prevPosition->next->prev = 0; // ถ้ามีตำแหน่งต่อไป {NULL 1 2<--(prevPos) 3 NULL} ให้ {NULL 1 2} {NULL 3 NULL}
			if (nowPosition->prev) nowPosition->next = nowPosition->prev;
			prevPosition->next = nowPosition;
			nowPosition->prev = prevPosition;
			break;
		}
		if (nowPosition->next)
		{
			Node *res = nowPosition->next;
			if (res->next == nowPosition)
			{
				res->next = res->prev;
				res->prev = nowPosition;
			}
		}
		resultArray[resultIndex++] = nowPosition->val;
	}
	for (loopIterator = 0; loopIterator<commandNumber; loopIterator++)
		printf("%d\n",resultArray[loopIterator]);
}