/*
3055번: 탈출
https://www.acmicpc.net/problem/3055
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

queue<pair<int,int>> water;
int sy,sx;
int ey,ex;

void initialize()
{
    cin>>r>>c;
    map.resize(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];

            if(map[i][j]=='D'){
                ey=i;   ex=j;
            }
            if(map[i][j]=='S'){
                sy=i;   sx=j;
            }
            if(map[i][j]=='*'){
                water.push({i,j});
            }
        }
    }    
}

struct Node{
    int time;
    int y,x;
};

bool isBoundary(int y, int x){
    if(y>=0&&y<r&&x>=0&&x<c){
        return true;
    }
    else{
        return false;
    }
}

int d[4][2]{{-1,0},{1,0},{0,-1},{0,1}};
void move_water(){
    queue<pair<int,int>> new_water;
    while(!water.empty()){
        int cy=water.front().first;
        int cx=water.front().second;
        water.pop();
        
        for(int i=0;i<4;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];

            if(!isBoundary(ny,nx))  continue;

            if(map[ny][nx]=='X')    continue;
            else if(map[ny][nx]=='D')   continue;
            else if(map[ny][nx]=='*')   continue;

            map[ny][nx]='*';
            new_water.push({ny,nx});
        }   
    }
    water=new_water;
}

void solve()
{
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    visited[sy][sx]=true;

    queue<Node> que;
    que.push({0,sy,sx});

    int last_time=-1;
    while(!que.empty()){
        int ctime=que.front().time;
        int cy=que.front().y;
        int cx=que.front().x;
        que.pop();

        if(cy==ey&&cx==ex){
            cout<<ctime;
            return;
        }
        
        if(last_time<ctime){
            last_time=ctime;
            move_water();
        }

        for(int i=0;i<4;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];
            if(!isBoundary(ny,nx))   continue;
            
            if(map[ny][nx]=='X')    continue;
            else if(map[ny][nx]=='*')   continue;
            
            if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            que.push({ctime+1,ny,nx});
        }
    }
    cout<<"KAKTUS";
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}