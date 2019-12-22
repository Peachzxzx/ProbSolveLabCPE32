/*
LANG: C++
TASK: buythemall
*/
#include <iostream>
using namespace std;

int main(){
    int sinka[3];
    for (int i =0;i<3;i++){
        cin>>sinka[i];
    }
    int jumnuansinka,jumnuan;
    int one = 0,two = 0,three = 0;
    cin>>jumnuansinka;
    for (int i=0;i<jumnuansinka;i++){
        cin>>jumnuan;
        if (jumnuan==1){
            one += 1;
        } else if (jumnuan == 2){
            two += 1;
        } else if (jumnuan == 3){
            three += 1;
        }
    }
    if ( sinka[0]*one < sinka[1]*two && sinka[0]*one < sinka[2]*three )
        cout << sinka[0]*one <<endl;
    else if ( sinka[1]*two < sinka[0]*one && sinka[1]*two < sinka[2]*three )
        cout << sinka[1]*two <<endl;
    else if ( sinka[2]*three < sinka[0]*one && sinka[2]*three < sinka[1]*two )
        cout << sinka[2]*three <<endl;
}