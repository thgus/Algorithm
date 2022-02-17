/*
1202번: 보석 도둑
https://www.acmicpc.net/problem/1202
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<pair<int,int>> jewelry;
multiset<int> bag;

void initialize()
{
    cin>>n>>k;
    int w,c;
    for(int i=0;i<n;i++){
        cin>>w>>c;
        jewelry.push_back({c,w});
    }

    for(int i=0;i<k;i++){
        cin>>w;
        bag.insert(w);
    }
}

void solve()
{
    long long result=0;
    sort(jewelry.begin(),jewelry.end(),greater<>());

    for(int i=0;i<jewelry.size();i++){
        int curc=jewelry[i].first;
        int curw=jewelry[i].second;

        auto it=bag.lower_bound(curw);
        if(it!=bag.end()){
            result+=curc;
            bag.erase(it);
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