/*
4994번: 배수 찾기
https://www.acmicpc.net/problem/4994
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve(int n)
{
       
}

void initialize()
{   
    int n;
    while(1){
        cin>>n;
        if(n==0)    break;
        solve(n);
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}