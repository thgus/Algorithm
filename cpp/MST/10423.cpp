/*
10423번: 전기가 부족해
https://www.acmicpc.net/problem/10423
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int find_parent(vector<int> &parent, int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=find_parent(parent,parent[i]);
    }
}

int main()
{
    sync_off;

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>> route(n+1);
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    int root,temp;
    cin>>root;
    for(int i=1;i<k;i++){
        cin>>temp;
        parent[temp]=root;
    }

    int a,b,c;
    priority_queue<pair<int,pair<int,int>>> que;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        que.push({-c,{a,b}});
    }

    int sum=0;
    while(!que.empty()){
        int cost=-que.top().first;
        a=que.top().second.first;
        b=que.top().second.second;
        que.pop();

        int ap=find_parent(parent,a);
        int bp=find_parent(parent,b);
        if(ap!=bp){
            parent[bp]=ap;
            sum+=cost;
        }
    }
    cout<<sum;

    return 0;
}