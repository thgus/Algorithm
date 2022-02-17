/*
14728번: 벼락치기
https://www.acmicpc.net/problem/14728
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100
#define TIMEMAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,t;
vector<pair<int,int>> vec;

void initialize()
{
    cin>>n>>t;
    int k,s;
    vec.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>k>>s;
        vec.push_back({k,s});
    }
}

void solve()
{
    vector<vector<int>> dp(MAX+1,vector<int>(TIMEMAX+1,0));
    for(int cur=1;cur<=n;cur++){
        int curTime=vec[cur].first;
        int curScore=vec[cur].second;

        for(int i=1;i<=t;i++){
             if(i<curTime){
                 dp[cur][i]=dp[cur-1][i];
             }
             else{
                 dp[cur][i]=max(dp[cur-1][i-curTime]+curScore,dp[cur-1][i]);
             }
        }
    }
    cout<<dp[n][t];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}