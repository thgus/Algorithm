/*
15591번: MooTube (Silver)
https://www.acmicpc.net/problem/15591
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 5000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,q;
vector<vector<pair<int,int>>> vec(MAX+1);

int solve(int s, int r)
{    
    queue<int> que;
    que.push({s});

    vector<bool> isVisited(n+1,false);
    isVisited[s]=true;

    int count=-1;
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        count++;
        
        for(int i=0;i<vec[cur].size();i++){
            int next=vec[cur][i].first;
            int usado=vec[cur][i].second;
            if(isVisited[next] || usado<r){
                continue;
            }
            isVisited[next]=true;
            que.push(next);
        }
    }
    return count;
}

void initialize()
{
    cin>>n>>q;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }

    int k,v;
    for(int i=0;i<q;i++){
        cin>>k>>v;
        cout<<solve(v,k)<<"\n";
    }
}

int main()
{
    initialize();
    return 0;
}