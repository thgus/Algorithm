/*
16933번: 벽 부수고 이동하기 3
https://www.acmicpc.net/problem/16933
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<vector<char>> map;

void initialize()
{
    cin>>n>>m>>k;
    map.resize(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
}

struct Point{
    int time;
    int break_wall;
    int y,x;
};

bool is_boundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<m){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

    vector<vector<vector<bool>>> visited(k+1,vector<vector<bool>>(n,vector<bool>(m,false)));
    queue<Point> que;
    que.push({1,0,0,0});
    visited[0][0][0]=true;

    int ans=1e9;
    while(!que.empty()){
        int c_time=que.front().time;
        int c_bw=que.front().break_wall;
        int c_y=que.front().y;
        int c_x=que.front().x;
        que.pop();

        if(c_y==n-1&&c_x==m-1){
            ans=min(ans,c_time);
            continue;
        }

        for(int i=0;i<4;i++){
            int n_y=c_y+d[i][0];
            int n_x=c_x+d[i][1];

            if(!is_boundary(n_y,n_x))    continue;
            if(map[n_y][n_x]=='0'){
                if(visited[c_bw][n_y][n_x]) continue;
                visited[c_bw][n_y][n_x]=true;
                que.push({c_time+1,c_bw,n_y,n_x});
            }
            else if(map[n_y][n_x]=='1'){
                if(c_bw>=k) continue;

                if(c_time%2==0){
                    que.push({c_time+1,c_bw,c_y,c_x});
                }
                else{
                    if(visited[c_bw+1][n_y][n_x])   continue;
                    visited[c_bw+1][n_y][n_x]=true;
                    que.push({c_time+1,c_bw+1,n_y,n_x});
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