/*
17404번: RGB거리 2
https://www.acmicpc.net/problem/17404
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<int[3]> vec(MAX);

void initialize(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
    }
}

void solve(){
    int minCost=1000*1000+1;

    //첫번째 집 case(R,G,B)마다 확인
    for(int i=0;i<3;i++){
        vector<int[3]> dp(MAX);

        for(int j=0;j<3;j++){
            if(i==j){
                dp[0][j]=vec[0][j];
            }
            else{
                dp[0][j]=1000*1000+1;
            }
        }

        for(int j=1;j<n;j++){
            dp[j][0]=min(dp[j-1][1],dp[j-1][2])+vec[j][0];
            dp[j][1]=min(dp[j-1][0],dp[j-1][2])+vec[j][1];
            dp[j][2]=min(dp[j-1][0],dp[j-1][1])+vec[j][2];
        }
        
        for(int j=0;j<3;j++){
            if(j==i){
                continue;
            }

            if(minCost>dp[n-1][j]){
                minCost=dp[n-1][j];
            }
        }
    }

    cout<<minCost;

}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}