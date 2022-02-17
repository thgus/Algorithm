/*
5214번: 환승
https://www.acmicpc.net/problem/5214
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;

    int n,k,m;
    cin>>n>>k>>m;

    vector<vector<int>> route(n+1);
    vector<vector<int>> line(m,vector<int>(k));
    queue<pair<int,int>> que;
    vector<bool> visited(n+1,false);

    route.resize(n+1);
    line.resize(m,vector<int>(k));

    int next,pre;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>line[i][j];
            route[line[i][j]].push_back(i);

            if(line[i][j]==1){
                que.push({i,1});

                if(n==1){
                    cout<<"1";
                    return 0;
                }
            }
        }
    }

    visited[1]=true;
    while(!que.empty()){
        int cur_line=que.front().first;
        int cur_len=que.front().second;
        que.pop();

        for(int next:line[cur_line]){
            if(next==n){
                cout<<cur_len+1;          
                return 0;
            }

            if(visited[next])   continue;
            visited[next]=true;

            for(int next_line:route[next]){
                if(next_line==cur_line) continue;

                que.push({next_line,cur_len+1});
            }
        }
    }

    cout<<"-1";

    return 0;
}