/*
LANG: C++
TASK: robot1000s
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void dis(int N,int E, int W, int S,int *X,int *Y);

int main(){
    string direction;
    int x=0,y=0,N=0,E=0,W=0,S=0;
    getline(cin,direction);
    for (char& c : direction){
        switch (c){
        case 'N':
            y++;
            N++;
            break;
        case 'S':
            y--;
            S++;
            break;
        case 'E':
            x++;
            E++;
            break;
        case 'W':
            x--;
            W++;
            break;
        }
    }
    int missingMove;
    cin >> missingMove;
    while (missingMove>0){
        if (y>0 && S>0){
            S--;
            missingMove--;
            dis(N,E,W,S,&x,&y);
        } else if (y<0 && N>0){
            N--;
            missingMove--;
            dis(N,E,W,S,&x,&y);
        } else if (x>0 && W>0){
            W--;
            missingMove--;
            dis(N,E,W,S,&x,&y);
        } else if (x<0 && E>0){
            E--;
            missingMove--;
            dis(N,E,W,S,&x,&y);
        } else {
            if (N>0){
                N--;
                missingMove--;
                dis(N,E,W,S,&x,&y);
            } else if (E>0){
                E--;
                missingMove--;
                dis(N,E,W,S,&x,&y);
            } else if (W>0){
                W--;
                missingMove--;
                dis(N,E,W,S,&x,&y);
            } else if (S>0){
                S--;
                missingMove--;
                dis(N,E,W,S,&x,&y);
            }
        }
    }
    cout << (abs(x)+abs(y))*2<<endl;
}

void dis(int N,int E, int W, int S,int *X,int *Y){
    *X = E-W;
    *Y = N-S;
}