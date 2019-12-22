/*
LANG: C++
TASK: robot1000
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string direction;
    int x=0,y=0;
    getline(cin,direction);
    for (char& c : direction){
        switch (c){
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'Z':
            x = 0;
            y = 0;
            break;
        }
    }
    cout << x << " " << y << endl;
}