/*
11722번: 가장 긴 감소하는 부분 수열
https://www.acmicpc.net/problem/11722
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<int> seq;
    seq.push_back(vec[n-1]);
    for(int i=n-2;i>=0;i--){
        if(seq.back()<vec[i]){
            seq.push_back(vec[i]);
        }
        else{
            int index=lower_bound(seq.begin(),seq.end(),vec[i])-seq.begin();
            seq[index]=vec[i];
        }
    }

    cout<<seq.size();
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}