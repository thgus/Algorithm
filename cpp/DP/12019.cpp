/*
12019번: 동아리방 청소!
https://www.acmicpc.net/problem/12019
*/

#include <iostream>
#include <vector>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<int> vec;

void initialize()
{
    cin>>n>>m;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

vector<vector<vector<int>>> dp;
int result=1e9;
string result_str="";

void dfs(int dirty, int sum, int num, int k, int last_clear, string str){
    if(dp[num][last_clear][k]>sum)  return;
    if(num==n-1){
        if(result>dp[num][last_clear][k]){
            result=dp[num][last_clear][k];
            result_str=str;
        }
        return;
    }

    if(k<m){
        if(dp[num+1][num][k+1]>sum){
            dp[num+1][num][k+1]=sum;
            string next_str=str+to_string(num+1)+" ";
            dfs(0,sum,num+1,k+1,num,next_str);
        }
    }

    int ndirty=dirty+vec[num];
    int nsum=sum+(ndirty)*vec[num+1];
    if(dp[num+1][last_clear][k]>nsum){
        dp[num+1][last_clear][k]=nsum;
        dfs(ndirty,nsum,num+1,k,last_clear,str);
    }
}

void solve()
{    
    dp.resize(n,vector<vector<int>>(n,vector<int>(m+1,1e9)));
    dp[0][0][0]=0;
    dfs(0,0,0,0,0,"");

    cout<<result<<"\n";
    cout<<result_str;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}