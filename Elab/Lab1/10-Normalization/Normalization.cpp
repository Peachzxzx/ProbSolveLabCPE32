#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
#include <sstream>
using namespace std;

int gcd(int x,int y);

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

    int divider = gcd(N,L);
    cout << N/divider << "/" << L/divider << endl;
}

int gcd(int x,int y){
    if (y>x){
        int tmp = x;
        x = y;
        y = tmp;
    }
    for (int i = y ; i>0;i--){
        if (x%i==0 && y%i==0){
            return i;
        }
    }
}
