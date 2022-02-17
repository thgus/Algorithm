/*
1311번: 할 일 정하기 1
https://www.acmicpc.net/problem/1311
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> cost;

void initialize()
{
    cin>>n;
    cost.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
}

struct Node{
    int len;
    int bit;
};

void solve()
{
    vector<int> dp(1<<n, 1e9);
    
    queue<Node> que;
    for(int i=0;i<n;i++){
        dp[(1<<i)]=cost[0][i];
        que.push({1,(1<<i)});
    }

    while(!que.empty()){
        Node cur=que.front();
        que.pop();

        for(int i=0;i<n;i++){
            if(cur.bit&(1<<i))  continue;
            int next_bit=cur.bit|(1<<i);
            if(dp[next_bit]==1e9){
                que.push({cur.len+1,next_bit});
            }

            dp[next_bit]=min(dp[next_bit],dp[cur.bit]+cost[cur.len][i]);
        }
    }

    cout<<dp[(1<<n)-1];

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}