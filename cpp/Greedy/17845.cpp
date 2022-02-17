/*
17845번: 수강 과목
https://www.acmicpc.net/problem/17845
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
vector<pair<int,int>> vec;

void initialize()
{
    cin>>n>>k;
    vec.push_back({0,0});
    int l,t;
    for(int i=1;i<=k;i++){
        cin>>l>>t;
        vec.push_back({l,t});
    }
}

void solve()
{
    vector<int> dp(n+1,0);
    for(int cur=1;cur<=k;cur++){
        int curIm=vec[cur].first;
        int curTime=vec[cur].second;
        
        for(int i=n;i>0;i--){
            if(i<curTime){
                break;
            }
            dp[i]=max(dp[i],dp[i-curTime]+curIm);
        }
    }
    cout<<dp[n];
}

int main()
{
    initialize();
    solve();

    return 0;
}