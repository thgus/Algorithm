/*
15653번: 구슬 탈출 4
https://www.acmicpc.net/problem/15653
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
vector<vector<char>> map;

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<m){
        return true;
    }
    else{
        return false;
    }
}

struct Node{
    int cost;
    pair<int,int> red;
    pair<int,int> blue;
};

pair<int,int> red_start;
pair<int,int> blue_start;

void initialize()
{
    cin>>n>>m;
    map.resize(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];

            if(map[i][j]=='R'){
                red_start.first=i;
                red_start.second=j;
            }

            if(map[i][j]=='B'){
                blue_start.first=i;
                blue_start.second=j;
            }
        }
    }

}

void solve()
{
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<vector<pair<int,int>>>> direction(n,vector<vector<pair<int,int>>>(m,vector<pair<int,int>>(4)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int next_y=i;
                int next_x=j;

                while(1){
                    if(!isBoundary(next_y,next_x)||map[next_y][next_x]=='#'){
                        next_y-=d[k][0];
                        next_x-=d[k][1];
                        break;
                    }
                    if(map[next_y][next_x]=='O'){
                        break;
                    }

                    next_y+=d[k][0];
                    next_x+=d[k][1];
                }

                direction[i][j][k]={next_y,next_x};
            }
        }
    }

    bool isVisited[n][m][n][m];
    for(int i=0;i<n;i++){   for(int j=0;j<m;j++){   for(int k=0;k<n;k++){   for(int l=0;l<m;l++){
                    isVisited[i][j][k][l]={false};
    }   }   }   }

    queue<Node> que;
    que.push({0,red_start,blue_start});
    isVisited[red_start.first][red_start.second][blue_start.first][blue_start.second]=true;

    while(!que.empty()){
        Node cur=que.front();
        que.pop();

        if(map[cur.red.first][cur.red.second]=='O'){
            cout<<cur.cost;
            return;
        }

        for(int i=0;i<4;i++){
            pair<int,int> next_red=direction[cur.red.first][cur.red.second][i];
            pair<int,int> next_blue=direction[cur.blue.first][cur.blue.second][i];

            if(map[next_blue.first][next_blue.second]=='O') continue;


            if(next_red.first==next_blue.first&&next_red.second==next_blue.second){
                bool is_red_change;
                switch(i){
                    case 0:
                        is_red_change=(cur.red.first<cur.blue.first)?false:true;
                        break;
                    case 1:
                        is_red_change=(cur.red.first<cur.blue.first)?true:false;
                        break;
                    case 2:
                        is_red_change=(cur.red.second<cur.blue.second)?false:true;
                        break;
                    case 3:
                        is_red_change=(cur.red.second<cur.blue.second)?true:false;
                        break;
                }

                if(is_red_change){
                    next_red.first-=d[i][0];
                    next_red.second-=d[i][1];
                }
                else{
                    next_blue.first-=d[i][0];
                    next_blue.second-=d[i][1];
                }
            }

            if(!isVisited[next_red.first][next_red.second][next_blue.first][next_blue.second]){
                isVisited[next_red.first][next_red.second][next_blue.first][next_blue.second]=true;
                que.push({cur.cost+1,next_red,next_blue});
            }
        }
    }

    cout<<"-1";
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}