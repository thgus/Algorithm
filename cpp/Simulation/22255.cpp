/*
22255번: 호석사우루스
https://www.acmicpc.net/problem/22255
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> map;

void initialize()
{
    cin>>n>>m;
    map.resize(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
}

struct Node
{
    int y,x;
    int time;
    int shock;
}

void solve()
{
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    int 
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}