/*
1854번: K번째 최단경로 찾기
https://www.acmicpc.net/problem/1854
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<vector<pair<int,int>>> route;

void initialize()
{
    cin>>n>>m>>k;
    route.resize(n+1);

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        route[a].push_back({b,c});
    }
}

void solve()
{
    vector<pair<int,int>> visited(n+1,{0,-1});
    priority_queue<pair<int,int>> que;

    que.push({0,1});
    while(!que.empty()){
        int cur=que.top().second;
        int cost=-que.top().first;
        que.pop();

        if(visited[cur].first>=k)   continue;
        visited[cur].first++;
        visited[cur].second=cost;

        for(pair<int,int> p:route[cur]){
            int next=p.first;
            int ncost=cost+p.second;

            if(visited[next].first>=k)  continue;
            que.push({-ncost,next});
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i].first==k){
            cout<<visited[i].second<<"\n";
        }
        else{
            cout<<"-1\n";
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