/*
16474번: 이상한 전깃줄
https://www.acmicpc.net/problem/16474
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
//vector<pair<int,int>> vec;
vector<vector<bool>> vec;
int k;

void initialize()
{
    cin>>n>>m;
    map<int,int> m1;
    map<int,int> m2;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        m1.insert({temp,i});
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        m2.insert({temp,i});
    }

    cin>>k;
    vec.resize(n,vector<bool>(m,false));
    int a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        vec[m1.find(a)->second][m2.find(b)->second]=true;
    }
}

vector<vector<int>> dp;
void solve()
{
    dp.resize(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(vec[i-1][j-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }

    int result=-1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            result=max(result,dp[i][j]);
        }
    }

    cout<<k-result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}