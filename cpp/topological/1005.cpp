/*
1005번: ACM Craft
https://www.acmicpc.net/problem/1005

진입차수 저장 안하고 그냥 for문으로 반복하면서 풀게 해서
시간초과 날수도 있다고 생각했는데
좀 느리긴 해도 시간 안에 잘 됐네
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define BUILDINGMAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

bool checkStart(int n, int s, vector<vector<bool>> &rule){
    for (int i = 1; i <= n; i++){
        if (rule[s][i]){
            return false;
        }
    }
    return true;
}

void solve(int n, int w, vector<int> &spendTime, vector<vector<bool>> &rule)
{
    vector<int> dp(BUILDINGMAX+1,0);
    vector<bool> isVisited(BUILDINGMAX+1,false);
    queue<int> que;

    for(int i=1;i<=n;i++){
        if(checkStart(n,i,rule)){
            que.push(i);
        }
    }

    while(!que.empty()){
        int cur=que.front();
        que.pop();

        if(cur==w){
            break;
        }

        if(isVisited[cur]){
            continue;
        }
        isVisited[cur]=true;

        for(int i=1;i<=n;i++){
            //i번째 작업이 현재 작업 이후에 수행할 수 있는 작업이라면
            if(rule[i][cur]){
                dp[i]=max(dp[i],dp[cur]+spendTime[cur]);
                //작업이 끝났음을 알림
                rule[i][cur]=false;
            }
        }

        for(int i=1;i<=n;i++){
            if(!isVisited[i] && checkStart(n,i,rule)){
                que.push(i);
            }
        }
    }

    //for(int i=1;i<=n;i++){
    //    cout<<dp[i]<<" ";
    //}
    //cout<<"\n";

    cout<<dp[w]+spendTime[w]<<"\n";
}

void initialize()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> spendTime(BUILDINGMAX+1);
        for(int i=1;i<=n;i++){
            cin>>spendTime[i];
        }

        //y번의 행동을 수행하기 위해서 이전에 해야 할 일 번호 x
        vector<vector<bool>> rule(BUILDINGMAX+1,vector<bool>(BUILDINGMAX+1,false));
        int x,y;
        for(int i=0;i<k;i++){
            cin>>x>>y;
            rule[y][x]=true;
        }
        int w;
        cin>>w;
        solve(n, w, spendTime,rule);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}