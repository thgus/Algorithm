/*
21924번: 도시 건설
https://www.acmicpc.net/problem/21924
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
priority_queue<pair<int,pair<int,int>>> pq;
long long total_route=0;

void initialize()
{
    cin>>n>>m;    
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        total_route+=c;
        pq.push({-c,{a-1,b-1}});
    }
}

vector<int> parent;
int find_parent(int a){
    if(parent[a]==a)    return a;
    return parent[a]=find_parent(parent[a]);
}

void solve()
{
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    long long cur_len=0;
    while(!pq.empty()){
        int len=-pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();

        int ap=find_parent(a);
        int bp=find_parent(b);
        if(ap==bp)  continue;
        parent[ap]=bp;
        cur_len+=len;
    }

    int top=find_parent(0);
    for(int i=1;i<n;i++){
        if(top!=find_parent(i)){
            cout<<"-1";
            return;
        }
    }
    cout<<total_route-cur_len;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}