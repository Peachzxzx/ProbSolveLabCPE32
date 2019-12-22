/*
LANG: C++
TASK: cyclingchars
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    getline(cin,text);
    for (char c : text){
        int shift = 0;
        int charater = ((int) c);
        for (int i=0;i<4;i++){
            if (++charater > (int) 'z'){
                charater = (int) 'a';
            }
        }
        cout << ((char)charater);
    }
     
}