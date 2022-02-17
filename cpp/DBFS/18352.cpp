/*
18352번: 특정 거리의 도시 찾기
https://www.acmicpc.net/problem/18352
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

int n,k,x;
vector<vector<int>> route;

void initialize()
{
    int m;
    cin>>n>>m>>k>>x;
    route.resize(n);
    int a,b;
    while(m--){
        cin>>a>>b;
        route[a-1].push_back(b-1);
    }
}

void solve()
{
    vector<bool> visited(n,false);
    visited[x-1]=true;

    vector<int> result;
    queue<pair<int,int>> que;
    que.push({x-1,0});
    while(!que.empty()){
        int cur=que.front().first;
        int cost=que.front().second;
        que.pop();

        if(cost==k){
            result.push_back(cur);
            continue;
        }

        for(int next:route[cur]){
            if(visited[next])   continue;
            visited[next]=true;
            que.push({next,cost+1});
        }
    }

    if(result.empty()){
        cout<<"-1";
    }
    else{
        sort(result.begin(),result.end());
        for(int cur:result){
            cout<<cur+1<<"\n";
        }
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}