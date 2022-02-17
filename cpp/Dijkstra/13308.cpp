/*
13308번: 주유소
https://www.acmicpc.net/problem/13308
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<int> cost;
vector<vector<pair<int,long long>>> road;

void initialize()
{
    cin>>n>>m;
    cost.resize(n+1);
    road.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }   

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }
}

struct Node{
    long long cost;
    int num;
    int oil_price;

    bool operator<(const Node node) const {
        return node.cost<cost;
    }
};

void solve()
{
    vector<vector<long long>> visited(n+1,vector<long long>(2501,LLONG_MAX));
    priority_queue<Node> que;
    que.push({0,1,cost[1]});
    visited[1][cost[1]]=0;

    while(!que.empty()){
        Node node=que.top();
        que.pop();

        if(node.num==n){
            cout<<node.cost;
            break;
        }

        if(visited[node.num][node.oil_price]<node.cost) continue;

        for(pair<int,int> p:road[node.num]){
            long long next_cost=node.cost+node.oil_price*p.second;
            if(visited[p.first][node.oil_price]<=next_cost)  continue;
            visited[p.first][node.oil_price]=next_cost;
            if(cost[p.first]<node.oil_price){
                que.push({next_cost,p.first,cost[p.first]});
            }
            else{
                que.push({next_cost,p.first,node.oil_price});
            }
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