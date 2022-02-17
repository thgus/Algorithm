/*
1818번: 책정리
https://www.acmicpc.net/problem/1818
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec(MAX);

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}

void solve()
{
    vector<int> seq;
    seq.push_back(vec[0]);

    for(int i=1;i<n;i++){
        if(seq.back()<vec[i]){
            seq.push_back(vec[i]);
        }
        else{
            int index=lower_bound(seq.begin(),seq.end(),vec[i])-seq.begin();
            seq[index]=vec[i];
        }
    }

    cout<<n-seq.size();
    
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}