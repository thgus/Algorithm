/*
17622번: 타일 교체
https://www.acmicpc.net/problem/17622
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<vector<int>> map;

void initialize()
{
    cin>>n>>k;

    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

// 0: 위, 1: 왼, 2: 아래, 3: 오른
int result=INF;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int input_direction, int y, int x, int len){
    if(y==n-1&&x==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<map[i][j];
            }
        }
        result=min(result,len);
        return;
    }

    if(y<0||y>=n||x<0||x>=n){
        return;
    }

    int map_direction=map[y][x];
    switch(input_direction){
        case 0:
            if(map_direction==2){
                dfs(1,y,x+1,len+1);
            }
            else if(map_direction==3){
                dfs(3,y,x-1,len+1);
            }
            else if(map_direction==4){
                dfs(0,y+1,x,len+1);
            }
            break;
        case 1:
            if(map_direction==1){
                dfs(0,y+1,x,len+1);
            }
            else if(map_direction==3){
                dfs(2,y-1,x,len+1);
            }
            else if(map_direction==5){
                dfs(1,y,x+1,len+1);
            }
            break;
        case 2:
            if(map_direction==0){
                dfs(1,y,x+1,len+1);
            }
            else if(map_direction==1){
                dfs(3,y,x-1,len+1);
            }
            else if(map_direction==4){
                dfs(2,y-1,x,len+1);
            }
            break;
        case 3:
            if(map_direction==0){
                dfs(0,y+1,x,len+1);
            }
            else if(map_direction==2){
                dfs(2,y-1,x,len+1);
            }
            else if(map_direction==5){
                dfs(3,y,x-1,len+1);
            }
            break;
    }
}

void print_result(){
    if(result==INF){
        cout<<"-1";
    }
    else{
        cout<<result;
    }
}

int main()
{
    sync_off;
    initialize();
    if(k==0){
        dfs(1,0,0,0);
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int save=map[i][j];
                for(int k=0;k<=5;k++){
                    if(save==k) continue;
                    map[i][j]=k;
                    dfs(1,0,0,0);
                    map[i][j]=save;
                }
            }
        }
    }

    print_result();

    return 0;
}