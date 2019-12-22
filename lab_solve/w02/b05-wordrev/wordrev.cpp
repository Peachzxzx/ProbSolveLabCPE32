/*
LANG: C++
TASK: wordrev
*/
#include <iostream>
#include <string>
using namespace std;

class mains{
public:
    mains();
};

mains::mains(){
    string a,b,c;
    getline (cin,a);
    for (char i:a){
        if (i == '_'){
            c+=string(b.rbegin(),b.rend())+'_';
            b.clear();
        } else {
            b.push_back(i);
        }
    }
    c+=string(b.rbegin(),b.rend());
    cout << c <<endl;
}

int main(){
    mains a;
}