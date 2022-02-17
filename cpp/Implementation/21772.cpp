/*
21772번: 가희의 고구마 먹방
https://www.acmicpc.net/problem/21772
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c,t;
vector<vector<char>> vec;

struct Node{
    int y,x;
    int time;
    int sweet;
};

bool boundary(int y, int x){
    if(y>=0&&x>=0&&y<r&&x<c){
        return true;
    }
    else{
        return false;
    }
}

int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int result=0;
void dfs(Node n){
    if(n.time==t){
        result=max(result,n.sweet);
        return;
    }

    for(int i=0;i<4;i++){
        int ny=n.y+d[i][0];
        int nx=n.x+d[i][1];

        if(!boundary(ny,nx))    continue;
        if(vec[ny][nx]=='#'){
            continue;
        }
        else if(vec[ny][nx]=='S'){
            vec[ny][nx]='.';
            dfs({ny,nx,n.time+1,n.sweet+1});
            vec[ny][nx]='S';
        }
        else if(vec[ny][nx]=='.'||vec[ny][nx]=='G'){
            dfs({ny,nx,n.time+1,n.sweet});
        }
    }
}

int main()
{
    sync_off;

    cin>>r>>c>>t;
    vec.resize(r,vector<char>(c));
    
    int y,x;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>vec[i][j];

            if(vec[i][j]=='G'){
                y=i;
                x=j;
            }
        }
    }

    dfs({y,x,0,0});

    cout<<result;

    return 0;
}