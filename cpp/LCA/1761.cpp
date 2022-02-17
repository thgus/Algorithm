/*
1761번: 정점들의 거리
https://www.acmicpc.net/problem/1761
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#define MAX 40000
#define MAXDEPTH 15

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> depth(MAX+1,-1);
vector<vector<int>> parent(MAX+1,vector<int>(MAXDEPTH+1,0));
vector<vector<int>> spendCost(MAX+1,vector<int>(MAXDEPTH+1,0));
vector<int> toStartCost(MAX+1);

int n;

int solve(int a, int b)
{
    int totalScore=0;
    if(depth[a]>depth[b]){
        int temp=b;
        b=a;
        a=temp;
    }

    if(depth[a]!=depth[b]){
        for(int i=MAXDEPTH;i>=0;i--){
            if(depth[b]-depth[a]>=(1<<i)){
                totalScore+=spendCost[b][i];
                b=parent[b][i];
            }
        }
    }

    if(a!=b){
        for(int i=MAXDEPTH;i>=0;i--){
            if(parent[a][i]!=parent[b][i]){
                totalScore+=(spendCost[a][i]+spendCost[b][i]);
                a=parent[a][i];
                b=parent[b][i];
            }
        }

        totalScore+=spendCost[a][0]+spendCost[b][0];
    }

    return totalScore;
}

int LCA(int a, int b){
    if(depth[a]>depth[b]){
        int temp=b;
        b=a;
        a=temp;
    }

    if(depth[a]!=depth[b]){
        for(int i=MAXDEPTH;i>=0;i--){
            if(depth[b]-depth[a]>=(1<<i)){
                b=parent[b][i];
            }
        }
    }

    int result;
    if(a!=b){
        for(int i=MAXDEPTH;i>=0;i--){
            if(parent[a][i]!=parent[b][i]){
                a=parent[a][i];
                b=parent[b][i];
            }
        }
        result=parent[a][0];
    }
    else{
        result=a;
    }

    return result;
}

void makeTree(vector<vector<pair<int,int>>> &vec){
    stack<int> stk;
    stk.push(1);
    depth[1]=1;
    toStartCost[1]=0;

    while(!stk.empty()){
        int cur=stk.top();
        stk.pop();
        
        for(pair<int,int> next:vec[cur]){
            int nextIndex=next.first;
            int nextLenth=next.second;

            if(depth[nextIndex]==-1){
                parent[nextIndex][0]=cur;
                //spendCost[nextIndex][0]=nextLenth;
                toStartCost[nextIndex]=toStartCost[cur]+nextLenth;
                depth[nextIndex]=depth[cur]+1;
                stk.push(nextIndex);
            }
        }
    }

    for(int j=1;j<=MAXDEPTH;j++){
        for(int i=1;i<=n;i++){
            parent[i][j]=parent[parent[i][j-1]][j-1];
            //spendCost[i][j]=spendCost[i][j-1]+spendCost[parent[i][j-1]][j-1];
        }
    }

}

void initialize()
{
    cin>>n;

    int a,b,c;
    vector<vector<pair<int,int>>> vec(MAX+1);
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }

    makeTree(vec);

    int m;
    cin>>m;

    while(m--){
        cin>>a>>b;
        //cout<<solve(a,b)<<"\n";
        cout<<toStartCost[a]+toStartCost[b]-(2*toStartCost[LCA(a,b)])<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}