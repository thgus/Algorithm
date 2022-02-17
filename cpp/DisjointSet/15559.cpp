/*
15559번: 내 선물을 받아줘
https://www.acmicpc.net/problem/15559
*/

#include <iostream>
#include <vector>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;

void initialize()
{
    cin>>n>>m;
}

vector<vector<pair<int,int>>> parent(MAX,vector<pair<int,int>>(MAX));
pair<int,int> findParent(pair<int,int> i){
    if(parent[i.first][i.second]==i){
        return i;
    }
    else{
        return parent[i.first][i.second]=findParent(parent[i.first][i.second]);
    }
}

void solve()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            parent[i][j]=make_pair(i,j);
        }
    }

    char cur;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cur;

            int nexty,nextx;
            switch(cur){
                case 'S':
                    nexty=i+1;  nextx=j;
                    break;
                case 'W':
                    nexty=i;    nextx=j-1;
                    break;
                case 'E':
                    nexty=i;    nextx=j+1;
                    break;
                case 'N':
                    nexty=i-1;  nextx=j;
                    break;
            }

            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m){
                pair<int, int> cp = findParent({i, j});
                pair<int, int> np = findParent({nexty, nextx});
                if (cp != np)
                {
                    parent[cp.first][cp.second] = np;
                }
            }
        }
    }

    vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,false));
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pair<int,int> p=findParent({i,j});
            if(!isVisited[p.first][p.second]){
                isVisited[p.first][p.second]=true;
                result++;
            }
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