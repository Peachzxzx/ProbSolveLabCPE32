/*
LANG: C++
TASK: dreaming
*/
#include <iostream>
#include <string>
using namespace std;

typedef struct fullAdderResult{
    int sum=0;
    int carry=0;
}fullAdderResult;

class int300digits{
public:
    int300digits();
private:
    void fulladder(char a,char b,fullAdderResult* c){
        int sum = (a-'0')+(b-'0')+(c->carry);
        c->sum = sum%10;
        c->carry = sum/10;
    }
};

int300digits::int300digits(){
    string a,b,out;
    int size;
    getline(cin,a);
    getline(cin,b);
    a = string(a.rbegin(),a.rend());
    b = string(b.rbegin(),b.rend());
    if (a.length()>b.length()){
        size = a.length();
        for (int i = b.length();i<a.length();i++){
            b.push_back('0');
        }
    } else {
        size = b.length();
        for (int i = a.length();i<b.length();i++){
            a.push_back('0');
        }
    }
    fullAdderResult c;
    for (int i=0;i<size;i++){
        fulladder(a[i],b[i],&c);
        out.push_back(c.sum);
    }
    if (c.carry>0){
        out.push_back(c.carry);
    }
    out = string(out.rbegin(),out.rend());
    for (char c:out){
        cout << (int)c;
    }
}

int main(){
    int300digits a;
}