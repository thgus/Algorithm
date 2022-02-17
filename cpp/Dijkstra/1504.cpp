/*
1504번: 특정한 최단 경로
https://www.acmicpc.net/problem/1504

이거 왜 안되냐;;
*/

#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

#define MAX 800
#define INF 20000*1000*2+1

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,e;
int v1,v2;
vector<vector<pair<int,int>>> vec(MAX+1,vector<pair<int,int>>(0));

void initialize()
{
    cin>>n>>e;
    int a,b,c;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    cin>>v1>>v2;
}

long long findRoute(int s, int d){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;
    vector<bool> visit(MAX+1,false);
    que.push({0,s});

    while(!que.empty()){
        long long len=que.top().first;
        int start=que.top().second;
        que.pop();

        if(start==d){
            return len;
        }

        if(visit[start]){
            continue;
        }
        visit[start]=true;

        for(int i=0;i<vec[start].size();i++){
            int to=vec[start][i].first;
            int cost=vec[start][i].second;

            que.push({len+cost,to});
        }
    }
    return INF;
}

void solve()
{
    long long route1, route2;
    bool flag1,flag2;

    int v=findRoute(v1,v2);

    route1=findRoute(1,v1);
    route2=findRoute(1,v2);

    route1+=findRoute(v2,n);
    route2+=findRoute(v1,n);

    if((route1>=INF&&route2>=INF)||v==INF){
        cout<<"-1";
    }
    else{
        cout<<min(route1,route2)+v;
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}