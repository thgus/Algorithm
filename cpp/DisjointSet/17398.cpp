/*
17398번: 통신망 분할
https://www.acmicpc.net/problem/17398
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<pair<int,int>> vec(MAX+1);
vector<bool> isConnected(MAX+1,true);
vector<int> index(MAX+1);
int n,m,q;

void initialize()
{
    cin>>n>>m>>q;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    for(int i=1;i<=q;i++){
        cin>>index[i];
        isConnected[index[i]]=false;
    }
}

vector<int> parent(MAX+1);
int findParent(int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=findParent(parent[i]);
    }
}

void solve()
{
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    vector<long long> cost(MAX+1,1);
    for(int i=1;i<=m;i++){
        if(isConnected[i]){
            int ap=findParent(vec[i].first);
            int bp=findParent(vec[i].second);
            if(ap!=bp){
                parent[bp]=ap;
                cost[ap]+=cost[bp];
            }
        }
    }

    long long result=0;
    for(int i=q;i>0;i--){
        int cura=vec[index[i]].first;
        int curb=vec[index[i]].second;

        int ap=findParent(cura);
        int bp=findParent(curb);
        if(ap!=bp){
            result+=cost[bp]*cost[ap];
            parent[bp]=ap;
            cost[ap]+=cost[bp];
        }
    }  

    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}