/*
2178번: 미로 탐색
https://www.acmicpc.net/problem/2178
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
vector<string> vec;

void initialize()
{
    cin>>n>>m;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

bool boundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<m){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    queue<pair<int,pair<int,int>>> que;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    que.push({1,{0,0}});
    visited[0][0]=true;

    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    while(!que.empty()){
        int y=que.front().second.first;
        int x=que.front().second.second;
        int len=que.front().first;
        que.pop();

        //cout<<y<<" "<<x<<"\n";

        if(y==n-1&&x==m-1){
            cout<<len;
            break;
        }

        for(int i=0;i<4;i++){
            int ny=y+d[i][0];
            int nx=x+d[i][1];

            if(!boundary(ny,nx))    continue;
            if(vec[ny][nx]=='0')    continue;
            if(visited[ny][nx])     continue;
            visited[ny][nx]=true;
            que.push({len+1,{ny,nx}});
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