/*
LANG: C++
TASK: parentest
*/
#include <iostream>
using namespace std;

int main(){
    string text;
    int y;
    cin >> y;
    getline(cin,text);
    int result[y];
    for (int i = 0; i<y ; i++){
        string stack;
        getline(cin,text);
        for (char c: text){
            switch (c)
            {
            case '{':
                stack.append("{");
                break;
            case '}':
                stack.append("}");
                break;
            case '(':
                stack.append("(");
                break;
            case ')':
                stack.append(")");
                break;
            case '[':
                stack.append("[");
                break;
            case ']':
                stack.append("]");
                break;
            }
            if (stack.length()>=2){
                if (stack[stack.length()-2]=='{' && stack[stack.length()-1]=='}'){
                    stack.pop_back();stack.pop_back();
                } else if (stack[stack.length()-2]=='(' && stack[stack.length()-1]==')') {
                    stack.pop_back();stack.pop_back();
                } else if (stack[stack.length()-2]=='[' && stack[stack.length()-1]==']') {
                    stack.pop_back();stack.pop_back();
                }
            }
        }

        if (stack.empty()){
            result[i]=1;
        } else {
            result[i]=2;
        }
    }
    for (int j:result){
        if (j == 1){
            cout << "yes" <<endl;
        } else if (j == 2){
            cout << "no" << endl;
        }
    }
}