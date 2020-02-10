/*
LANG: C++
TASK: ic
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> icArray;
    string command;
    int commandNum, icNumber, tmp;
    cin >> commandNum;
    while (commandNum-->0)
    {
        cin >> command;
        if (command == "li")
        {
            cin >> icNumber;
            icArray.push_front(icNumber);
        }
        else if (command == "ri")
        {
            cin >> icNumber;
            icArray.push_back(icNumber);
        }
        else if (icArray.empty())
        {

        }
        else if (command == "lr")
        {
            tmp = icArray.front();
			icArray.pop_front();
            icArray.push_back(tmp);
        }
        else if (command == "rr")
        {
            tmp = icArray.back();
			icArray.pop_back();
            icArray.push_front(tmp);
        }
    }  
    while (icArray.empty()!=1)
    {
        cout << icArray.front() << endl;
        icArray.pop_front();
    }
}