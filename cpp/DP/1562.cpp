/*
1562번: 계단 수
https://www.acmicpc.net/problem/1562
*/

#include <iostream>
#include <vector>

#define mod 1000000000
#define INF 1000000000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;

void initialize()
{
    cin>>n;
}

void solve()
{
    vector<vector<vector<long long>>> vec(10,vector<vector<long long>>(n,vector<long long>(1<<10)));
    for(int i=1;i<10;i++){
        vec[i][0][1<<i]=1;
    }

    for(int k=1;k<n;k++){
        for(int i=0;i<10;i++){
            int pre=i-1;
            int next=i+1;

            for(int j=0;j<(1<<10);j++){
                if(pre>=0){
                    vec[pre][k][j|(1<<pre)]+=vec[i][k-1][j];
                    vec[pre][k][j|(1<<pre)]%=INF;
                }
                if(next<10){
                    vec[next][k][j|(1<<next)]+=vec[i][k-1][j];
                    vec[next][k][j|(1<<next)]%=INF;
                }
            }
        }
    }

    long long result=0;
    for(int i=0;i<10;i++){
        result+=vec[i][n-1][(1<<10)-1]%INF;
    }

    cout<<result%INF<<"\n";
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}