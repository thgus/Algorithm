/*
21569번: Maximum Bishop
https://www.acmicpc.net/problem/21569
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    int n;
    cin>>n;

    vector<pair<int,int>> vec;

    for(int i=1;i<=n;i++){
        vec.push_back({1,i});
    }

    for(int i=2;i<n;i++){
        vec.push_back({n,i});
    }

    cout<<vec.size()<<"\n";
    for(pair<int,int> cur:vec){
        cout<<cur.first<<" "<<cur.second<<"\n";
    }

    return 0;
}