/*
11000번: 강의실 배정
https://www.acmicpc.net/problem/11000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> vec;

void initialize()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
}

void solve()
{
    sort(vec.begin(),vec.end());

    int max_room=0;
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<vec.size();i++){
        int stime=vec[i].first;
        int etime=vec[i].second;
        
        while(!que.empty()&&que.top()<=stime){
            que.pop();
        }
        que.push({etime});

        int size=que.size();
        //cout<<size<<" ";
        max_room=max(max_room,size);
    }
    cout<<max_room;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}