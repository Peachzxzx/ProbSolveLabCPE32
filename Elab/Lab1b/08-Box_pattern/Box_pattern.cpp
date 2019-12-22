#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int loop = 1;
    for (int i = 0; i<x; i++){
        for (int j = 0; j<x; j++){
            cout << loop++;
            if (loop>x){
                loop = 1;
            }
        }
        cout << endl;
        loop += 1;
    }
}