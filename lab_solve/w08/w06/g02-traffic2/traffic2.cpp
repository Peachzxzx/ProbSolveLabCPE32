/*
LANG: C++
TASK: traffic2
*/
#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;

int n,k;
int ans[3][4];
void fi(int x,int y1,int y2)
{
    if (k == 0) return;
    if (y2-y1 == 0) return;
    int mid = (y2+y1) / 2;
    int res = traffic_query(x,y1,x,mid);
    if (res != (mid-y1))
        if (mid - y1 == 1)
        {
            ans[k][0] = x;
            ans[k][1] = y1;
            ans[k][2] = x;
            ans[k][3] = mid;
            k--;
            return;
        }
        else
            fi(x, y1, mid);
    else
        if (y2 - mid == 1)
        {
            ans[k][0] = x;
            ans[k][1] = mid;
            ans[k][2] = x;
            ans[k][3] = y2;
            k--;
            return;
        }
        else
            fi(x, mid, y2);
}

void fiii(int x,int y1,int y2)
{
    if (k == 0) return;
    if (y2-y1 == 0) return;
    int mid = (y2+y1) / 2;
    int res = traffic_query(x,y1,x,mid);
    if (res == (mid-y1) + 1)
        if (y2 - y1 == 1)
        {
            ans[k][0] = x;
            ans[k][1] = y1;
            ans[k][2] = x;
            ans[k][3] = mid;
            k--;
            if (k == 0)
                return;
        }
        else
        {
            fi(x, y1, mid);
            fi(x, mid, y2);
        }
    else if (res == (mid-y1) + 2)
        fiii(x, y1, mid);
    else
        fiii(x, mid, y2);
}

void fii(int x1,int x2,int y)
{
    if (k == 0) return;
    if (x2-x1 == 0) return;
    int mid = (x2+x1) / 2;
    int res = traffic_query(x1,y,mid,y);
    if (res != (mid-x1))
        if (mid - x1 == 1)
        {
            ans[k][0] = x1;
            ans[k][1] = y;
            ans[k][2] = mid;
            ans[k][3] = y;
            k--;
            return;
        }
        else
            fii(x1, mid, y);
    else
    {
        if (x2 - mid == 1)
        {
            ans[k][0] = mid;
            ans[k][1] = y;
            ans[k][2] = x2;
            ans[k][3] = y;
            k--;
            return;
        }
        fii(mid, x2, y);
    }
}

void fiv(int x1,int x2,int y)
{
    if (k == 0) return;
    if (x2-x1 == 0) return;
    int mid = (x2+x1) / 2;
    int res = traffic_query(x1,y,mid,y);
    if (res == mid - x1)
        fiv(mid, x2, y);
    else if (res == (mid-x1) + 1)
        if (x2 - x1 == 1)
        {
            ans[k][0] = x1;
            ans[k][1] = y;
            ans[k][2] = mid;
            ans[k][3] = y;
            k--;
            if (k == 0)
                return;
        }
        else
        {
            fii(x1, mid, y);
            fii(mid, x2, y);
        }
    else if (res == (mid-x1) + 2)
        fiv(x1, mid, y);
    else
        fiv(mid, x2, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    traffic_init(&n,&k);
    int res = 0;
    for (int i = 1 ; i<=n; i++)
    {
        res = traffic_query(i,1,i,n);
        if (res == n) fi(i,1,n);
        else if (res == n+1) fiii(i,1,n);
        if (k == 0)
        {
            traffic_report(ans[1][0],ans[1][1],ans[1][2],ans[1][3], ans[2][0],ans[2][1],ans[2][2],ans[2][3]);
            return 0;
        }
    }
    if (k)
        for (int i = 1 ; i<=n; i++)
        {
            res = traffic_query(1,i,n,i);
            if (res == n) fii(1,n,i);
            else if (res == n+1) fiv(1,n,i);
            if (k == 0)
            {
                traffic_report(ans[1][0],ans[1][1],ans[1][2],ans[1][3], ans[2][0],ans[2][1],ans[2][2],ans[2][3]);
                return 0;
            }
        }
    return 0;
}
