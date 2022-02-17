/*
11952번: 좀비
https://www.acmicpc.net/problem/11952
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

int n,m,k,s;
int p,q;

vector<vector<int>> route;
vector<int> infection_city;

void initialize()
{
    cin>>n>>m>>k>>s;
    route.resize(n+1);

    cin>>p>>q;
    int city;
    for(int i=0;i<k;i++){
        cin>>city;
        infection_city.push_back(city);
    }

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        route[a].push_back(b);
        route[b].push_back(a);
    }
}

struct Node{
    long long cost;
    int num;

    bool operator<(const Node node) const {
        return node.cost<cost;
    }
};

void solve()
{
    //0: 안전, 1:위험 2:감염
    vector<int> isInfect(n+1,0);
    for(int i=0;i<k;i++){
        int start=infection_city[i];
        
        queue<Node> que;
        vector<int> visited(n+1,0);
        que.push({start,0});
        visited[start]=2;
        
        while(!que.empty()){
            int cur=que.front().cost;
            int cost=que.front().num;
            que.pop();

            if(cost>=s) continue;
            for(int next:route[cur]){
                if(visited[next]) continue;
                visited[next]=1;
                que.push({next,cost+1});
            }
        }

        for(int j=1;j<=n;j++){
            isInfect[j]=max(isInfect[j],visited[j]);
        }
    }

    vector<long long> visited(n+1,LLONG_MAX);
    priority_queue<Node> pq;
    pq.push({0,1});
    visited[1]=0;

    while(!pq.empty()){
        long long cost=pq.top().cost;
        int cur=pq.top().num;
        pq.pop();

        if(visited[cur]>cost)   continue;
        if(cur==n){
            cost-=(isInfect[n])?q:p;
            cout<<cost;
            break;
        }

        for(int next:route[cur]){
            long long ncost=cost;
            if(isInfect[next]==0){
                ncost+=p;
            }
            else if(isInfect[next]==1){
                ncost+=q;
            }
            else if(isInfect[next]==2){
                continue;
            }

            if(visited[next]<=ncost) continue;
            visited[next]=ncost;
            pq.push({ncost,next});
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