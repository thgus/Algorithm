/*
16137번: 견우와 직녀
https://www.acmicpc.net/problem/16137
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
    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

struct Node{
    int len;
    int chance;
    int y,x;
};

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<n){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<vector<int>>> visited(2,vector<vector<int>>(n,vector<int>(n,1e9)));
    
    queue<Node> que;
    que.push({0,0,0,0});
    visited[0][0][0]=0;

    int ans=1e9;
    
    while(!que.empty()){
        int clen=que.front().len;
        int chance=que.front().chance;
        int cy=que.front().y;
        int cx=que.front().x;
        que.pop();

        if(map[cy][cx]==0){
            bool can_estb=true;
            for(int i=0;i<4;i++){
                int ny1=cy+d[i][0];
                int nx1=cx+d[i][1];

                int ny2=cy+d[(i+1)%4][0];
                int nx2=cx+d[(i+1)%4][1];

                if(!isBoundary(ny1,nx1))   continue;
                if(!isBoundary(ny2,nx2))   continue;

                if(map[ny1][nx1]!=1&&map[ny2][nx2]!=1){
                    can_estb=false;
                    break;
                }
            }

            if(!can_estb)   continue;
        }

        if(cy==n-1&&cx==n-1){
            ans=min(ans,clen);
            continue;
        }

        for(int i=0;i<4;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];

            if(!isBoundary(ny,nx))   continue;

            if(map[ny][nx]==1){
                if(visited[chance][ny][nx]>clen+1){
                    visited[chance][ny][nx]=clen+1;
                    que.push({clen+1,chance,ny,nx});
                }
            }
            else if(map[ny][nx]==0){
                if(chance==1)   continue;
                if(map[cy][cx]!=1)  continue;

                int nlen=((clen+1)%m==0)?clen+1:((clen/m)+1)*m;
                if(visited[1][ny][nx]>nlen){
                    visited[1][ny][nx]=nlen;
                    que.push({nlen,1,ny,nx});
                }
            }
            else if(map[ny][nx]>=2){
                if(map[cy][cx]!=1)  continue;

                int nlen=((clen+1)%map[ny][nx]==0)?clen+1:((clen/map[ny][nx])+1)*map[ny][nx];
                if(visited[chance][ny][nx]>nlen){
                    visited[chance][ny][nx]=nlen;
                    que.push({nlen,chance,ny,nx});
                }
            }
        }
    }

    if(ans==1e9){
        cout<<"-1";
    }
    else{
        cout<<ans;
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}