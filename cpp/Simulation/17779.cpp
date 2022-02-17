/*
17779번: 게리맨더링 2
https://www.acmicpc.net/problem/17779

개어려운데 왜 이게 골드 4??
개어려운데??? 개어려워
*/

#include <iostream>
#include <vector>
#include <string.h>

#define MAX 21
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int map[MAX][MAX];

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
}

bool isBoundary(int y, int x)
{
    if(y>=0&&y<n&&x>=0&&x<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool boundary[MAX][MAX];

int dy[2]={-1,1};
int dx[2]={1,1};
bool check_boundary(int &cy, int &cx, int index, int len)
{
    for (int k = 0; k < len; k++)
    {
        cy -= dy[index];
        cx += dx[index];
        if (!isBoundary(cy, cx))
        {
            return false;
        }
        boundary[cy][cx] = true;
    }

    return true;
}

void print_boundary()
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            boundary[i][j];
        }
        cout<<"\n";
    }
}

int make_boundary(int y, int x)
{
    for(int w=1;w<n;w++)
    {
        for(int h=1;h<n;h++)
        {
            for(int i=0;i<MAX;i++)  memset(boundary[i],false,sizeof(bool)*MAX);

            int y1=y,x1=x-1;
            if(!check_boundary(y1,x1,0,w))  continue;
            
            int y2=y1,x2=x2;
            if(!check_boundary(y2,x2,1,h))  continue;

            int y3=y,x3=x-1;
            int y4=y,x4=x-1;
            if(!check_boundary(y4,x4,1,w))  continue;

            print_boundary();
        }
    }
}

void solve()
{
    int result=1e9;
    for(int y=1;y<n-1;y++)
    {
        for(int x=1;x<n-1;x++)
        {
            make_boundary(y,x);
        }
    }

    cout<<result;
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}