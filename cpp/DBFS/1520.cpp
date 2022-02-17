/*
1520번: 내리막 길
https://www.acmicpc.net/problem/1520

내가 바텀업 방식은 어려워 하는 것 같다.
이 문제를 bfs로 푸는 방법은 없을까?
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c;
vector<vector<int>> map;

void initialize()
{
    cin>>r>>c;
    map.resize(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<r&&x>=0&&x<c){
        return true;
    }
    else{
        return false;
    }
}

vector<vector<int>> dp;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int y, int x){
    if(dp[y][x]!=-1)    return dp[y][x];
    if(y==r-1&&x==c-1)  return 1;
    dp[y][x]=0;

    for(int i=0;i<4;i++){
        int ny=y+d[i][0];
        int nx=x+d[i][1];

        if(!isBoundary(ny,nx))   continue;
        if(map[y][x]<=map[ny][nx])  continue;
        dp[y][x]+=dfs(ny,nx);
    }

    return dp[y][x];
}

void solve()
{
    dp.resize(r,vector<int>(c,-1));
    dfs(0,0);

    cout<<dp[0][0];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}