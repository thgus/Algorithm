/*
16681번: 등산
https://www.acmicpc.net/problem/16681
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
long long d,e;
vector<long long> h;
vector<vector<pair<int,long long>>> road;

void initialize()
{
    cin>>n>>m>>d>>e;
    h.resize(n+1);
    road.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    int a,b,n;
    for(int i=0;i<m;i++){
        cin>>a>>b>>n;
        road[a].push_back({b,n});
        road[b].push_back({a,n});
    }
}

void print_vec(vector<long long> &vec){
    for(int i=1;i<=n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void cal_len(int start, vector<long long> &dist){
    priority_queue<pair<long long,int>> que;
    que.push({0,start});

    while(!que.empty()){
        int cur=que.top().second;
        long long cost=-que.top().first;
        que.pop();

        if(dist[cur]<cost)   continue;

        for(pair<int,long long> p:road[cur]){
            int next=p.first;
            long long ncost=cost+p.second;
            if(h[cur]<h[next]&&dist[next]>ncost){
                dist[next]=ncost;
                que.push({-ncost,next});
            }
        }
    }
}

void solve()
{
    vector<long long> start_to_top(n+1,LLONG_MAX);
    vector<long long> end_to_top(n+1,LLONG_MAX);

    cal_len(1,start_to_top);
    cal_len(n,end_to_top);

    long long result=LLONG_MIN;
    for(int i=2;i<n;i++){
        if(start_to_top[i]==LLONG_MAX||end_to_top[i]==LLONG_MAX)    continue;
        //아 이거 성취감이 소모한 체력보다 크면 값이 -1이 될 수 있으니까
        //최대 가치가 -1이면 result가 Impossible이 나온다..? 그래서 틀린건가
        result=max(result,(h[i]*e)-((start_to_top[i]+end_to_top[i])*d));
    }

    if(result==LLONG_MIN){
        cout<<"Impossible";
    }
    else{
        cout<<result;
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}