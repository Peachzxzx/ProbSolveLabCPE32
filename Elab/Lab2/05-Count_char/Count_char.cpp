#include <iostream>
using namespace std;

int count_char(char* st, char c)
{
  int res = 0;
  for (int i =0 ; i<1000;i++){
      char x = st[i];
      if (x == c){
        res += 1;
      }
      if (st[i] == '\0'){
        break;
      }
  }
  return res;
}

main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}