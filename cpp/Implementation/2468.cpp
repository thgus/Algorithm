/*
2468번: 안전 영역
https://www.acmicpc.net/problem/2468
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> vec;
set<int> s;

void initialize()
{
    cin>>n;
    vec.resize(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];

            s.insert(vec[i][j]);
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

int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(vector<vector<bool>> &visited, int y, int x){
    queue<pair<int,int>> que;
    que.push({y,x});
    while(!que.empty()){
        int cy=que.front().first;
        int cx=que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];
            if(!isBoundary(ny,nx))   continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            que.push({ny,nx});
        }
    }

}

void solve()
{
    int result=1;
    for(auto it=s.begin();it!=s.end();it++){
        int cur_h=*(it);
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                visited[y][x]=(vec[y][x]<=cur_h)?true:false;
            }
        }

        int sum=0;
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(visited[y][x])   continue;
                sum++;
                dfs(visited,y,x);
            }
        }

        result=max(result,sum);
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