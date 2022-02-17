/*
1029번: 그림 교환
https://www.acmicpc.net/problem/1029
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> cost;

void initialize()
{
    cin>>n;

    cost.resize(n,vector<int>(n));

    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            cost[i][j]=str[j]-'0';
        }
    }
    
}

struct Paint{
    int owner,cost,former_buyer;
};

void solve()
{
    queue<Paint> que;
    que.push({0,0,(1<<0)});

    vector<vector<int>> dp(n,vector<int>((1<<n),1e9));
    dp[0][(1<<0)]=0;

    int max_onwer_num=0;
    while(!que.empty()){
        int cur_owner=que.front().owner;
        int cur_cost=que.front().cost;
        int former_buyer=que.front().former_buyer;
        que.pop();

        if(dp[cur_owner][former_buyer]!=cur_cost)  continue;

        vector<int> n_former_buyer;
        for(int i=0;i<n;i++){
            if(~former_buyer&(1<<i)){
                n_former_buyer.push_back(i);
            }
        }

        if(max_onwer_num<n-n_former_buyer.size()) 
            max_onwer_num=n-n_former_buyer.size();        

        for(int i=0;i<n_former_buyer.size();i++){
            int next_owner=n_former_buyer[i];
            int next_cost=cost[cur_owner][next_owner];
            int next_former_buyer=former_buyer|(1<<next_owner);
            
            if(cur_cost>next_cost)    
                continue;
                        
            if(dp[next_owner][next_former_buyer]>next_cost){
                dp[next_owner][next_former_buyer]=next_cost;
                que.push({next_owner,next_cost,next_former_buyer});
            }
        }

    }

    cout<<max_onwer_num;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}