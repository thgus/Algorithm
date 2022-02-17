/*
14867번: 물통
https://www.acmicpc.net/problem/14867
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int a,b;
int c,d;

void initialize()
{
    cin>>a>>b>>c>>d;
}

pair<int,int> M(int x, int y, int max_x, int max_y){
    int last_x=max_x-x;
    int last_y=max_y-y; 
    
    if(last_y>=x){
        return {0,y+x};
    }
    else{
        int last=x-last_y;
        return {x-last_y,max_y};
    }
}

void solve()
{
    set<pair<int,int>> s;
    queue<pair<int,pair<int,int>>> que;
    s.insert({0,0});
    que.push({0,{0,0}});

    while(!que.empty()){
        int time=que.front().first;
        int ca=que.front().second.first;
        int cb=que.front().second.second;
        que.pop();

        if(ca==c&&cb==d){
            cout<<time;
            return;
        }
        
        //물통 x에 물을 가득 채운다.
        if(s.find({a,cb})==s.end()){
            s.insert({a,cb});
            que.push({time+1,{a,cb}});
        }
        if(s.find({ca,b})==s.end()){
            s.insert({ca,b});
            que.push({time+1,{ca,b}});
        }

        //물통 x의 물을 모두 버린다.
        if(s.find({0,cb})==s.end()){
            s.insert({0,cb});
            que.push({time+1,{0,cb}});
        }
        if(s.find({ca,0})==s.end()){
            s.insert({ca,0});
            que.push({time+1,{ca,0}});
        }

        //물통 x의 물을 물통 y에 붓는다.
        pair<int,int> xy=M(ca,cb,a,b);
        pair<int,int> yx=M(cb,ca,b,a);

        if(s.find({xy.first,xy.second})==s.end()){
            s.insert({xy.first,xy.second});
            que.push({time+1,{xy.first,xy.second}});
        }
        if(s.find({yx.second,yx.first})==s.end()){
            s.insert({yx.second,yx.first});
            que.push({time+1,{yx.second,yx.first}});
        }
    }

    cout<<"-1";
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}