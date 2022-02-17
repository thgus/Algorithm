/*
1922번: 네트워크 연결
https://www.acmicpc.net/problem/1922
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define COMMAX 1000
#define COSTMAX 10000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//컴퓨터의 수
int n;
//연결할 수 있는 선의 수
int m;

//first: cost. second: computer num
//priority queue는 삽입시 시간이 오래 걸리니까 vector에 저장한 후 한번에 정렬
vector<pair<int,pair<int,int>>> computer;

void Initialize(){
    cin>>n;
    cin>>m;

    //연결하는 컴퓨터 a,b 컴퓨터에 연결하는데 드는 비용 c
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        computer.push_back({c,{a,b}});
    }
    sort(computer.begin(),computer.end());
}

vector<int> parent(COMMAX+1);

int findParent(int n){
    if(parent[n]==n){
        return n;
    }
    else{
        return parent[n]=findParent(parent[n]);
    }
}

void unionNode(int a, int b){
    int parentA=findParent(a);
    int parentB=findParent(b);

    parent[parentA]=parentB;
}

int solve(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    int trunkNum=0;
    
    int cost;
    int node1,node2;

    int minCost=0;
    for(int i=0;i<computer.size()&&trunkNum<n-1;i++){
        cost=computer[i].first;
        node1=computer[i].second.first;
        node2=computer[i].second.second;

        if(findParent(node1)==findParent(node2)){
            continue;
        }
        unionNode(node1,node2);
        trunkNum++;
        minCost+=cost;
    }

    return minCost;
}

int main(){
    sync_off;
    Initialize();
    cout<<solve();
    return 0;
}