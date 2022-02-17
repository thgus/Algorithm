/*
1766번: 문제집
https://www.acmicpc.net/problem/1766
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
vector<int> topology;
vector<vector<int>> next_solve;

void initialize()
{
    cin>>n>>m;
    topology.resize(n+1,0);
    next_solve.resize(n+1);

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        next_solve[a].push_back(b);
        topology[b]++;
    }
}

void solve()
{
    priority_queue<int> que;
    queue<int> seq;

    for(int i=1;i<=n;i++){
        if(topology[i]==0){
            topology[i]=-1;
            que.push(-i);
        }
    }

    while(!que.empty()){
        int cur=-que.top();
        que.pop();

        seq.push(cur);

        for(int i=0;i<next_solve[cur].size();i++){
            int next=next_solve[cur][i];
            if(--topology[next]==0){
                que.push(-next);
            }
        }
    }
    

    while(!seq.empty()){
        cout<<seq.front()<<" ";
        seq.pop();
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}