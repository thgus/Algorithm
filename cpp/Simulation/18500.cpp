/*
18500번: 미네랄 2
https://www.acmicpc.net/problem/18500

공중에 떠 있는 미네랄 클러스터는 없으며, 두 개 또는 그 이상의 클러스터가 동시에 떨어지는 경우도 없다.
*/

#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX 101
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r, c;
vector<vector<char>> map;

void initialize()
{
    cin >> r >> c;
    map.resize(r + 1, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int j = 0; j < c; j++)
    {
        map[r][j] = 'x';
    }
}

bool boundary(int y, int x)
{
    if (y >= 0 && y < r && x >= 0 && x < c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_map()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_visited(bool visited[][101])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << visited[i][j];
        }
        cout << "\n";
    }
}

int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool bfs(bool visited[][MAX],int y, int x){
    if (!boundary(y, x))    return false;
    if (map[y][x] == '.')   return false;

    queue<pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = true;

    int bottom_y = y;
    while (!que.empty())
    {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();

        bottom_y = max(cy, bottom_y);

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + d[i][0];
            int nx = cx + d[i][1];

            if (!boundary(ny, nx))  continue;
            if (map[ny][nx] == '.') continue;
            if (visited[ny][nx])    continue;
            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }

    if (bottom_y == r - 1)  return false;
    return true;
}

bool isBreak(bool visited[][MAX], int i){
    for (int y = 0; y < r - i; y++){
        for (int x = 0; x < c; x++){
            if (map[y + i][x] == 'x' && visited[y][x])
                return false;
        }
    }
    return true;
}

void shout_stick(int h, bool isLeft)
{
    print_map();
    int x;
    if(isLeft){
        x=0;
        while (x < c && map[h][x] == '.')   x++;
        if (x == c)
            return;
    }
    else{
        x=c-1;
        while (x >= 0 && map[h][x] == '.')   x--;
        if (x == 0)
            return;
    }
    map[h][x] = '.';

    for (int k = 0; k < 4; k++)
    {
        bool visited[MAX][MAX];
        for (int i = 0; i < r; i++)
        {
            memset(visited[i], false, sizeof(bool) * c);
        }

        if(!bfs(visited,h+d[k][0],x+d[k][1])){
            continue;
        }

        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                if(visited[y][x])   map[y][x]='.';
            }
        }

        int i=1;
        while(isBreak(visited,i)){
            i++;
        }
        
        i--;
        for (int y = 0; y < r - i; y++){
            for (int x = 0; x < c; x++){
                if (visited[y][x])
                    map[y + i][x] = 'x';
            }
        }
    }
}

int main()
{
    sync_off;
    initialize();
    int n;
    cin >> n;

    int h;
    bool isLeft=true;
    while (n--)
    {
        cin >> h;
        shout_stick(r - h,isLeft);
        isLeft=(isLeft)?false:true;
    }

    print_map();

    return 0;
}