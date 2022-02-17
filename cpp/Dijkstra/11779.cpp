/*
11779번: 최소비용 구하기 2
https://www.acmicpc.net/problem/11779

이 코드는 왜 틀리는거지..?
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int m;
vector<vector<pair<int,int>>> route; 
int s,e;

void initialize()
{
    cin>>n;
    cin>>m;

    route.resize(n+1);
    int a,b,t;
    for(int i=0;i<m;i++){
        cin>>a>>b>>t;
        route[a].push_back({b,t});
    }
    cin>>s>>e;
}

struct Node{
    int cost;
    int cur;
    int visit_city_count;
    string seq;

    bool operator<(const Node n)const{
        return n.cost<cost;
    }
};

void solve()
{
    vector<int> visited(n+1,INT_MAX);
    visited[s]=0;

    priority_queue<Node> que;

    que.push({0,s,1,to_string(s)});

    while(!que.empty()){
        int cur=que.top().cur;
        int cost=que.top().cost;
        int visit_city_count=que.top().visit_city_count;
        string seq=que.top().seq;
        que.pop();

        if(visited[cur]>cost)  continue;

        if(cur==e){
            cout<<cost<<"\n";
            cout<<visit_city_count<<"\n";
            cout<<seq;
            break;
        }

        for(pair<int,int> next:route[cur]){
            int ncost=cost+next.second;
            if(visited[next.first]>ncost){
                visited[next.first]=ncost;
                string next_str=seq+" "+to_string(next.first);
                que.push({ncost,next.first,visit_city_count+1,next_str});
            }
        }
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}