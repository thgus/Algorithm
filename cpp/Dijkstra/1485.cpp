/*
1485번: 등산
https://www.acmicpc.net/problem/1486
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
long long t, d;
vector<vector<int>> map;

void initialize()
{
    cin>>n>>m>>t>>d;
    map.resize(n,vector<int>(m));

    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c>='A'&&c<='Z'){
                map[i][j]=c-'A';
            }
            else if(c>='a'&&c<='z'){
                map[i][j]=26+c-'a';
            }
        }
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<m){
        return true;
    }
    else{
        return false;
    }
}

struct Node{
    long long cost;
    int y,x;

    bool operator<(const Node node)const{
        return node.cost<cost;
    }
};

void print_vec(vector<vector<int>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void cal_route(bool isTop, vector<vector<long long>> &dist){
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    long long max_difference=t*t;

    priority_queue<Node> que;
    que.push({0,0,0});
    dist[0][0]=0;

    while(!que.empty()){
        long long cost=que.top().cost;
        int y=que.top().y;
        int x=que.top().x;
        que.pop();

        if(dist[y][x]>cost)   continue;

        for(int i=0;i<4;i++){
            int ny=y+d[i][0];
            int nx=x+d[i][1];
            if(!isBoundary(ny,nx)) continue;

            long long difference=(map[y][x]-map[ny][nx])*(map[y][x]-map[ny][nx]);
            if(difference>max_difference)   continue;

            long long ncost;
            if(isTop){
                ncost=(map[y][x]<map[ny][nx])?cost+difference:cost+1;
            }
            else{
                ncost=(map[y][x]>map[ny][nx])?cost+difference:cost+1;
            }

            if(dist[ny][nx]>ncost){
                dist[ny][nx]=ncost;
                que.push({ncost,ny,nx});
            }
        }
    }

}

void solve()
{
    vector<vector<long long>> go(n,vector<long long>(m,LLONG_MAX));
    vector<vector<long long>> back(n,vector<long long>(m,LLONG_MAX));

    cal_route(true,go);
    cal_route(false,back);

    //print_vec(go);
    //print_vec(back);

    int result=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(go[i][j]==LLONG_MAX||back[i][j]==LLONG_MAX)    continue;
            if(go[i][j]+back[i][j]>d)   continue;

            result=max(result,map[i][j]);
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