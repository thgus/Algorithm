/*
16724번: 피리 부는 사나이
https://www.acmicpc.net/problem/16724
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c;
vector<vector<char>> vec(MAX,vector<char>(MAX));

void initialize()
{
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>vec[i][j];
        }
    }
}

vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,false));
vector<vector<pair<int,int>>> parent(MAX,vector<pair<int,int>>(MAX));
pair<int,int> findParent(pair<int,int> p){
    int y=p.first;
    int x=p.second;

    if(parent[y][x].second==x && parent[y][x].first==y){
        return make_pair(y,x);
    }
    else{
        return parent[y][x]=findParent(parent[y][x]);
    }
}
void makeUnion(pair<int,int> a, pair<int,int> b){
    pair<int,int> ap=findParent(a);
    pair<int,int> bp=findParent(b);
    parent[ap.first][ap.second]=bp;
}

void bfs(pair<int,int> s){
    queue<pair<int,int>> que;
    isVisited[s.first][s.second]=true;
    que.push(s);

    while(!que.empty()){
        pair<int,int> cur=que.front();
        que.pop();

        int y=cur.first;
        int x=cur.second;

        int nexty,nextx;

        switch(vec[y][x]){
            case 'U':
                y-=1;
                break;
            case 'D':
                y+=1;
                break;
            case 'L':
                x-=1;
                break;
            case 'R':
                x+=1;
                break;
        }

        if(y>=0&&y<r&&x>=0&&x<c){
            pair<int,int> next=make_pair(y,x);
            makeUnion(cur,next);
            if(!isVisited[y][x]){
                isVisited[y][x]=true;
                que.push(next);
            }
        }

    }
    
}

void solve()
{
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            parent[i][j].first=i;
            parent[i][j].second=j;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(isVisited[i][j]){
                continue;
            }
            bfs(make_pair(i,j));
        }
    }

    vector<vector<bool>> isSafe(MAX,vector<bool>(MAX,false));
    int result=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            pair<int,int> temp=findParent(make_pair(i,j));
            if(!isSafe[temp.first][temp.second]){
                result++;
                isSafe[temp.first][temp.second]=true;
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