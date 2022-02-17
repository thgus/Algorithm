/*
21610번: 마법사 상어와 비바라기
https://www.acmicpc.net/problem/21610
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> map;

int dy[8]={0,-1,-1,-1,0,1,1,1};
int dx[8]={-1,-1,0,1,1,1,0,-1};

vector<pair<int,int>> cloud;

void print_map()
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print_map(vector<vector<bool>> vec)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(int d, int s)
{
    int diagonal_direction[4]={1,3,5,7};

    // 1. 구름 이동
    // 2. 비가 내린다.
    // 3. 이동 위치의 대각선 저장 => 물복사 버그
    for(int i=0;i<cloud.size();i++)
    {
        int cy=cloud[i].first+dy[d]*s;
        int cx=cloud[i].second+dx[d]*s;

        if(cy<0)    cy=n-abs(cy)%n;
        cy%=n;  

        if(cx<0)    cx=n-abs(cx)%n;
        cx%=n;

        // 2. 비내림
        map[cy][cx]++;
    }

    for(int i=0;i<cloud.size();i++)
    {
        int cy=cloud[i].first+dy[d]*s;
        int cx=cloud[i].second+dx[d]*s;

        if(cy<0)    cy=n-abs(cy)%n;
        cy%=n;  

        if(cx<0)    cx=n-abs(cx)%n;
        cx%=n;

        cloud[i].first=cy;
        cloud[i].second=cx;

        // 3. 물 복사
        for (int j = 0; j < 4; j++)
        {
            int ny = cy + dy[diagonal_direction[j]];
            int nx = cx + dx[diagonal_direction[j]];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
                
            if(map[ny][nx]==0)  continue;
            map[cy][cx]++;
        }

    }

    vector<vector<bool>> used(n,vector<bool>(n,false));
    for(int i=0;i<cloud.size();i++)
    {
        used[cloud[i].first][cloud[i].second]=true;
    }
    cloud.clear();

    //4. 구름 생성
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(used[i][j])  continue;
            if(map[i][j]<2) continue;

            map[i][j]-=2;
            cloud.push_back({i,j});
        }
    }

}

int main()
{
    sync_off;
 
    cin>>n>>m;

    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }    

    cloud.push_back({n-1,0});
    cloud.push_back({n-1,1});
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});

    int d,s;
    for(int i=0;i<m;i++){
        cin>>d>>s;
        solve(d-1,s);
    }

    long long result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result+=map[i][j];
        }
    }
    cout<<result;

    return 0;
}