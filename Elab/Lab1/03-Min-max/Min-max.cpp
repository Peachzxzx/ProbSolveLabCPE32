#include <iostream>

using namespace std;

int main()
{
  int n,x;
  int mn,mx;

  cin >> n;
  cin >> x;
  mn = mx = x;
  for (int i=1; i<n; i++) {
    cin >> x;
    if (mn>x) {
      mn = x;
    }
    if (x > mx) {
      mx = x;
    }
  }
  cout << mx << endl << mn << endl;
}