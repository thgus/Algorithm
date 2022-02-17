/*
3184번: 양
https://www.acmicpc.net/problem/3184
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
vector<vector<char>> map;

int wolf,sheep;
void initialize()
{
    wolf=sheep=0;

    cin>>r>>c;   
    map.resize(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];

            if(map[i][j]=='o'){
                sheep++;
            }
            else if(map[i][j]=='v'){
                wolf++;
            }
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

void solve()
{
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(visited[i][j])   continue;
            if(map[i][j]=='#')  continue;

            int cur_wolf,cur_sheep;
            cur_wolf=cur_sheep=0;

            queue<pair<int,int>> que;
            que.push({i,j});
            visited[i][j]=true;
            
            while(!que.empty()){
                int cy=que.front().first;
                int cx=que.front().second;
                que.pop();

                if(map[cy][cx]=='o')    cur_sheep++;
                if(map[cy][cx]=='v')    cur_wolf++;

                for(int i=0;i<4;i++){
                    int ny=cy+d[i][0];
                    int nx=cx+d[i][1];
                    if(!isBoundary(ny,nx))  continue;
                    if(map[ny][nx]=='#')    continue;
                    if(visited[ny][nx])     continue;
                    visited[ny][nx]=true;
                    que.push({ny,nx});
                }
            }

             
            if(cur_wolf>=cur_sheep){
                sheep-=cur_sheep;
            }
            else{
                wolf-=cur_wolf;
            }
        }
    }

    cout<<sheep<<" "<<wolf;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}