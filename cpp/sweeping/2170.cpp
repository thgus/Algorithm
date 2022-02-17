/*
2170번: 선 긋기
https://www.acmicpc.net/problem/2170

일차원 배열
*/

#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
priority_queue<pii,vector<pii>,greater<pii>> spot;

void initialize()
{  
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b){
            int temp=b;
            b=a;
            a=temp;
        }
        spot.push({a,b});
    }
}

void solve()
{
    int result=0;
    int l=-(1e9+1),r=-(1e9+1);

    while(!spot.empty()){
        int curL=spot.top().first;
        int curR=spot.top().second;
        spot.pop();

        if(r<=curL){
            result+=curR-curL;
            l=curL;
            r=curR;
        }
        else{
            if(r<curR){
                result+=curR-r;
                r=curR;
            }
        }
    }

    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}