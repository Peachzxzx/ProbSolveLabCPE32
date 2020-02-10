/*
LANG: C++
TASK: trains
*/
#include <stdio.h>
#include <list>

using namespace std;
list<int> trainStations[100000];

int main()
{
    int loop, from, to;
    char command;
    scanf("%d",&loop);
    while (loop-->0)
    {
        scanf(" %c %d %d",&command,&from,&to);
        switch (command)
        {
        case 'N':
            trainStations[to-1].push_back(from);
            break;
        
        case 'M':
            trainStations[from-1].splice(trainStations[to-1].end(),trainStations[from-1]);
            break;
        }
    }
    for (int i = 0;i<100000;i++)
    {
        for (std::_List_iterator<int> j=trainStations[i].begin();j!=trainStations[i].end();j++)
        {
            printf("%d\n",*j);
        }
    }
}