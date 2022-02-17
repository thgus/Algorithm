/*
18128번: 치삼이의 징검다리 건너기
https://www.acmicpc.net/problem/18128

치삼이 귀여워
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> map;
vector<vector<bool>> can_go;
vector<vector<bool>> water_visited;
queue<pair<int,int>> water;

void initialize()
{
    int w;
    cin>>n>>w;

    water_visited.resize(n,vector<bool>(n,false));
    can_go.resize(n,vector<bool>(n,true));

    int y,x;

    while(w--){
        //cin>>x>>y;
        cin>>y>>x;
        water.push({y-1,x-1});
        water_visited[y-1][x-1]=true;
    }

    map.resize(n);

    for(int i=0;i<n;i++){
        cin>>map[i];

        for(int j=0;j<n;j++){
            if(map[i][j]=='1'&&!water_visited[i][j]){
                can_go[i][j]=false;
            }
        }
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<n){
        return true;
    }
    else{
        return false;
    }
}

bool print_vec(vector<vector<bool>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

int dy[8]={1,-1,0,0,1,1,-1,-1};
int dx[8]={0,0,1,-1,1,-1,1,-1}; 

bool bfs(vector<vector<bool>> &visited, queue<pair<int,int>> &waiting_stone){
    queue<pair<int,int>> save;
    
    while(!waiting_stone.empty()){
        int y=waiting_stone.front().first;
        int x=waiting_stone.front().second;
        waiting_stone.pop();

        queue<pair<int,int>> que;
        que.push({y,x});

        while(!que.empty()){
            int cy=que.front().first;
            int cx=que.front().second;
            que.pop();

            if(!can_go[cy][cx]){
                save.push({cy,cx});
                continue;
            }

            if(cy==n-1&&cx==n-1){
                return true;
            }

            for(int i=0;i<8;i++){
                int ny=cy+dy[i];
                int nx=cx+dx[i];

                if(!isBoundary(ny,nx))   continue;
                if(visited[ny][nx])  continue;
                if(map[ny][nx]=='0')    continue;
                
                visited[ny][nx]=true;
                que.push({ny,nx});
            }
        }
    }

    waiting_stone=save;
    return false;
}

void flow_water(){
    queue<pair<int,int>> save;
    while(!water.empty()){
        int y=water.front().first;
        int x=water.front().second;
        water.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(!isBoundary(ny,nx))  continue;
            if(water_visited[ny][nx])   continue;
            
            water_visited[ny][nx]=true;
            can_go[ny][nx]=true;
            save.push({ny,nx});
        }
    }
    water=save;
}   

void solve()
{
    can_go[0][0]=can_go[n-1][n-1]=true;

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[0][0]=true;

    queue<pair<int,int>> waiting_stone;
    waiting_stone.push({0,0});

    int time=0;
    while(!bfs(visited,waiting_stone)){
        if(water.size()==0){
            time=-1;
            break;
        }
        time++;
        flow_water();
    }
    cout<<time;
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}