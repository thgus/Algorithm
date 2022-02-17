/*
15649번: N과 M(1)
https://www.acmicpc.net/problem/15649
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<bool> use;
vector<int> vec;

void initialize()
{
    cin>>n>>m;
    use.resize(n+1);
}

void solve(int start)
{
    if(vec.size()==m){
        for(int i=0;i<m;i++){
            cout<<vec[i]<<" ";
        }
        cout<<"\n"; 
    }

    for(int i=1;i<=n;i++){
        if(use[i])  continue;

        use[i]=true;
        vec.push_back(i);
        solve(i+1);
        vec.pop_back();
        use[i]=false;
    }
}

int main()
{
    sync_off;
    initialize();
    solve(1);

    return 0;
}