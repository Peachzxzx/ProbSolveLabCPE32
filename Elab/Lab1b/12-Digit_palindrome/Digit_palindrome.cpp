#include <iostream>
#include <string>
using namespace std;

int main(){
    string number;
    getline(cin,number);
    string reverseNumber = number;
    int len = number.length();
    int n=len-1;
    for(int i=0;i<(len/2);i++){
    //Using the swap method to switch values at each index
    swap(reverseNumber[i],reverseNumber[n--]);
    }
    for(int i=0;i<=number.length();i++){
        if(number[i]!=reverseNumber[i]){
            cout<< "no" <<endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}