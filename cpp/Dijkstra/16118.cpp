/*
16118번: 달빛 여우
https://www.acmicpc.net/problem/16118

늑대가 2배로 빨리 가는 경우에 나누기로 해결하면 나머지만큼의 오차가 발생하므로
여우가 가는 시간을 2배로 처리하고, 늑대가 여우보다 빨리 가는 시간을 4배를 처리해주어야 함.

그리고 늑대에게 어떤 목적지는 한바퀴 돈 다음에 가는게(시작지점에서 느리게 출발) 더 빠른 경우도 있으니 이를 주의하자.
반례) https://www.acmicpc.net/board/view/48207 
5 5
1 2 1
2 3 1
1 3 1
1 4 1
4 5 10000

*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 4000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<pair<int,int>>> route(MAX+1);

void initialize()
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        route[a].push_back({b,c});
        route[b].push_back({a,c});
    }
}

void solve()
{
    vector<long long> foxDistance(MAX+1,(long long)2e9);
    priority_queue<pair<long long,int>> que;
    que.push({0,1});
    foxDistance[1]=0;

    while(!que.empty()){
        long long cost=-que.top().first;
        int cur=que.top().second;
        que.pop();

        if(foxDistance[cur]<cost){
            continue;
        }
        for(int i=0;i<route[cur].size();i++){
            int next=route[cur][i].first;
            long long nextcost=cost+(route[cur][i].second*2);
            if(foxDistance[next]>nextcost){
                foxDistance[next]=nextcost;
                que.push({-nextcost,next});
            }
        }
    }

    vector<vector<long long>> wolfDistance(MAX+1,vector<long long>(2,(long long)2e9));  
    priority_queue<pair<long long,pair<int,bool>>> que2;  
    wolfDistance[1][1]=0;
    que2.push({0,{1,true}});

    while(!que2.empty()){
        long long cost=-que2.top().first;        
        int cur=que2.top().second.first;
        bool isDouble=que2.top().second.second;
        que2.pop();

        int index;
        (isDouble)?index=1:index=0;
        if(cost>wolfDistance[cur][index]){
            continue;
        }

        int nextindex=(index+1)%2;
        for(int i=0;i<route[cur].size();i++){
            int next=route[cur][i].first;
            long long nextroutecost=cost;
            (isDouble)?nextroutecost+=(route[cur][i].second):nextroutecost+=(route[cur][i].second*4);
            if(wolfDistance[next][nextindex]>nextroutecost){
                que2.push({-nextroutecost,{next,isDouble^1}});
                wolfDistance[next][nextindex]=nextroutecost;
            }
        }
    }

    int result=0;
    for(int i=1;i<=n;i++){
        if(foxDistance[i]<wolfDistance[i][0]&&foxDistance[i]<wolfDistance[i][1]){
            result++;
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