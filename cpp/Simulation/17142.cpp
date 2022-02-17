/*
17142번: 연구소 3
https://www.acmicpc.net/problem/17142
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> map;

vector<pair<int,int>> virous_start;
int start_left_space=0;

void initialize()
{
    cin>>n>>m;
    map.resize(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];

            if(map[i][j]==2)
            {
                virous_start.push_back({i,j});
            }
            else if(map[i][j]==0)
            {
                start_left_space++;
            }
        }
    }
}

inline bool isBoundary(int y, int x)
{
    if(y>=0&&y<n&&x>=0&&x<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
vector<int> seq;

int cal_day()
{
    int time=-1;
    int left_space=start_left_space;

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<pair<int,pair<int,int>>> que;
    for(int i=0;i<m;i++)
    {
        int y=virous_start[seq[i]].first;
        int x=virous_start[seq[i]].second;
        que.push({0,{y,x}});
        visited[y][x]=true;
    }

    while(!que.empty())
    {
        int len=que.front().first;
        int y=que.front().second.first;
        int x=que.front().second.second;
        que.pop();

        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isBoundary(ny,nx))   continue;
            if(map[ny][nx]==1)  continue;
            if(visited[ny][nx]) continue;

            if(map[ny][nx]==0)
            {
                left_space--;
            }
            
            visited[ny][nx]=true;
            que.push({len+1,{ny,nx}});
        }

        if(left_space==0)
        {
            time=len+1;  
            break;          
        }
    }

    return time;
}

void choice_station(int &min_time, int index)
{
    if(seq.size()==m)
    {
        int time=cal_day();
        if(time!=-1){
            min_time=min(min_time,time);
        }
        return;
    }

    for(int i=index;i<virous_start.size();i++)
    {
        seq.push_back(i);
        choice_station(min_time,i+1);
        seq.pop_back();
    }
}

void solve()
{
    int result=1e9;
    if(start_left_space==0) result=0;
    
    choice_station(result,0);

    if(result==1e9) result=-1;
    cout<<result;
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}