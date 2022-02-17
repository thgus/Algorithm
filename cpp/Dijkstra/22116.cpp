/*
22116번: 창영이와 퇴근
https://www.acmicpc.net/problem/22116
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> height;

void initialize()
{
    cin>>n;
    height.resize(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>height[i][j];
        }
    }    
}

struct Node
{
    int sub;
    int y,x;
    bool operator<(const Node n) const
    {
        return n.sub<sub;
    }
};

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

void solve()
{
    vector<vector<int>> visited(n,vector<int>(n,INT_MAX));
    visited[0][0]=0;

    priority_queue<Node> pq;
    pq.push({0,0,0});

    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};

    while(!pq.empty())
    {
        int sub=pq.top().sub;
        int y=pq.top().y;
        int x=pq.top().x;
        pq.pop();

        if(visited[y][x]<sub) continue;

        if(y==n-1&&x==n-1)
        {
            cout<<sub;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isBoundary(ny,nx))   continue;
            
            int csub=abs(height[ny][nx]-height[y][x]);
            int nsub=max(csub,sub);

            if(visited[ny][nx]>nsub)
            {
                visited[ny][nx]=nsub;
                pq.push({nsub,ny,nx});
            }
        }
    }
}   

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}