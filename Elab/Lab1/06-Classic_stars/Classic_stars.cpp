#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int i = 1;
    int y = x-i;
    while(y>=0){
        for (int q=0;q<y;q++){
            cout << " ";
        }
        for (int r=0;r<i;r++){
            cout << "*";
        }
        cout << "\n";
        i = i + 1; 
        y = x-i;
    }
}