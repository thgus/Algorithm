/*
2211번: 네트워크 복구
https://www.acmicpc.net/problem/2211
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<pair<int,int>>> network;

void initialize()
{
    cin>>n>>m;
    network.resize(n+1);

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        network[a].push_back({b,c});
        network[b].push_back({a,c});
    }
}

void solve()
{
    priority_queue<pair<int,pair<int,int>>> que;
    vector<int> isVisited(n+1,1e9);
    vector<pair<int,int>> result;

    que.push({0,{-1,1}});
    isVisited[1]=0;
    while(!que.empty()){
        int cur_cost=-que.top().first;
        int cur=que.top().second.second;
        int pre=que.top().second.first;
        que.pop();

        if(isVisited[cur]<cur_cost)   continue;
        result.push_back({pre,cur});

        for(pair<int,int> p:network[cur]){
            int next=p.first;
            int next_cost=cur_cost+p.second;

            if(isVisited[next]>next_cost){
                isVisited[next]=next_cost;
                que.push({-next_cost,{cur,next}});
            }
        }
    }

    cout<<result.size()-1<<"\n";
    for(int i=1;i<result.size();i++){
        cout<<result[i].first<<" "<<result[i].second<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}