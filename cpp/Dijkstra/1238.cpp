/*
1238번: 파티
https://www.acmicpc.net/problem/1238
*/

#include <iostream>
#include <vector>
#include<queue>


#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define INF 10000001
#define MAX 1000

using namespace std;

/*
 n 마을 수
 m 도로 수
 x 만나기로 한 마을
*/
int n,m,x;
vector<vector<pair<int,int>>> pRoad(MAX+1,vector<pair<int,int>>(0));
vector<vector<pair<int,int>>> rRoad(MAX+1,vector<pair<int,int>>(0));

void initialize()
{
    cin>>n>>m>>x;
    int a,b,t;
    for(int i=0;i<m;i++){
        cin>>a>>b>>t;
        //길은 단방향
        pRoad[a].push_back({b,t});

        //반대로 가는 길을 저장해서
        //a->x로 가는 길을 각각 구하지 않아도 한번의 다익스트라로 구할 수 있음
        rRoad[b].push_back({a,t});
    }  
}

vector<int> findAllRoute(vector<vector<pair<int,int>>> &road, int start){
    vector<int> route(MAX+1,INF);
    priority_queue<pair<int,int>> que;
    route[start]=0;
    que.push({0,start});
    
    while(!que.empty()){
        int len=-que.top().first;
        int cur=que.top().second;
        que.pop();

        for(int i=0;i<road[cur].size();i++){
            int next=road[cur][i].first;
            int nextLen=len+road[cur][i].second;
            if(route[next]>nextLen){
                route[next]=nextLen;
                que.push({-nextLen,next});
            }
        }
    }

    return route;
}

int findRouteToX(vector<vector<pair<int,int>>> &road, int start){
    vector<int> route(MAX+1,INF);
    priority_queue<pair<int,int>> que;
    route[start]=0;
    que.push({0,start});
    
    while(!que.empty()){
        int len=-que.top().first;
        int cur=que.top().second;
        que.pop();

        if(cur==x){
            return len;
        }

        for(int i=0;i<road[cur].size();i++){
            int next=road[cur][i].first;
            int nextLen=len+road[cur][i].second;
            if(route[next]>nextLen){
                route[next]=nextLen;
                que.push({-nextLen,next});
            }
        }
    }
    return 0;
}

void printVector(vector<int> &vec){
    for(int i=1;i<=n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void solve1()
{
    vector<int> backRoute=findAllRoute(pRoad, x);
    
    int maxTime=0;
    for(int i=1;i<=n;i++){
        int toX=findRouteToX(rRoad, i)+backRoute[i];
        if(maxTime<toX){
            maxTime=toX;
        }
    }
    
    cout<<maxTime;
}

void solve2(){
    vector<int> goRoute=findAllRoute(rRoad,x);
    vector<int> backRoute=findAllRoute(pRoad,x);

    int maxTime=0;
    for(int i=1;i<=n;i++){
        if(maxTime<goRoute[i]+backRoute[i]){
            maxTime=goRoute[i]+backRoute[i];
        }
    }
    cout<<maxTime;
}

int main()
{
    sync_off;
    initialize();
    //solve1();
    solve2();

    return 0;
}