/*
11657번: 타임머신 
https://www.acmicpc.net/problem/11657

벨만 포드
간선의 가중치가 음의 수 일 경우 비용 구하는 방법
음의 사이클이 생기는 경우에는 사용 X

n이 500이고 간선은 -10,000~10,000인데 int형에서 오버플러우가 나는 이유
    a->b로 가는 경우의 수가 여러개 있을 때 이 노선의 최소값만 저장한다면 상관 안해도 됨.
    문제는 이미 a에서 b로 가는 루트인지 생각하지 않고 그냥 모든 노선들을 추가해 주었을 때
버스 노선의 개수가 6000개이기 때문에 만약 이 6000개의 노선이 전부 1->2, 2->1으로 가는 노선이라면
벨만-포드 알고리즘을 사용하면 500*3000*10000=15000000000 이라는 값이 나올 수 있다. 이는 INT를 아득히 뛰어넘는 숫자이므로 오버플로우
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<pair<int,int>>> route;

void initialize()
{
    int m;
    cin>>n>>m;
    int a,b,c;
    
    route.resize(n);
    while(m--){
        cin>>a>>b>>c;
        route[a-1].push_back({b-1,c});
    }
}

void dijkstra(vector<long long> &visited){
    for (int cur = 0; cur < n; cur++)
    {
        if (visited[cur] == LLONG_MAX)
            continue;
        for (pair<int, int> next : route[cur])
        {
            long long next_cost = visited[cur] + (long long)next.second;
            if (visited[next.first] > next_cost)
            {
                visited[next.first] = next_cost;
            }
        }
    }
}

void solve()
{
    //벨만 포드
    vector<long long> visited(n,LLONG_MAX);
    visited[0]=0;
    for(int i=0;i<n-1;i++){
        dijkstra(visited);
    }

    //음의 가중치 확인
    vector<long long> check_cycle=visited;
    dijkstra(check_cycle);

    for(int i=0;i<n;i++){
        if(visited[i]!=check_cycle[i]){
            cout<<"-1";
            return;
        }
    }

    for(int i=1;i<n;i++){
        if(visited[i]==LLONG_MAX){
            cout<<"-1\n";
        }
        else{
            cout<<visited[i]<<"\n";
        }
    }

    return;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}