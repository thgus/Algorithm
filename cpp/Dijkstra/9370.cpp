/*
9370번: 미확인 도착지
https://www.acmicpc.net/problem/9370
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define PMAX 987654321
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int T;

void dijkstra(vector<int> &path, vector<vector<pair<int,int>>> &route, int s){
    path[s]=0;
    priority_queue<pair<int,int>> que;
    que.push({0,s});
    
    int visitedCrossroads=0;
    while(!que.empty()){
        int cost=-que.top().first;
        int cur=que.top().second;
        que.pop();

        if(path[cur]<cost){
            continue;
        }
        
        for(int i=0;i<route[cur].size();i++){
            int nextroute=route[cur][i].first;
            int nextrouteCost=cost+route[cur][i].second;
          
            if(path[nextroute]>nextrouteCost){
                que.push({-nextrouteCost,nextroute});
                path[nextroute]=nextrouteCost;
            }
        }
    }
}

void printVector(vector<int> &vec){
    for(int i=1;i<vec.size();i++){
        cout<<i<<":"<<vec[i]<<" ";
    }
    cout<<"\n";
}

void solve(int n, int s, int g, int h, vector<vector<pair<int,int>>> &route, vector<int> &dc, int smelldCost)
{
    vector<int> shortestPath(n+1,PMAX);
    vector<int> startGpath(n+1,PMAX);
    vector<int> startHpath(n+1,PMAX);

    dijkstra(shortestPath,route,s);
    dijkstra(startGpath,route,g);
    dijkstra(startHpath,route,h);
    
    priority_queue<int> result;
    for(int i=0;i<dc.size();i++){
        int shortesDisPath=shortestPath[dc[i]];
        int minGHPath=min(shortestPath[g]+startHpath[dc[i]],shortestPath[h]+startGpath[dc[i]])+smelldCost;

        if(shortesDisPath==minGHPath){
            result.push(-dc[i]);
        }
    }

    while(!result.empty()){
        cout<<-result.top()<<" ";
        result.pop();
    }
    cout<<"\n";
}

void initialize()
{
    cin>>T;
    while(T--){
        //n: 교차로, m: 도로, t: 목적지 후보
        int n,m,t;
        cin>>n>>m>>t;
        //s: 예술가들의 출발지, g와 h사이의 거리를 지나갔다는 것을 앎
        int s,g,h;
        cin>>s>>g>>h;

        int a,b,d;
        vector<vector<pair<int,int>>> route(n+1); //교차로간의 거리
        int smelldCost;
        for(int i=0;i<m;i++){
            cin>>a>>b>>d;
            route[a].push_back({b,d});
            route[b].push_back({a,d});

            if((a==g&&b==h)||(a==h&&b==g)){
                smelldCost=d;
            }
        }

        vector<int> dc(t); //목적지 후보
        for(int i=0;i<t;i++){
            cin>>dc[i];
        }

        solve(n, s, g, h, route, dc, smelldCost);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}