/*
1981번: 배열에서 이동
https://www.acmicpc.net/problem/1981

//여기서 최소값으 정해주고
//bfs를 통해서 차이가 가장 작은 값을 result로 갱신
//만약 현재 최소값으로는 목표지점에 도달할 수 없다면 최소값을 더 내리고
//목표지점에 도달할 수 있다면 최소값을 올림.
//(최소값보다 크거나 같은 가장 작은 값이 최대값)
    => 이건 만약 목표지점에 도달할 수 있어서 최소값을 올렸는데 
        그 최소값 아래에서 최대 최소 차이 값이 더 적게 나올 수 있는 경우가 있어서 오답.
        생각해보면 당연한건데 이걸 생각 못했네;;


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

int n;
vector<vector<int>> vec;

void initialize()
{
    cin>>n;
    vec.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
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

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int result=1e9;
bool dfs(int min_num, int max_num){
    if(vec[0][0]<min_num || vec[0][0]>max_num)   return false;

    queue<pair<int,int>> que;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    que.push({0,0});
    visited[0][0]=true;

    while(!que.empty()){
        int cy=que.front().first;
        int cx=que.front().second;
        que.pop();

        if(cy==n-1&&cx==n-1){
            return true;
        }

        for(int i=0;i<4;i++){
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(!isBoundary(ny,nx))  continue;
            if(vec[ny][nx]<min_num || vec[ny][nx]>max_num) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            que.push({ny,nx});
        }
    }

    return false;
}

bool isCan(int dif){
    for(int i=0;i+dif<=200;i++){
        if(dfs(i,i+dif)){
            result=min(result,dif);
            return true;
        }
    }
    return false;
}

void solve()
{
    int left,right;
    left=0;
    right=200;

    while(left<=right){
        int mid=(left+right)/2;
        if(isCan(mid)){
            right=mid-1;
        }
        else{
            left=mid+1;
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