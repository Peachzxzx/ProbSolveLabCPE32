#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string S, T, res; 
    int y;
    getline(cin, res);
    istringstream(res) >> y;
    int l[y];
    getline(cin, S); 
  
    stringstream X(S); 
    int i=0;
    while (getline(X, T, ' ')) {
        istringstream(T) >> l[i++];
    }
    int car = 1;
    int index = 0;
    int res2 = 0;
    while (index<y){
        if (l[index]+res2>1000){
            res2 = l[index++];
            car++;
        }else{
            res2 = l[index++]+res2;
        }
    }
    cout << car << endl;
}