/*
1107번: 리모컨
https://www.acmicpc.net/problem/1107
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<bool> isBroken(10,false);

void initialize()
{
    cin>>n;
    cin>>m;

    int temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        isBroken[temp]=true;
    }
}

void findChannel(int k, int d, int c, int &minPush){
    if(k==d){
        int num=k+abs(c-n);
        if(minPush>num){
            minPush=num;
        }
        return;
    }

    for(int i=0;i<=9;i++){
        if(isBroken[i]){
            continue;
        }
        findChannel(k,d+1,c*10+i,minPush);
    }   
}

void solve()
{
    int minPush=abs(100-n);
    for(int i=1;i<=7;i++){
        findChannel(i,0,0,minPush);
    }
    cout<<minPush;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}