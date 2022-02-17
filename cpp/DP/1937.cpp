/*
1937번: 욕심쟁이 판다
https://www.acmicpc.net/problem/1937
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map;

void initialize()
{
    cin>>n;

    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

bool boundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<n){
        return true;
    }
    else{
        return false;
    }
}

int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
vector<vector<int>> dp;

int dfs(int y, int x){
    if(dp[y][x]!=0) return dp[y][x];

    dp[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+d[i][0];
        int nx=x+d[i][1];

        if(!boundary(ny,nx)) continue;
        if(map[ny][nx]<=map[y][x])  continue;
        dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);
    }

    return dp[y][x];
}

void solve()
{
    dp.resize(n,vector<int>(n,0));

    int result=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result=max(result,dfs(i,j));
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