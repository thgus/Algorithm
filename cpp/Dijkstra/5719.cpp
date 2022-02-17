/*
5719번: 거의 최단 경로
https://www.acmicpc.net/problem/5719
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node{
    int cost=1e9;
    vector<int> pre;
};

void print_vec(vector<vector<int>> &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(vector<vector<int>> &route, int s, int d, int n)
{
    vector<Node> visited(n);
    priority_queue<pair<int,int>> pq;

    pq.push({0,s});

    visited[s].cost=0;
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(cur==d){
            break;
        }

        for(int next=0;next<n;next++){
            if(route[cur][next]==-1)    continue;
            int ncost=cost+route[cur][next];
            if(visited[next].cost>ncost){
                visited[next].cost=ncost;
                visited[next].pre.clear();
                visited[next].pre.push_back(cur);
                pq.push({-ncost,next});
            }
            else if(visited[next].cost==ncost){
                visited[next].pre.push_back(cur);
            }
        }
    }

    queue<int> que;
    vector<bool> isVisited(n,false);
    isVisited[d]=true;
    que.push(d);
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        for(int pre:visited[cur].pre){
            route[pre][cur]=-1;
            if(isVisited[pre])  continue;
            isVisited[pre]=true;
            que.push(pre);
        }
    }

    priority_queue<pair<int,int>> prq;
    vector<int> vt(n,1e9);
    vt[s]=0;
    prq.push({0,s});
    while(!prq.empty()){
        int cost=-prq.top().first;
        int cur=prq.top().second;
        prq.pop();

        if(cur==d){
            cout<<cost<<"\n";
            return;
        }

        for(int next=0;next<n;next++){
            if(route[cur][next]==-1)    continue;
            int ncost=cost+route[cur][next];
            if(vt[next]>ncost){
                vt[next]=ncost;
                prq.push({-ncost,next});
            }
        }
    }

    cout<<"-1\n";
}

void initialize()
{
    int n,m;
    int s,d;

    while(1){
        cin>>n>>m;
        if(n==0&&m==0)  break;

        vector<vector<int>> route(n,vector<int>(n,-1));
        cin>>s>>d;

        int u,v,p;
        for(int i=0;i<m;i++){
            cin>>u>>v>>p;
            route[u][v]=p;
        }

        solve(route,s,d,n);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}