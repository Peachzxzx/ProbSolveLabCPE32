/*
LANG: C++
TASK: darts
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,score = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        float x,y,r;
        cin >> x>>y;
        r=hypot(x,y);
        if (r<=2)
            score += 5;
        else if (r<=4)
            score += 4;
        else if (r<=6)
            score += 3;
        else if (r<=8)
            score += 2;
        else if (r<=10)
            score += 1;
    }
    cout << score <<endl;
}