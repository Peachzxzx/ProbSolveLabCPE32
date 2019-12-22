/*
LANG: C++
TASK: gifts
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int n,input;
    int output = 0;
    cin>>n;
    for (int i =0;i<n;i++){
        cin>>input;
        if (input>0){
            output+=input;
        }
    }
    cout << output <<endl;
}