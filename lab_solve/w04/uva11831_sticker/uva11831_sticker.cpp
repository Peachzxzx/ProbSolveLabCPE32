/*
LANG: C++
TASK: uva11831_sticker
*/
#include <cstdio>
using namespace std;

int work(int N, int M, int S)
{
    int forward[][2] = {{0,-1},{1,0},{0,1},{-1,0}}; // {x,y};{N,L,S,O};{N,E,S,W}
    int x, y, dir, sticker = 0;
    char map[N][M];
    char in;
    for (int i = 0; i<N; i++)
    {
        scanf(" ");
        for (int j = 0; j<M; j++)
        {
            scanf("%c",&in);
            switch (in)
            {
            case 'N':
                dir = 0;
                x = j;
                y = i;
                break;
            case 'S':
                dir = 2;
                x = j;
                y = i;
                break;
            case 'L':
                dir = 1;
                x = j;
                y = i;
                break;
            case 'O':
                dir = 3;
                x = j;
                y = i;
                break;
            }
            map[i][j] = in;
        }
    }
    scanf(" ");
    while (S--)
    {
        scanf("%c",&in);
        switch (in)
        {
        case 'D':
            switch (++dir)
            {
            case 4:
                dir = 0;
                break;
            }
            break;
        case 'E':
            switch (--dir)
            {
            case -1:
                dir = 3;
                break;
            }
            break;
        case 'F':
            x = x+forward[dir][0];
            y = y+forward[dir][1];
            if (x == M | y == N | x == -1 | y == -1) 
            {
                x = x-forward[dir][0];
                y = y-forward[dir][1];
            }
            else
            {
                switch (map[y][x])
                {
                case '#':
                    x = x-forward[dir][0];
                    y = y-forward[dir][1];
                    break;
                case '*':
                    sticker++;
                    map[y][x] = '.';
                    break;
                }
            }
            break;
        }
    }
    return sticker;
}

int main()
{
    int N,M,S;
    do {
        int r = scanf("%d %d %d", &N, &M, &S);
        if (N==0||  M==0 || S==0) break;
        printf("%d\n",work(N,M,S));
    } while(true);
}