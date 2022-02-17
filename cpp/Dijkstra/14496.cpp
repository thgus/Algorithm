/*
14496번: 그대, 그머가 되어
https://www.acmicpc.net/problem/14496
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int a,b;
int n,m;
vector<vector<int>> route;

void initialize()
{
    cin>>a>>b;
    a--;    b--;

    cin>>n>>m;
    route.resize(n);

    int s,e;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        route[s-1].push_back(e-1);
        route[e-1].push_back(s-1);
    }
}

void solve()
{
    vector<int> visited(n,false);
    queue<pair<int,int>> que;
    que.push({a,0});
    visited[a]=true;

    while(!que.empty()){
        int num=que.front().first;
        int cost=que.front().second;
        que.pop();

        if(num==b){
            cout<<cost;
            return;
        }

        for(int next:route[num]){
            if(visited[next])   continue;
            visited[next]=true;
            que.push({next,cost+1});
        }
    }

    cout<<"-1";
    return;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}