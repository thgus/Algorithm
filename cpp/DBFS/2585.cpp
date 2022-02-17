/*
2585번: 경비행기
https://www.acmicpc.net/problem/2585
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<pair<int,int>> location;

void initialize()
{
    cin>>n>>k;
    int a,b;
    location.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>a>>b;
        location.push_back({a,b});
    }
    location.push_back({10000,10000});
}

bool BFS(vector<vector<int>> &vec, int ml){
    vector<bool> visited(n+2,false);
    queue<pair<int,int>> que;
    que.push({0,-1});
    visited[0]=true;

    while(!que.empty()){
        int cnum=que.front().first;
        int ck=que.front().second;
        que.pop();

        if(ck>k)    continue;

        if(cnum==n+1){
            return true;
        }

        for(int nnum=0;nnum<vec[cnum].size();nnum++){
            int nl=vec[cnum][nnum];
            if(nl>ml) continue;
            if(visited[nnum])   continue;
            visited[nnum]=true;
            que.push({nnum,ck+1});
        }
    }

    return false;
}

void print_vec(vector<vector<int>> &route){
    cout<<"\n";
    for(int i=0;i<route.size();i++){
        for(int j=0;j<route.size();j++){
            cout<<route[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    vector<vector<int>> route(n+2,vector<int>(n+2,1e9));
    vector<int> cost;
    for(int i=0;i<location.size()-1;i++){
        for(int j=i+1;j<location.size();j++){
            int clen=ceil(sqrt(pow(location[i].first-location[j].first,2)+pow(location[i].second-location[j].second,2))*0.1);
            route[i][j]=route[j][i]=clen;

            cost.push_back(clen);
        }
    }
    sort(cost.begin(),cost.end());

    //print_vec(route);

    int start=0;
    int end=cost.size()-1;
    int ans=1e9;
    
    while(start<end){
        int mid=(start+end)/2;

        if(BFS(route,cost[mid])){
            ans=min(ans,cost[mid]);
            end=mid;
        }
        else{
            start=mid+1;
        }
    }

    cout<<cost[end];
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}