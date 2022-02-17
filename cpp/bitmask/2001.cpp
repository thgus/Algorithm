/*
2001번: 보석 줍기
https://www.acmicpc.net/problem/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<vector<pair<int,int>>> route;
vector<int> jewelry;

void initialize()
{
    cin>>n>>m>>k;
    route.resize(n+1);
    jewelry.resize(n+1,-1);

    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        jewelry[temp]=i;
    }

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        route[a].push_back({b,c});
        route[b].push_back({a,c});
    }
}

struct Node{
    int weight;
    int key;
    int cur;
};

void solve()
{
    int result=0;

    queue<Node> que;
    vector<vector<bool>> visited(1<<k,vector<bool>(n+1,false));
    
    que.push({0,0,1});

    while(!que.empty()){
        int cur=que.front().cur;
        int weight=que.front().weight;
        int key=que.front().key;
        que.pop();

        int nkey=key;
        int nweight=weight+1;

        visited[key][cur]=true;

        if(jewelry[cur]!=-1 && ~key&(1<<jewelry[cur])){
            nkey|=(1<<jewelry[cur]);
            visited[nkey][cur]=true;
        }

        if(cur==1){
            if(nkey!=key){
                result=max(result,nweight);
            }
            else{
                result=max(result,weight);
            }
        }

        for(pair<int,int> p:route[cur]){
            int next=p.first;
            int limit=p.second;

            if(!visited[key][next]&&limit>=weight){
                visited[key][next]=true;
                que.push({weight,key,next});
            }

            if(!visited[nkey][next]&&limit>=nweight){
                visited[nkey][next]=true;
                que.push({nweight,nkey,next});
            }
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