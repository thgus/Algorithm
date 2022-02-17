/*
14889번: 스타트와 링크
https://www.acmicpc.net/problem/14889
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map;

void initialize()
{
    cin>>n;
    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }    
}

int total=0;
vector<int> r_sum;
vector<int> c_sum;

int backTracking(int index, int count, int power)
{
    int min_result;
    if(count==n/2)
    {   
        // power는 전체에서 team2를 제외한 힘 + team1
        // 1,2 => 이런식으로 나뉘어져 있고 1이 team1, 4가 team2 영역이라면
        // 3,4      매개변수 power는 영역 1+1+2+3 의 파워만큼 가지고 있다.
        // 여기서 total을 빼주면 (1+1+2+3)-(1+2+3+4) = 1 - 4 ## 두 영역의 차이를 구할 수 있다.
        
        int result=power-total;
        if(result<0)
        {
            min_result=-result;
        }
        else
        {
            min_result=result;
        }
        return min_result;
    }

    if(index==n){
        return 1e9;
    }    

    //team1
    int n_team_power=power+r_sum[index]+c_sum[index];
    min_result = backTracking(index+1,count+1,n_team_power);

    //team2
    int ret = backTracking(index+1,count,power);
    if(ret<min_result)  min_result=ret;

    return min_result;
}

void solve()
{
    r_sum.resize(n,0);
    c_sum.resize(n,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            total+=map[i][j];
            
            r_sum[i]+=map[i][j];
            c_sum[j]+=map[i][j];
        }
    }

    cout<<backTracking(0,0,0);
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}