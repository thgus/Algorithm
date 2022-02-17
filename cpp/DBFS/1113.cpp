/*
1113번: 수영장 만들기
https://www.acmicpc.net/problem/1113
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    map.resize(n,vector<int>(m));

    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;

            map[i][j]=c-'0';
        }
    }
}

void print_vector(vector<vector<bool>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    vector<vector<bool>> isEdge(n,vector<bool>(m,false));
    vector<vector<bool>> isSum(n,vector<bool>(m,false));
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

    int result=0;
    for(int k=9;k>=1;k--){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(map[y][x]==k){
                    isEdge[y][x]=true;
                }
            }
        }

        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        queue<pair<int,int>> que;
        
        int sum=0;
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(isVisited[y][x] || isEdge[y][x] || isSum[y][x]) continue;

                vector<vector<bool>> cur_visited(n,vector<bool>(m,false));
                bool isPool=true;
                int num=0;  int depth=0;
                que.push({y,x});
                while(!que.empty()){
                    int cur_y=que.front().first;
                    int cur_x=que.front().second;
                    que.pop();

                    if(isVisited[cur_y][cur_x]||isEdge[cur_y][cur_x]) continue;
                    isVisited[cur_y][cur_x]=true;
                    cur_visited[cur_y][cur_x]=true;

                    num++;
                    depth+=map[cur_y][cur_x];

                    for(int i=0;i<4;i++){
                        int next_y=cur_y+d[i][0];
                        int next_x=cur_x+d[i][1];
                        if(next_y>=0&&next_y<n&&next_x>=0&&next_x<m){
                           que.push({next_y,next_x}); 
                        }
                        else{
                            isPool=false;
                        }
                    }                    
                }

                if(isPool){
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(cur_visited[i][j])   isSum[i][j]=true;
                        }
                    }
                    result+=k*num-depth;
                }
            }
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