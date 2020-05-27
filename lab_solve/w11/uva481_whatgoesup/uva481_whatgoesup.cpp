/*
LANG: C++
TASK: uva481_whatgoesup
*/
#include <cstdio>
#include <algorithm>
#define MAX_N 100001 
using namespace std;
typedef struct iii
{
	int data;
	int index;

	bool operator<(const iii& rhs) const { data < rhs.data;}
};

iii input[MAX_N];

int main()
{
	int in = 0;
	int i;
	for (i = 0;;i++)
	{
		if (scanf(" %d",&in) != 1) break;
		input[i].data = in;
	}
	std::sort(input,input+i);
	for (int j = 0; j <= i;j++)
	{
		if (input[])
	}
}