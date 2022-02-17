/*
14501번: 퇴사
https://www.acmicpc.net/problem/14501
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 15
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> vec(MAX+1);

void initialize(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
}

vector<int> dp(MAX,0);
void solve(){
    for(int i=0;i<n;i++){
        int day=vec[i].first;
        int cost=vec[i].second;

        for(int j=i+day;j<=n;j++){
            dp[j]=max(dp[i]+cost,dp[j]);
        }
    }

    cout<<dp[n];
}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}