/*
LANG: C++
TASK: fin62_food
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int persons[5000];
int table[5000][5000]; //[time][food]
int main()
{
	int N,K,time;
	scanf("%d %d",&N,&K);
	for (int i = 2; i<=N+1;i++)
	{
		scanf(" %d",&time);
		persons[i] = time;
	}
	int food_a1 = K, food_b1 = K, food_a2 = K, food_b2 = K,food_a = K, food_b = K;
	for (int t = 2; t <= N+1; t++)
	{
		table[t][] = 
	}	
	cout << table[N+1];
}