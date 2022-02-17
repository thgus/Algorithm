/*
2352번: 반도체 설계
https://www.acmicpc.net/problem/2352
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

    cout<<seq.size();
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}