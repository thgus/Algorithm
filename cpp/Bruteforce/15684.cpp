/*
15684번: 사다리 조작
https://www.acmicpc.net/problem/15684
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,h;

//세로선 번호, 높이, 왼쪽/오른쪽
vector<vector<vector<bool>>> ladder;

void initialize()
{
    cin>>n>>m>>h;

    ladder.resize(n,vector<vector<bool>>(h,vector<bool>(2,false)));

    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        ladder[b-1][a-1][1]=ladder[b][a-1][0]=true;
    }
}

bool start()
{
    for(int i=0;i<n;i++)
    {
        int cur=i;
        for(int j=0;j<h;j++)
        {
            if(ladder[cur][j][0]){
                cur--;
            }
            else if(ladder[cur][j][1]){
                cur++;
            }
        }

        if(cur!=i)
        {
            return false;
        }
    }

    return true;
}

bool backTracking(int add, int sn, int sh)
{
    if(add==0)
    {
        return start();
    }

    for (int j = sh; j < h; j++)
    {
        if (ladder[sn][j][0] || ladder[sn][j][1])
            continue;
        if (ladder[sn - 1][j][0] || ladder[sn - 1][j][1])
            continue;

        //사다리 추가
        ladder[sn][j][0] = true;
        ladder[sn - 1][j][1] = true;
        if (backTracking(add - 1, sn, j))
        {
            return true;
        }
        ladder[sn][j][0] = false;
        ladder[sn - 1][j][1] = false;
    }

    for(int i=sn+1;i<n;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(ladder[i][j][0]||ladder[i][j][1])    continue;
            if(ladder[i-1][j][0]||ladder[i-1][j][1])    continue;

            //사다리 추가
            ladder[i][j][0] = true;
            ladder[i - 1][j][1] = true;
            if (backTracking(add - 1,i,j))
            {
                return true;
            }
            ladder[i][j][0] = false;
            ladder[i - 1][j][1] = false;
        }
    }

    return false;
}

void solve()
{
    int max_horizontal_line=(n/2)*h;   
    
    int add=0;
    while(add<=3&&m+add<=max_horizontal_line)
    {
        if(backTracking(add,1,0))
        {
            cout<<add;
            return;
        }

        add++;
    }

    cout<<"-1";
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}