/*
17070번: 파이프 옮기기 1
https://www.acmicpc.net/problem/17070
*/

#include <iostream>
#include <vector>

#define MAX 16
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> space(MAX+1,vector<int>(MAX+1));
int n;

void initialize()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>space[i][j];
        }
    }
}

void solve()
{
    //가로, 세로, 대각선
    vector<vector<vector<int>>> dp(MAX+1,vector<vector<int>>(MAX+1,vector<int>(3,0)));
    
    dp[1][2][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=3;j<=n;j++){
            if(space[i][j]==1){
                continue;
            }

            if(space[i][j-1]!=1){
                dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][2];
            }
            if(space[i-1][j]!=1){
                dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j][2];
            }
            if(space[i-1][j-1]!=1 && space[i-1][j]!=1 && space[i][j-1]!=1){
                dp[i][j][2]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            }
        }
    }

    cout<<dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}