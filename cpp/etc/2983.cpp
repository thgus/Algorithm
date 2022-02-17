/*
2983번: 개구리 공주
https://www.acmicpc.net/problem/2983
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
string order;

struct Node
{
    int y,x;
    Node *a,*b,*c,*d;
}

vector<pair<int,int>> plants;

void initialize()
{
    cin>>n>>k;
    plants.resize(n);

    int y,x;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        plants[i]={y,x};
    }
}

void solve()
{
    sort(plants.begin(),plants.end());


}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}