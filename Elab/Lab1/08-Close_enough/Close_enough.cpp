#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
    string S, T; 
    int N,L,y;
    bool res = true;
    getline(cin, S); 
  
    stringstream X(S); 
  
    while (getline(X, T, ' ')) {
        if (res){
            istringstream(T)>> N;
            res = false;
        } else {
            istringstream(T)>> L;
        }
    }
    int Pos[N];
    for (int i = 0 ; i<N; i++){
        cin >> Pos[i];
    }
    int count = 0;
    for (int i = 0 ; i<(N-1); i++){
        for (int j = (i+1) ; j<N; j++){
            int chkVal = abs(Pos[i]-Pos[j]);
            if (chkVal<=L){
                count++;
            }
        }
    }
    cout << count << endl;
}