/*
18427번: 함께 블록 쌓기
https://www.acmicpc.net/problem/18427
*/

#include <iostream>
#include <vector>
#include<sstream>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,h;
vector<vector<int>> blocks(51);

void initialize()
{
    cin>>n>>m>>h;
    string line;
    cin.ignore(1);
    //getline(cin, line);
    
    for (int i = 1; i <= n; i++)
    {
        getline(cin, line);
        istringstream ss(line);
        string buffer;
        while (getline(ss, buffer, ' '))
        {
            int value = atoi(buffer.c_str());
            blocks[i].push_back(value);
        }
    }
}

void solve()
{
    vector<int> dp(h+1,0);

    for(int cur=1;cur<=n;cur++){
        vector<int> temp(h+1,0);
        for(int i=0;i<blocks[cur].size();i++){
            int curB=blocks[cur][i];
            temp[curB]+=1;
            for(int j=curB+1;j<=h;j++){
                temp[j]+=dp[j-curB];
            }  
        }
        for(int i=1;i<=h;i++){
            dp[i]+=temp[i];
            dp[i]%=10007;
            //cout<<dp[i]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[h]%10007;
}

int main()
{
    //sync_off;
    initialize();
    solve();

    return 0;
}