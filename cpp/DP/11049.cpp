/*
11049번: 행렬 곱셈 순서
https://www.acmicpc.net/problem/11049

연쇄행렬곱셈
공부했었는데 까먹었어;; 다시공부해야해
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500
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
    int r,c;
    cin>>r>>c;
    vec.push_back(r);
    vec.push_back(c);
    for(int i=1;i<n;i++){
        cin>>r>>c;
        vec.push_back(c);
    }
}

vector<vector<int>> dp(MAX+1,vector<int>(MAX+1,0));

void printDP(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            int y=j;
            int x=i+j;

            int minValue=2147483647;
            for(int k=j;k<x;k++){
                minValue=min(minValue,dp[y][k]+dp[k+1][x]+vec[j-1]*vec[k]*vec[x]);
            }
            dp[y][x]=minValue;
        }
    }

    cout<<dp[1][n];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}