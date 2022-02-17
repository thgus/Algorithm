/*
1944번: 복제 로봇
https://www.acmicpc.net/problem/1944

https://yabmoons.tistory.com/407
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node{
    int num;
    int lenth;
    int y,x;
};

int find_parent(vector<int> &parent, int i){
    if(parent[i]==i)    return i;
    return parent[i]=find_parent(parent,parent[i]);
}

void make_union(vector<int> &parent, int a, int b){
    int pa=find_parent(parent,a);
    int pb=find_parent(parent,b);
    if(pa==pb)  return;
    parent[pb]=pa;
}

bool isBoundary(int n, int nx, int ny){
    if (nx >= 0 && ny >= 0 && nx < n && ny < n){
        return true;
    }
    else{
        return false;
    } 
}

int main()
{
    sync_off;
    int n,m;
    cin>>n>>m;

    vector<vector<char>> vec(n,vector<char>(n));
    map<pair<int,int>,int> mp;
    pair<int,int> start;
    queue<Node> que;
    vector<vector<vector<bool>>> visited(m+1,vector<vector<bool>>(n,vector<bool>(n,false)));

    int m_index=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];

            if(vec[i][j]=='S'){
                start.first=i;
                start.second=j;

                visited[0][i][j]=true;
                que.push({0,0,i,j});
                mp.insert({{i,j},0});
            }
            else if(vec[i][j]=='K'){
                visited[m_index][i][j]=true;
                que.push({m_index,0,i,j});
                mp.insert({{i,j},m_index++});
            }
        }
    }

    priority_queue<pair<int,pair<int,int>>> pq;
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    while(!que.empty()){
        int cnum=que.front().num;
        int clen=que.front().lenth;
        int cy=que.front().y;
        int cx=que.front().x;
        que.pop();

        for(int i=0;i<4;i++){
            int ny=cy+d[i][0];
            int nx=cx+d[i][1];

            if(!isBoundary(n,ny,nx))  continue;

            if(visited[cnum][ny][nx])   continue;
            visited[cnum][ny][nx]=true;

            if(vec[ny][nx]=='1')    continue;
            else if(vec[ny][nx]=='K'||vec[ny][nx]=='S'){
                int nnum=mp.find({ny,nx})->second;
                pq.push({-(clen+1),{cnum,nnum}});
            }
            que.push({cnum,clen+1,ny,nx});
        }
    }    

    vector<int> parent(m+1);
    for(int i=0;i<=m;i++){
        parent[i]=i;
    }

    int sum=0;
    while(!pq.empty()){
        int len=-pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();

        int ap=find_parent(parent,a);
        int bp=find_parent(parent,b);
        if(ap==bp)  continue;

        parent[bp]=ap;
        sum+=len;
    }

    for(int i=1;i<=m;i++){
        if(parent[0]!=parent[i]){
            cout<<"-1";
            return 0;
        }
    }
    cout<<sum;
    return 0;
}