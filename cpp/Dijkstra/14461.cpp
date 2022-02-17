/*
14461번: 소가 길을 건너간 이유 7
https://www.acmicpc.net/problem/14461
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,t;
vector<vector<int>> map;

struct Node{
    int cost;
    int len;
    int y,x;

    bool operator<(const Node node) const {
        return node.cost<cost;
    }
};

void initialize()
{
    cin>>n>>t;
    map.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
}

void print_vec(vector<vector<int>> &m){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<vector<int>>> isVisited(3,vector<vector<int>>(n,vector<int>(n,1e9)));
    priority_queue<Node> que;
    que.push({0,0,0,0});
    isVisited[0][0][0]=0;

    while(!que.empty()){
        Node cur=que.top();
        que.pop();

        if(cur.y==n-1&&cur.x==n-1){
            cout<<cur.cost;
            break;
        }

        if(isVisited[cur.len%3][cur.y][cur.x]<cur.cost)    continue;

        int next_len=cur.len+1;
        for(int i=0;i<4;i++){
            int next_y=cur.y+d[i][0];
            int next_x=cur.x+d[i][1];

            if(next_y>=0&&next_y<n&&next_x>=0&&next_x<n){
                int next_cost=cur.cost+t;
                if(next_len%3==0)   next_cost+=map[next_y][next_x];
                if(isVisited[next_len%3][next_y][next_x]<=next_cost)    continue;
                isVisited[next_len%3][next_y][next_x]=next_cost;
                que.push({next_cost,next_len,next_y,next_x});
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