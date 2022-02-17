/*
10217번: KCM Travel
https://www.acmicpc.net/problem/10217
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

struct Route{
    int v;
    int cost,time;
};

struct Node{
    int num;
    int remaining_cost;
    int spend_time;

    bool operator<(const Node node)const{
        return node.spend_time<spend_time;
    }
};

void solve(vector<vector<Route>> &route,int n, int m)
{
    vector<vector<int>> visited(n+1,vector<int>(m+1,1e9));
    priority_queue<Node> que;
    que.push({1,m,0});
    visited[1][m]=0;

    while(!que.empty()){
        Node cur=que.top();
        que.pop();

        if(visited[cur.num][cur.remaining_cost]>cur.spend_time) continue;

        for(auto next:route[cur.num]){
            int next_cost=cur.remaining_cost-next.cost;
            int next_time=cur.spend_time+next.time;

            if(next_cost<0) continue;
            
            if(visited[next.v][next_cost]>next_time){
                visited[next.v][next_cost]=next_time;
                que.push({next.v,next_cost,next_time});
            }
        }
    }

    int min_len=1e9;
    for(int i=0;i<=m;i++){
        min_len=min(min_len,visited[n][i]);
    }

    if(min_len==1e9){
        cout<<"Poor KCM\n";
    }
    else{
        cout<<min_len<<"\n";
    }
}

void initialize()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        //vec[공항][남은 지원 비용]=소요 시간
        vector<vector<Route>> route(n+1);
        int u,v,c,d;
        for(int i=0;i<k;i++){
            cin>>u>>v>>c>>d;
            route[u].push_back({v,c,d});
        }  

        solve(route,n, m);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}