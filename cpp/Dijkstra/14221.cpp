/*
14221번: 편의점
https://www.acmicpc.net/problem/14221
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
int p,q;
vector<vector<pair<int,long long>>> vec;
vector<int> classification;

void initialize()
{
    cin>>n>>m;

    int a,b,c;
    vec.resize(n+1);
    classification.resize(n+1,0);

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }

    int num;
    cin>>p>>q;
    for(int i=0;i<p;i++)
    {
        cin>>num;
        classification[num]=1;
    }
    for(int i=0;i<q;i++)
    {
        cin>>num;
        classification[num]=2;
    }
}

struct Node{
    int start;
    int num;
    long long cost;
};

void solve()
{
    vector<long long> dp(n+1,LLONG_MAX);
    queue<Node> que;
    for(int i=0;i<=n;i++)
    {
        if(classification[i]==1)
        {
            dp[i]=0;
            que.push({i,i,0});
        }
    }

    int result=0;
    long long min_cost=LLONG_MAX;
    while(!que.empty())
    {
        Node cur=que.front();
        que.pop();

        if(dp[cur.num]>cur.cost)    continue;
        // 편의점 도착
        if(classification[cur.num]==2)
        {
            if(min_cost>cur.cost) {
                min_cost=cur.cost;
                result=cur.start;
            }
            else if(min_cost==cur.cost){
                if(result>cur.num)  result=cur.start;
            }

            continue;
        }

        for(pair<int,long long> p:vec[cur.num])
        {
            long long ncost=p.second+cur.cost;

            if(dp[p.first]<=ncost) continue;
            dp[p.first]=ncost;
            
            que.push({cur.start,p.first,ncost});
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