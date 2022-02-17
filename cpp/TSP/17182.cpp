/*
17182번: 우주 탐사선
https://www.acmicpc.net/problem/17182
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,start;
vector<vector<int>> route;

void initialize()
{
    cin>>n>>start;
    route.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>route[i][j];
        }
    }
}

struct Planet{
    int planet_num;
    int spend_time;
    int visited_palnet;
};

void solve()
{
    vector<vector<int>> dp(n,vector<int>(1<<n,1e9));
    for(int i=0;i<n;i++)    dp[i][i]=0;
    dp[start][1<<start]=0;

    int result=1e9;
    queue<Planet> que;
    que.push({start,0,1<<start});

    while(!que.empty()){
        Planet p=que.front();
        que.pop();

        if(p.visited_palnet==(1<<n)-1){
            result=min(result,p.spend_time);
            continue;


        if(dp[p.planet_num][p.visited_palnet]<p.spend_time){
            continue;
        }

        for(int next_planet=0;next_planet<n;next_planet++){
            int next_spend_time=p.spend_time+route[p.planet_num][next_planet];
            int next_visited_planet=p.visited_palnet|(1<<next_planet);
            if(dp[next_planet][next_visited_planet]>next_spend_time){
                dp[next_planet][next_visited_planet]=next_spend_time;
                que.push({next_planet,next_spend_time,next_visited_planet});
            }
        }
    }

    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}