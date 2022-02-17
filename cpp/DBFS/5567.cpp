/*
5567번: 결혼식
https://www.acmicpc.net/problem/5567
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
vector<vector<int>> f;

void initialize()
{
    cin>>n>>m;
    f.resize(n);
    int a,b;
    while(m--){
        cin>>a>>b;
        f[a-1].push_back(b-1);
        f[b-1].push_back(a-1);
    }
}

void solve()
{
    vector<bool> visited(n,false);
    visited[0]=true;

    int people_num=-1;
    queue<pair<int,int>> que;
    que.push({0,0});

    while(!que.empty()){
        int cur=que.front().first;
        int len=que.front().second;
        que.pop();

        people_num++;
        if(len==2){
            continue;
        }

        for(int next:f[cur]){
            if(visited[next])   continue;
            visited[next]=true;
            que.push({next,len+1});
        }
    }

    cout<<people_num;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}