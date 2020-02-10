/*
LANG: C++
TASK: uva146_idcodes
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string str)  
{
    string s = str;
    bool ss = false; 
    do 
    {
        if (ss)
        {
            cout << str << "\n";
            return;
        }
        else if (s == str)
            ss = true;
    }
    while (next_permutation(str.begin(), str.end()));
    cout << "No Successor" << "\n";
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "#")
            break;
        permute(str);
        str.empty();
    }
}