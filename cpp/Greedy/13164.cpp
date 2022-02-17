/*
13164번: 행복 유치원
https://www.acmicpc.net/problem/13164
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
vector<int> vec;

void initialize()
{
    cin>>n>>k;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<int> sub;
    for(int i=1;i<n;i++){
        sub.push_back({vec[i]-vec[i-1]});
    }   
    sort(sub.begin(),sub.end());

    //N-1-(M-1)
    long long sum=0;
    for(int i=0;i<n-k;i++){
        sum+=sub[i];
    }
    cout<<sum;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}