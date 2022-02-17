/*
1509번: 팰린드롬 분할
https://www.acmicpc.net/problem/1509
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str;
void initialize()
{  
    cin>>str;
}

void solve()
{
    vector<vector<bool>> dp(str.size(),vector<bool>(str.size()));
    for(int i=0;i<str.size();i++)   dp[i][i]=true;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=true;
        }
        else{
            dp[i][i+1]=false;
        }
    }

    for(int i=2;i<str.size();i++){
        for(int j=0;j<str.size()-i;j++){
            if(str[j]==str[j+i]&&dp[j+1][j+i-1]){
                dp[j][j+i]=true;
            }
            else{
                dp[j][j+i]=false;
            }
        }
    }

    vector<int> pLen(str.size()+1,0);
    for(int end=0;end<str.size();end++){
        pLen[end+1]=1e9;
        for(int start=0;start<=end;start++){
            if(dp[start][end]){
                pLen[end+1]=min(pLen[start]+1,pLen[end+1]);
            }
        }
    }

    cout<<pLen[str.size()];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}