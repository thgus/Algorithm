/*
2398번: 3인통화
https://www.acmicpc.net/problem/2398
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

int n,m;
vector<vector<pair<int,int>>> route;
int a,b,c;

void initialize()
{
    cin>>n>>m;
    route.resize(n+1);

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        route[a].push_back({b,c});
        route[b].push_back({a,c});
    }
    cin>>a>>b>>c;
}

void bfs(vector<int> &visited, vector<int> &r, int start){
    queue<pair<int,int>> que;
    que.push({0,start});
    visited[start]=0;

    while(!que.empty()){
        int cur=que.front().second;
        int cost=que.front().first;
        que.pop();

        if(visited[cur]>cost)  continue;

        for(pair<int,int> p:route[cur]){
            int next=p.first;
            int ncost=cost+p.second;
            
            if(visited[next]>ncost){
                visited[next]=ncost;
                r[next]=cur;
                que.push({ncost,next});
            }            
        }
    }
}

void backTracking(vector<pair<int,int>> &node, vector<int> &r, int start, int end){
    int cur=start;
    while(cur!=end){
        int pre=r[cur];

        if(cur>pre){
            node.push_back({pre,cur});
        }
        else{
            node.push_back({cur,pre});
        }
        cur=pre;
    }
}

void solve()
{
    vector<int> cost1(n+1,1e9);
    vector<int> cost2(n+1,1e9);
    vector<int> cost3(n+1,1e9);

    vector<int> r1(n+1,-1);
    vector<int> r2(n+1,-1);
    vector<int> r3(n+1,-1);

    bfs(cost1,r1,a);
    bfs(cost2,r2,b);
    bfs(cost3,r3,c);

    int result=1e9;
    vector<pair<int,int>> node;
    int index=0;

    for(int i=1;i<=n;i++){
        int cur_cost=cost1[i]+cost2[i]+cost3[i];
        if(result>cur_cost){
            result=cur_cost;
            index=i;
        }
    }
    
    backTracking(node,r1,index,a);
    backTracking(node,r2,index,b);
    backTracking(node,r3,index,c);

    sort(node.begin(),node.end());

    cout<<result<<" "<<node.size()<<"\n";
    for(pair<int,int> p:node){
        cout<<p.first<<" "<<p.second<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}