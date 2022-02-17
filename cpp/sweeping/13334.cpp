/*
13334번: 철로
https://www.acmicpc.net/problem/13334
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

int n;
vector<pair<int,int>> vec;
int railLen;

void initialize()
{
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        
        int temp;
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }
        vec.push_back({a,b});
    }
    cin>>railLen;
}

void solve()
{
    sort(vec.begin(),vec.end());
    
    int maxnum=0;
    multiset<int> ms;
    for(int i=0;i<vec.size();i++){
        int sx=vec[i].first;
        int ex=vec[i].second;
        
        ms.insert(sx);

        while(ex-(it.begin())>railLen){
            ms.erase(it);
            if(ms.empty()){
                break;
            }
        }

        int curnum=ms.size();
        maxnum=max(maxnum,curnum);
        
    }

    cout<<maxnum;

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}