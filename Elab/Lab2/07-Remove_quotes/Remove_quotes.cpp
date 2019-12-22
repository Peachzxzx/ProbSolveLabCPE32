#include <iostream>
using namespace std;

void remove_quotes(char* src, char *dest)
{
  int y = 0;
  for (int i=0;i<1000;i++){
    switch (src[i])
    {
      case '\'':
      case '\"':
        break;
      default:
        dest[y++] = src[i];
        break;
      }
      
  }
}

main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  remove_quotes(st,out);

  cout << out << endl;
}