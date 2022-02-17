/*
1647번: 도시 분할 계획
https://www.acmicpc.net/problem/1647

n개의 집이 있다면 모든 길을 연결하려면 적어도 n-1개의 길이 있어야 하는데
만약 2개의 마을로 분할한다면 n-2개의 길만 있으면 된다.
이 외에는 최소 스패닝 트리 알고리즘과 똑같다.

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define HMAX 100000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n,m;
vector<pair<int,pair<int,int>>> vec;
vector<int> parent(HMAX);

void initialize(){
    cin>>n>>m;

    int a,b,c;

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec.push_back({c,{a,b}});
    }
}

int findParent(int i){
    if(parent[i]==i){
        return i;
    }
    else{
        return parent[i]=findParent(parent[i]);
    }
}

void solve(){
    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int load=0;
    int minCost=0;

    int h1,h2;
    for(int i=0;i<m;i++){
        h1=vec[i].second.first;
        h2=vec[i].second.second;

        if(findParent(h1)!=findParent(h2)){
            parent[findParent(h1)]=findParent(h2);
            minCost+=vec[i].first;
            if (++load == n - 2){
                break;
            }
        }
    }
    
    cout<<minCost;
}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}