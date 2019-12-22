/*
LANG: C++
TASK: robot2000
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void rotateDir(char wantDir,char *d,string *dir);

int main(){
    string l;
    getline(cin, l);
    int index = 0;
    string dir;
    char forwardDir = 'N';
    while (index<l.length()){
        switch ((char)l[index])
        {
        case 'N':
            rotateDir('N',&forwardDir,&dir);
            dir.append("F");
            break;
        case 'E':
            rotateDir('E',&forwardDir,&dir);
            dir.append("F");
            break;
        case 'W':
            rotateDir('W',&forwardDir,&dir);
            dir.append("F");
            break;
        case 'S':
            rotateDir('S',&forwardDir,&dir);
            dir.append("F");
            break;
        case 'Z':
            dir.append("Z");
            forwardDir = 'N';
            break;
        default:
            break;
        }
        index++;
    }
    cout << dir << endl;
}

void rotateDir(char wantDir,char *d,string *dir){
    while (wantDir!=(*d))
    {
        switch (*d)
        {
            case 'N':
                *d = 'E';
                (*dir).append("R");
                break;
            case 'E':
                *d = 'S';
                (*dir).append("R");
                break;
            case 'W':
                *d = 'N';
                (*dir).append("R");
                break;
            case 'S':
                *d = 'W';
                (*dir).append("R");
                break;
        }
    }
    if ((*dir).length()>=4){
        if ((*dir)[-1]=='R' && (*dir)[-2]=='R' && (*dir)[-3]=='R' && (*dir)[-4]=='R'){
            (*dir).pop_back();
            (*dir).pop_back();
            (*dir).pop_back();
            (*dir).pop_back();
        }
    }
}