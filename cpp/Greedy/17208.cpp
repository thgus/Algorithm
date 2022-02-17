/*
17208번: 카우버거 알바생
https://www.acmicpc.net/problem/17208
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define ORDERMAX 100
#define MAX 300
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int m,k;
vector<pair<int,int>> order;

void initialize()
{
    cin>>n;
    cin>>m>>k;

    int x,y;
    order.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>x>>y;
        order.push_back({x,y});
    }
}

void solve()
{
    vector<vector<int>> dp(MAX+1,vector<int>(MAX+1,0));
    vector<vector<int>> temp(MAX+1,vector<int>(MAX+1));

    for(int cur=1;cur<=n;cur++){
        int rBuger=order[cur].first;
        int rPotato=order[cur].second;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                if(i<rBuger||j<rPotato){
                    temp[i][j]=dp[i][j];
                }
                else{
                    temp[i][j]=max(dp[i][j],dp[i-rBuger][j-rPotato]+1);
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=temp[i][j];
            }
        }
    }

    cout<<dp[m][k];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}