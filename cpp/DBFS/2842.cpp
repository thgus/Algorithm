/*
2842번:집배원 한상덕 
https://www.acmicpc.net/problem/2842
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<char>> map;
vector<vector<int>> altitude;
vector<int> s;

int start_y,start_x;
int total_host_num=0;

void initialize()
{
    cin>>n;
    map.resize(n,vector<char>(n));
    altitude.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];

            if(map[i][j]=='P'){
                start_y=i;
                start_x=j;
            }
            else if(map[i][j]=='K'){
                total_host_num++;
            }
        }   
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>altitude[i][j];
            s.push_back(altitude[i][j]);
        }   
    }
}

void solve()
{
    int d[8][2]={{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int l,r;
    l=r=0;
    
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    int min_atigue=1e9;

    while(l<=r&&l<=altitude[start_y][start_x]&&r<s.size()){
        vector<vector<bool>> isVisited(n,vector<bool>(n,false));
        isVisited[start_y][start_x]=true;

        int visit_house=0;
        queue<pair<int,int>> que;
        que.push({start_y,start_x});

        while(!que.empty()){
            int cur_y=que.front().first;
            int cur_x=que.front().second;
            que.pop();

            if(altitude[cur_y][cur_x]>s[r] || altitude[cur_y][cur_x]<s[l])    continue;

            if(map[cur_y][cur_x]=='K'){
                visit_house++;
            }

            for(int i=0;i<8;i++){
                int next_y=cur_y+d[i][0];
                int next_x=cur_x+d[i][1];
                if(next_y>=0&&next_y<n&&next_x>=0&&next_x<n){
                    if(!isVisited[next_y][next_x]){
                        isVisited[next_y][next_x]=true;
                        que.push({next_y,next_x});
                    }
                }
            }
        }

        if(visit_house==total_host_num){
            min_atigue=min(min_atigue,s[r]-s[l]);
            l++;
        }
        else{
            r++;
        }
    }

    cout<<min_atigue;   
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}