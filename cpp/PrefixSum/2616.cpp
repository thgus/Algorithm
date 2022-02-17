/*
2616번: 소형기관차
https://www.acmicpc.net/problem/2616
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    cin>>k;
}

void solve()
{
    vector<int> sum;
    sum.resize(n+1);
    int s=0;
    for(int i=1;i<=n;i++){
        s+=vec[i];
        sum[i]=s;
    }

    vector<vector<int>> dp(4,vector<int>(n+1,0));
    // 기차
    for(int i=1;i<=3;i++){
        //객차
        for(int j=i*k;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-k]+(sum[j]-sum[j-k]));
        }   
    }
    cout<<dp[3][n];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}