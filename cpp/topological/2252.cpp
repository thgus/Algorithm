/*
2252번: 줄 세우기
https://www.acmicpc.net/problem/2252
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 32000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> comp(MAX+1);
vector<int> enter(MAX+1,0);

void initialize()
{
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        comp[a].push_back(b);
        enter[b]++;
    }
}

void solve()
{
    queue<int> que;
    for(int cur=1;cur<=n;cur++){
        if(enter[cur]==0){
            que.push(cur);
        }
    }

    vector<int> result;
    while(!que.empty()){
        int cur=que.front();
        result.push_back(cur);
        que.pop();

        for(int i=0;i<comp[cur].size();i++){
            int next=comp[cur][i];
            if(--enter[next]==0){
                que.push(next);
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}