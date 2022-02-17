/*
2887번: 행성 터널
https://www.acmicpc.net/problem/2887
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<pair<int,int>> planetX(MAX);
vector<pair<int,int>> planetY(MAX);
vector<pair<int,int>> planetZ(MAX);

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>planetX[i].first>>planetY[i].first>>planetZ[i].first;
        planetX[i].second=i;
        planetY[i].second=i;
        planetZ[i].second=i;
    }
}  

vector<int> parent(MAX);
int findParent(int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=findParent(parent[i]);
    }
}

void makeUnion(int a, int b){
    int pa=findParent(a);
    int pb=findParent(b);
    parent[pa]=pb;
}

void solve()
{
    priority_queue<pair<int,pair<int,int>>> que;
    sort(planetX.begin(),planetX.begin()+n);
    sort(planetY.begin(),planetY.begin()+n);
    sort(planetZ.begin(),planetZ.begin()+n);

    for(int i=0;i<n-1;i++){
        int x=abs(planetX[i].first-planetX[i+1].first);
        int y=abs(planetY[i].first-planetY[i+1].first);
        int z=abs(planetZ[i].first-planetZ[i+1].first);   

        que.push({-x,{planetX[i].second,planetX[i+1].second}});
        que.push({-y,{planetY[i].second,planetY[i+1].second}});
        que.push({-z,{planetZ[i].second,planetZ[i+1].second}});
    }

    for(int i=0;i<n;i++)    parent[i]=i;

    int cost=0;
    int len=0;
    while(len<n-1){
        int curcost=-que.top().first;
        int a=que.top().second.first;
        int b=que.top().second.second;
        que.pop();

        if(findParent(a)!=findParent(b)){
            makeUnion(a,b);
            cost+=curcost;
            len++;
        }
    }

    cout<<cost;

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}