/*
16991번: 외판원 순회3
https://www.acmicpc.net/problem/16991
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> point;

void initialize()
{
    cin>>n;
    int y,x;
    for(int i=0;i<n;i++){
        cin>>y>>x;
        point.push_back({y,x});
    }
}

struct Node{
    int start_city;
    int num;
    int visited_city;
    double cost;
};

void solve()
{
    queue<Node> que;
    vector<vector<double>> dp(n,vector<double>(1<<n,1e9));
    for(int i=0;i<n;i++){
        que.push({i,i,0,0});
        dp[i][0]=0;
    }

    double min_cost=1e9;
    while(!que.empty()){
        Node cur=que.front();
        que.pop();

        if(!(~cur.visited_city&(1<<cur.num))&&cur.num==cur.start_city){
            if(cur.visited_city==(1<<n)-1){
                min_cost=min(min_cost,cur.cost);
            }
            continue;
        }

        if(dp[cur.num][cur.visited_city]<cur.cost)  continue;

        for(int next=0;next<n;next++){
            if(cur.num==next)   continue;
            
            int next_visited_city=cur.visited_city|(1<<next);
            double next_cost=cur.cost+sqrt(pow((double)point[cur.num].first-(double)point[next].first,2)+pow((double)point[cur.num].second-(double)point[next].second,2));

            if(cur.visited_city!=next_visited_city){
                if(dp[next][next_visited_city]>next_cost){
                    dp[next][next_visited_city]=next_cost;
                    que.push({cur.start_city,next,next_visited_city,next_cost});
                }
            }
        }
    }

    printf("%.9f",min_cost);
}

int main()
{
    //sync_off;
    initialize();
    solve();

    return 0;
}