/*
LANG: C++
TASK: uva357_letmecount
*/
#include<cstdio>
using namespace std;
#define MAX_N 30001

int main()
{
	int coins[5] = { 1, 5, 10, 25, 50 };
	long long value[MAX_N] = { 1 };

	for (int i = 0; i < 5; i++)
		for (int j = coins[i]; j < MAX_N; j++)
			value[j] += value[j - coins[i]];

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (value[n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", value[n], n);
	}

}