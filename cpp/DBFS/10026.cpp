/*
10026번: 적록색약
https://www.acmicpc.net/problem/10026
*/

#include<iostream>
#include<vector>
#include<queue>

#define MAX 100
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<vector<char>> vec(MAX,vector<char>(MAX));

void initialize(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
}

void dfs(vector<vector<bool>> &isVisited, int r, int c, char color){
    queue<pair<int,int>> que;
    que.push({r,c});
    isVisited[r][c]=true;

    int _r,_c;
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    while(!que.empty()){
        for(int i=0;i<4;i++){
            _r=que.front().first+d[i][0];
            _c=que.front().second+d[i][1];
            if(_r>=0&&_r<n&&_c>=0&&_c<n&&!isVisited[_r][_c]&&color==vec[_r][_c]){
                que.push({_r,_c});
                isVisited[_r][_c]=true;
            }
        }
        que.pop();
    }

}

void rgdfs(vector<vector<bool>> &isVisited, int r, int c, char color){
    queue<pair<int,int>> que;
    que.push({r,c});
    isVisited[r][c]=true;

    int _r,_c;
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    while(!que.empty()){
        for(int i=0;i<4;i++){
            _r=que.front().first+d[i][0];
            _c=que.front().second+d[i][1];
            if(_r>=0&&_r<n&&_c>=0&&_c<n&&!isVisited[_r][_c]){
                if((color=='B'&&color==vec[_r][_c])||(color!='B'&&(vec[_r][_c]=='R'||vec[_r][_c]=='G'))){
                    que.push({_r,_c});
                    isVisited[_r][_c]=true;
                }
            }
        }
        que.pop();
    }

}

void solve(){
    vector<vector<bool>> isNomalVisited(MAX,vector<bool>(MAX,false));
    vector<vector<bool>> isRGVisited(MAX,vector<bool>(MAX,false));

    int non, weak;
    non=0; weak=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char color=vec[i][j];

            if(!isNomalVisited[i][j]){
                dfs(isNomalVisited, i, j, color);
                non++;
            }
            if(!isRGVisited[i][j]){
                rgdfs(isRGVisited,i,j,color);
                weak++;;
            }
        }
    }

    cout<<non<<" "<<weak;
}

int main(){
    sync_off;
    initialize();
    solve();
    
    return 0;
}