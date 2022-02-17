/*
1240번: 노드사이의 거리
https://www.acmicpc.net/problem/1240
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
vector<vector<pair<int,int>>> tree;

void initialize()
{
    cin>>n>>m;
    tree.resize(n);

    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        tree[a-1].push_back({b-1,c});
        tree[b-1].push_back({a-1,c});
    }
}

void clear_visited(vector<bool> &visited){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
}  

void solve()
{
    int a,b;
    vector<bool> visited(n);

    while(m--){
        cin>>a>>b;
        
        queue<pair<int,int>> que;
        clear_visited(visited);

        que.push({a-1,0});
        visited[a-1]=true;

        while(!que.empty()){
            int cur=que.front().first;
            int len=que.front().second;
            que.pop();

            if(cur==b-1){
                cout<<len<<"\n";
                break;
            }

            for(pair<int,int> next:tree[cur]){
                if(visited[next.first])   continue;
                visited[next.first]=true;
                que.push({next.first,len+next.second});
            }
        }
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}