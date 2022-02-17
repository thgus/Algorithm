/*
16946번: 벽 부수고 이동하기 4
https://www.acmicpc.net/problem/16946
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> map(MAX,vector<int>(MAX,0));
vector<vector<int>> saveLenth(MAX,vector<int>(MAX,0));
vector<vector<pair<int,int>>> parent(MAX,vector<pair<int,int>>(MAX));
queue<pair<int,int>> wall;

void initialize()
{
    cin>>n>>m;
    char temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            if(temp=='1'){
                map[i][j]=1;
                wall.push({i,j});
            }
            parent[i][j]=make_pair(i,j);
        }
    }
}

int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
pair<int,int> findParent(pair<int,int> a){
    if(parent[a.first][a.second]==a){
        return a;
    }
    else{
        return parent[a.first][a.second]=findParent(parent[a.first][a.second]);
    }

}

void unionParent(pair<int,int> a, pair<int,int> b){
    pair<int,int> ap=findParent(a);
    pair<int,int> bp=findParent(b);

    parent[ap.first][ap.second]=bp;
}

vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,false));
void bfs(int y, int x){
    queue<pair<int,int>> que;
    que.push({y,x});
    isVisited[y][x]=true;

    int lenth=0;
    while(!que.empty()){
        int cury=que.front().first;
        int curx=que.front().second;
        lenth++;

        que.pop();

        for(int i=0;i<4;i++){
            int nexty=cury+d[i][0];
            int nextx=curx+d[i][1];
            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m){
                if(!isVisited[nexty][nextx]&&!map[nexty][nextx]){
                    isVisited[nexty][nextx]=true;
                    que.push({nexty,nextx});
                    unionParent({cury,curx},{nexty,nextx});
                }
            }
        }
    }

    pair<int,int> rootP=findParent({y,x});
    saveLenth[rootP.first][rootP.second]=lenth;

}

void solve()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!isVisited[i][j]&&!map[i][j]){
                bfs(i,j);
            }
        }
    }

    while(!wall.empty()){
        int cury=wall.front().first;
        int curx=wall.front().second;
        wall.pop();

        long long totalLen=0;
        pair<int,int> pp[4];
        for(int i=0;i<4;i++){
            int nexty=cury+d[i][0];
            int nextx=curx+d[i][1];

            bool isPluse=true;
            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m&&map[nexty][nextx]==0){
                pp[i]=findParent({nexty,nextx});
                for(int j=0;j<i;j++){
                    if(pp[j]==pp[i]){
                        isPluse=false;
                        break;
                    }
                }
                if(isPluse){
                    totalLen+=saveLenth[pp[i].first][pp[i].second];
                }
            }
            else{
                pp[i]={-1,-1};
            }
        }
        
        map[cury][curx]=(1+totalLen)%10;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<(map[i][j]);
        }
        cout<<"\n";
    }
}

int main()
{
    //sync_off;
    initialize();
    solve();

    return 0;
}