#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int height[n];
    for(int i=0; i<n; i++) {
        cin >> height[i];
    }
    int height_list[n];
    for(int i=0; i<n; i++){
        height_list[i] = 0;
        for(int j=0;j<n;j++){
            if(height[i]<height[j]){
                height_list[i] = height_list[i] + 1;
            }
        }
        cout << height_list[i] << endl;
    }
}