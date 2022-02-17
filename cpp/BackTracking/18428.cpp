#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<char>> map;
vector<pair<int,int>> teacher;

void initialize()
{
    cin>>n;
    map.resize(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];

            if(map[i][j]=='T')
            {
                teacher.push_back({i,j});
            }
        }
    }
}

int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check()
{
    for(pair<int,int> t:teacher){
        for(int k=0;k<4;k++)
        {
            int y=t.first;
            int x=t.second;

            while(y>=0&&y<n&&x>=0&&x<n)
            {
                if(map[y][x]=='S')  return false;
                else if(map[y][x]=='O')  break;

                y+=d[k][0];
                x+=d[k][1];
            }
        }
    }

    return true;
}

bool backTracking(int y, int x, int block_cnt)
{
    if(block_cnt==3)
    {
        return check();
    }
    
    for(int j=x;j<n;j++)
    {
        if(map[y][j]!='X')  continue;
        
        map[y][j]='O';
        if(backTracking(y,j+1,block_cnt+1)) return true;
        map[y][j]='X';
    }

    for(int i=y+1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]!='X')  continue;

            map[i][j]='O';
            if(backTracking(i,j+1,block_cnt+1)) return true;
            map[i][j]='X';
        }
    }

    return false;
}

int main()
{
    sync_off;
 
    initialize();
    if(backTracking(0,0,0))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}