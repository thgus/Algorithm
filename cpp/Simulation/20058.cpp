/*
20058번: 마법사 상어와 파이어스톰
https://www.acmicpc.net/problem/20058
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX 64
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int map[MAX][MAX];

void print_map()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int temp[MAX][MAX];
void turn_map(int l)
{
	int nl = pow(2, l);
	int p = n / nl;

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			int sy = i * nl;
			int sx = j * nl;

			for (int y = 0; y < nl; y++)
			{
				for (int x = 0; x < nl; x++)
				{
					temp[x][nl - 1 - y] = map[sy + y][sx + x];
				}
			}

			for (int y = 0; y < nl; y++)
			{
				for (int x = 0; x < nl; x++)
				{
					map[sy + y][sx + x] = temp[y][x];
				}
			}
		}
	}
}

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
void melt_ice()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][j]=map[i][j];
            if(map[i][j]<=0)    continue;

            int ice_num=0;
            for(int k=0;k<4;k++)
            {
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(ny<0||ny>=n||nx<0||nx>=n)    continue;
                if(map[ny][nx]>0)   ice_num++;
            }

            if(ice_num<3)   temp[i][j]--;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            map[i][j]=temp[i][j];
        }
    }
}

int main()
{
	sync_off;

	int q;
	cin >> n >> q;

	n = pow(2, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int l;
	while (q--)
	{
		cin >> l;
		turn_map(l);
        melt_ice();
	}

    int max_sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]>0)
                max_sum+=map[i][j];
        }
    }
    cout<<max_sum<<"\n";

    int max_space=0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j])   continue;
            
            int space_size=0;
            queue<pair<int,int>> que;
            que.push({i,j});
            visited[i][j]=true;

            while(!que.empty())
            {
                int cy=que.front().first;
                int cx=que.front().second;
                que.pop();

                if(map[cy][cx]<=0)
                {
                    continue;
                }
                space_size++;

                for(int k=0;k<4;k++)
                {
                    int ny=cy+dy[k];
                    int nx=cx+dx[k];

                    if(ny<0||ny>=n||nx<0||nx>=n)    continue;
                    
                    if(visited[ny][nx]) continue;
                    visited[ny][nx]=true;
                    que.push({ny,nx});
                }
            }
            max_space=max(max_space,space_size);
        }
    }
    cout<<max_space;

	return 0;
}