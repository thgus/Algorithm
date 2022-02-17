/*
16562번: 친구비
https://www.acmicpc.net/problem/16562
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FMAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<int> frendCost(FMAX+1);
vector<vector<int>> gfriend(FMAX+1);

void initialize()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>frendCost[i];
    }
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        gfriend[a].push_back(b);
        gfriend[b].push_back(a);
    }
}

vector<int> parent(FMAX+1);

int findParent(int n){
    if(parent[n]==n){
        return n;
    }
    else{
        return parent[n]=findParent(parent[n]);
    }
}

void makeUnion(int a,int b){
    int ap=findParent(a);
    int bp=findParent(b);
    parent[ap]=bp;
}

long long bfs(vector<bool> &isVisited, int s){
    queue<int> que;
    que.push(s);
    isVisited[s]=true;

    int minCost=987654321;
    
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        minCost=min(minCost,frendCost[cur]);

        for(int i=0;i<gfriend[cur].size();i++){
            int next=gfriend[cur][i];
            if(!isVisited[next]){
                que.push(next);
                //makeUnion(cur,next);
                isVisited[next]=true;

            }
        }
    }

    return minCost;
}  

void solve()
{
    vector<bool> isVisited(FMAX+1, false);

    long long needCost=0;
    for(int i=1;i<=n;i++){
        if(isVisited[i]){
            continue;
        }
        needCost+=bfs(isVisited,i);
    }

    if(needCost<=k){
        cout<<needCost;
    }
    else{
        cout<<"Oh no";
    }
}

int main()
{
    initialize();
    solve();

    return 0;
}