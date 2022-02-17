/*
2463번: 비용
https://www.acmicpc.net/problem/2463
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node{
    int a,b;
    int cost;

    bool operator<(const Node n)const{
        return cost<n.cost;
    }
};

int n,m;
priority_queue<Node> que;
long long total_cost;

void initialize()
{
    total_cost=0;
    cin>>n>>m;

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        que.push({a,b,c});

        total_cost+=c;
    }
}

int find_parent(vector<int> &parent, int i){
    if(i==parent[i]){
        return i;
    }
    else{
        return parent[i]=find_parent(parent,parent[i]);
    }
}

void solve()
{
    vector<int> parent(n+1);
    vector<long long> group_size(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;  
        group_size[i]=1;     
    }

    long long result=0;
    while(!que.empty()){
        Node cur=que.top();
        que.pop();

        int ap=find_parent(parent,cur.a);
        int bp=find_parent(parent,cur.b);

        if(ap!=bp){   
            if(ap>bp){
                int temp=ap;
                ap=bp;
                bp=temp;
            }
            result+=total_cost*group_size[ap]*group_size[bp];
            result%=1000000000;
            parent[bp]=ap;
            group_size[ap]+=group_size[bp];        
        }        
        total_cost-=cur.cost;
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