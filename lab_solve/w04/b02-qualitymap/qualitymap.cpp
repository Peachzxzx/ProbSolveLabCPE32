/*
LANG: C++
TASK: qualitymap
*/

#include <cstdio>
using namespace std;

#define SPACE   '.'
#define FOREST  '*' 
#define MINERAL '$'
#define WALL    '#'
typedef struct qualitymap
{
	char is;
	bool notVisited;
} qualitymap;

int dir[][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // {y,x}
int N,M;
bool forest = false, mineral = false;
int count = 0;
qualitymap map[30][30];
void dfs(int y, int x)
{
	if (y == -1 || y == N)
		return;
	if (x == -1 || x == M)
		return;
	if (map[y][x].notVisited)
	{
		map[y][x].notVisited = false;
		if (map[y][x].is == WALL)
			return;
		else if (map[y][x].is == FOREST)
			forest = true;
		else if (map[y][x].is == MINERAL)
			mineral = true;
		for (int i = 0; i<4; i++)
			dfs(y+dir[i][0],x+dir[i][1]);
		count++;
	}
}

int main()
{
	char tmp;
	int countOne = 0, countTwo = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			scanf(" %c",&tmp);
			map[i][j].is = tmp;
			map[i][j].notVisited = true;
		}
	}
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			if (map[i][j].notVisited)
			{
				forest = false;
				mineral = false;
				count = 0;
				dfs(i,j);
				if (forest && mineral)
					countTwo += count;
				else if (forest != mineral)
					countOne += count;
			}
		}
	}
	printf("%d %d\n",countTwo,countOne);
}