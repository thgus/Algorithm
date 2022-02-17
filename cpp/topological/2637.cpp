/*
2637번: 장난감 조립
https://www.acmicpc.net/problem/2637
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
vector<vector<int>> need_quantity;
vector<vector<int>> next_part;

void initialize()
{
    cin>>n>>m;

    topology.resize(n+1,0);
    need_quantity.resize(n+1,vector<int>(n+1,0));
    next_part.resize(n+1);

    int x,y,k;
    for(int i=0;i<m;i++){
        cin>>x>>y>>k;
        topology[x]++;
        next_part[y].push_back(x);
        need_quantity[x][y]=k;
    }
}

void print_vec(){
    cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<need_quantity[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    vector<bool> basic_part(n,false);
    queue<int> que;

    for(int i=1;i<=n;i++){
        if(topology[i]==0){
            que.push(i);
            topology[i]=-1;
            need_quantity[i][i]=1;
            basic_part[i]=true;
        }
    }

    while(!que.empty()){
        int cur=que.front();
        que.pop();

        for(int i=0;i<next_part[cur].size();i++){
            int next=next_part[cur][i];
            topology[next]--;

            int mul=need_quantity[next][cur];
            need_quantity[next][cur]=0;
            for(int j=1;j<=n;j++){
                need_quantity[next][j]+=need_quantity[cur][j]*mul;
            }

            if(topology[next]==0){
                que.push(next);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(basic_part[i]){
            cout<<i<<" "<<need_quantity[n][i]<<"\n";
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