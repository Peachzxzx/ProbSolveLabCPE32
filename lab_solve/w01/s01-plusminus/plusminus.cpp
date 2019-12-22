/*
LANG: C++
TASK: plusminus
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string S, T, res; 
    int y;
    getline(cin, res);
    istringstream(res) >> y;
    char l[2*y-1];
    int j[2*y-1];
    getline(cin, S); 
    stringstream X(S); 
    int i=0;
    while (getline(X, T, ' ')) {
        istringstream(T) >> l[i];
        istringstream(T) >> j[i++];
    }
    int index = 1;
    int num1=j[2];
    int num2=j[0];
    while (index<(2*y-1)){
        switch (l[index])
        {
        case '+':
            num2 = num2 + num1; 
            break;
        case '-':
            num2 = num2 - num1;
            break;
        default:
            num1 = j[index+2];
            break;
        }
        index++;
    }
    cout << num2 << endl;
}