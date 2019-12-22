/*
LANG: C++
TASK: strrev
*/
#include <iostream>
#include <string>
using namespace std;

class mains{
public:
    mains();
};

mains::mains(){
    string a;
    getline (cin,a);
    a = string(a.rbegin(),a.rend());
    cout << a << endl;
}

int main(){
    mains a;
}