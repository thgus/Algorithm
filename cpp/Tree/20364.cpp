/*
20364번: 부동산 다툼
https://www.acmicpc.net/problem/20364
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,q;
vector<bool> occupancy;

void initialize()
{
    cin>>n>>q;
    occupancy.resize(n+1,false);
}

void solve()
{
    int goal;
    while(q--){
        cin>>goal;

        int cur=goal;
        int num=0;
        while(1){
            if(occupancy[cur]){
                num=cur;
            }
            if(cur==1) break;
            cur/=2;
        }
        occupancy[goal]=true;
        cout<<num<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}