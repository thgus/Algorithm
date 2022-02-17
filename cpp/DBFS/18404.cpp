/*
18404번: 현명한 나이트
https://www.acmicpc.net/problem/18404
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
vector<int> horses;

int sy,sx;

bool isBoundary(int y, int x){
    if(y>0&&y<=n&&x>0&&x<=n){
        return true;
    }
    else{
        return false;
    }
}

void initialize()
{
    cin>>n>>m;
    map.resize(n+1,vector<int>(n+1,0));
    horses.resize(m+1);

    cin>>sy>>sx;

    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        map[a][b]=i;
    }
}

struct Node{
    int len;
    int y,x;
};

void solve()
{
    int d[8][2]={{-1,-2},{1,-2},{-1,2},{1,2},{2,1},{2,-1},{-2,1},{-2,-1}};
    int catch_n=0;

    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    visited[sy][sx]=true;

    queue<Node> que;
    que.push({0,sy,sx});

    while(!que.empty()){
        int clen=que.front().len;
        int cy=que.front().y;
        int cx=que.front().x;
        que.pop();

        if(catch_n==m)  break;

        for(int i=0;i<8;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];
            if(!isBoundary(ny,nx))   continue;

            if(visited[ny][nx])  continue;
            visited[ny][nx]=true;

            if(map[ny][nx]){  
                catch_n++;
                horses[map[ny][nx]]=clen+1;
            }

            que.push({clen+1,ny,nx});
        }

    }

    for(int i=1;i<=m;i++){
        cout<<horses[i]<<" ";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}