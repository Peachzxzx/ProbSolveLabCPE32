/*
LANG: C++
TASK: mars
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string text;
    int wheel[5];
    wheel[1] = 0;
    wheel[2] = 0;
    int T, sum = 0;
    cin >> T;
    cin.get();
    while (T--)
    {
        sum = 0;
        int n = 0;
        text.clear();
        getline(cin,text);
        cout << text.size();
        for (string::iterator c = text.begin(); c != text.end(); c++)
        {
            n = (*c) - 'A';
            int oneOne = wheel[1] - n;
            int oneTwo = n - wheel[1];
            if (oneOne >= 0)
            {
                if (oneTwo >= 0)
                {
                    oneOne = std::min(oneOne,oneTwo);
                }
            }
            else
                oneOne = oneTwo;
            int twoOne = wheel[2] - n;
            int twoTwo = n - wheel[2];
            if (twoTwo >= 0)
            {
                if (twoOne >= 0)
                {
                    twoTwo = std::min(twoTwo,twoOne);
                }
            }
            else
                twoTwo = twoOne;
            if (oneOne <= twoTwo)
            {
                wheel[1] = n;
                sum += oneOne;
            }
            else
            {
                wheel[2] = n;
                sum += twoTwo;
            }
            
        }
        cout << sum << "\n";
    }
}
