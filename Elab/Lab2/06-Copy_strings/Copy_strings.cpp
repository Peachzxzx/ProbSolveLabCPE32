#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
  for (int i=0;i<1000;i++){
      dest[i]=src[i];
      if (src[i] == '\0'){
          break;
      }
  }
}

main()
{
  char st1[1000];
  char st2[1000];

  cin.getline(st1,1000);
  copy_string(st1,st2);

  cout << st2 << endl;
}