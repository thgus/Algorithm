/*
11055번: 가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11055
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n+1);

    vec[0]=0;
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){  
        dp[i]=vec[i];
        for(int j=1;j<i;j++){
            if(vec[j]<vec[i]){
                dp[i]=max(dp[i],dp[j]+vec[i]);
            }
        }
    }

    int max_sum=0;
    for(int i=1;i<=n;i++){
        //cout<<dp[i]<<" ";
        max_sum=max(max_sum,dp[i]);
    }

    cout<<max_sum;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}