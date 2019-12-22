#include <iostream>
using namespace std;

void find_max_min(int b[], int n,int* mx,int* mn)
{
    (*mx)=b[0];
    (*mn)=b[0];
    for(int i=0;b[i]!='\0';i++){
        if (b[i]>(*mx)){
            (*mx)=b[i];
        }
        if (b[i]<(*mn)){
            (*mn)=b[i];
        }
    }
}

main()
{
  int a[1000];
  int n;

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int mx,mn;
  find_max_min(a,n,&mx,&mn);

  cout << "max = " << mx << endl;
  cout << "min = " << mn << endl;
}