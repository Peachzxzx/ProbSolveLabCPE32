/*
LANG: C++
TASK: maxlate
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int,int>> jobs;
    int aa,bb,cc;
    cin >> cc;
    for(int i=0; i<cc; i++)
    {
        cin >> aa >> bb;
        jobs.push_back(make_pair(aa, bb));
    }
    sort(jobs.begin(), jobs.end());
    int t = 0;
    vector<pair<int,int>> jobInt;
    for(int i=0; i<cc; i++)
    {
        jobInt.push_back(make_pair(t,t+jobs[i].second));
        t += jobs[i].second;
    }
    
    int debt = 0;
    
    for(int i=0; i<cc; i++)
    {
        int abc = jobInt[i].second-jobs[i].first;
        if (abc <= 10)
            ;
        else 
            debt = max(abc,debt);
    }
    int c = ((debt - 10) * 1000);
    
    if (c>0)
        cout << c;
    else
        cout << 0;
    return 0;
}