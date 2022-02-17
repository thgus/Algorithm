/*
2933번: 미네랄
https://www.acmicpc.net/problem/2933
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c;
vector<vector<char>> map;

void print_vec(vector<vector<bool>> &vec){
    cout<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

void print_vec(vector<vector<char>> &vec){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<r&&x>=0&&x<c){
        return true;
    }
    else{
        return false;
    }
}

pair<int,int> shot_stick(int turn, int h)
{   
    int cury=h,curx=-1;
    if(turn%2==0){
        for(int i=0;i<c;i++){
            if(map[h][i]=='x'){
                curx=i;
                break;
            }
        }
    }
    else{
       for(int i=c-1;i>=0;i--){
            if(map[h][i]=='x'){
                curx=i;
                break;
            }
        } 
    }

    if(curx==-1)    return{-1,-1};

    map[cury][curx]='.';

    return {cury,curx};
}

int d[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
void gravity(pair<int,int> p){
    if(p.first==-1) return;

    for(int k=0;k<4;k++){
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(r,vector<bool>(c,false));

        int y=p.first+d[k][0];
        int x=p.second+d[k][1];
        if(!isBoundary(y,x))  continue;
        if(map[y][x]=='.')    continue;

        int ty, dy, lx, rx;
        ty = r - 1;
        dy = 0;
        lx = c - 1;
        rx = 0;

        que.push({y,x});
        visited[y][x]=true;
        while (!que.empty())
        {
            int cy = que.front().first;
            int cx = que.front().second;
            que.pop();

            map[cy][cx] = '.';

            if (cy < ty)
                ty = cy;
            if (cy > dy)
                dy = cy;
            if (cx < lx)
                lx = cx;
            if (cx > rx)
                rx = cx;

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + d[i][0];
                int nx = cx + d[i][1];
                if (ny >= 0 && ny < r && nx >= 0 && nx < c)
                {
                    if (map[ny][nx] == 'x' && !visited[ny][nx])
                    {
                        visited[ny][nx] = true;
                        que.push({ny, nx});
                    }
                }
            }
        }

        int i;
        for (i = 1; i < r - dy; i++)
        {
            for (int y = ty; y <= dy; y++)
            {
                for (int x = lx; x <= rx; x++)
                {
                    if (visited[y][x] && map[y + i][x] == 'x')
                    {
                        goto bk;
                    }
                }
            }
        }

    bk:
        for (int ny = ty; ny <= dy; ny++)
        {
            for (int nx = lx; nx <= rx; nx++)
            {
                if (visited[ny][nx])
                    map[ny + (i - 1)][nx] = 'x';
            }
        }
    }
}

int main()
{
    sync_off;

    cin>>r>>c;
    map.resize(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }

    int n,h;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        gravity(shot_stick(i,r-h));
    }

    print_vec(map);

    return 0;
}