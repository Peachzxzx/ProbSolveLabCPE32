#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st)
{
  static int index = 0;
  switch ((*st))
    {
      case '<':
        dest[index++] = '&';
        dest[index++] = 'l';
        dest[index++] = 't';
        dest[index++] = ';';
        break;
      case '>':
        dest[index++] = '&';
        dest[index++] = 'g';
        dest[index++] = 't';
        dest[index++] = ';';
        break;
      case '\"':
        dest[index++] = '&';
        dest[index++] = 'q';
        dest[index++] = 'u';
        dest[index++] = 'o';
        dest[index++] = 't';
        dest[index++] = ';';
        break;
      default:
        dest[index++] = (*st);
        break;
    }
  return dest;
}

void escape(char* src, char *dest)
{
  for (int i=0;i<1000;i++){
    const char* x = &(src[i]);
    dest = write_chars(dest,x);
    if (src[i] == '\0'){
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
  escape(st,out);

  cout << out << endl;
}