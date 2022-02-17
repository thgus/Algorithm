/*
1916번: 최소비용 구하기
https://www.acmicpc.net/problem/1916
*/

#include<iostream>
#include<vector>
#include<queue>

#define BUSMAX 100000
#define CITYMAX 1000
#define COSTMAX 100000001
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//도시의 개수
int n;
//버스의 개수
int m;
//출발 도시 번호, 도착 도시 번호, 버스 비용
int a,b,c;
//시작도시, 도착도시
int startCity, endCity;
//버스 정보 저장
//출발지 노드 -> first:도착지, second:버스 비용
vector<vector<int>> bus(CITYMAX+1,vector<int>(CITYMAX+1,BUSMAX));

void initialize(){
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(bus[a][b]>c){
            bus[a][b]=c;
        }
    }
    cin>>startCity>>endCity;
}

int solve(){
    //first:비용. second:출발지
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> que;
    vector<bool> isVisited(CITYMAX+1,false);

    que.push({0,startCity});

    int pCost;
    int sCity;

    int minCost=COSTMAX;
    while(!que.empty()){
        pCost=que.top().first;
        sCity=que.top().second;
        que.pop();

        if(isVisited[sCity]){
            continue;
        }
        isVisited[sCity]=true;
        
        if(sCity==endCity){
            if(minCost>pCost){
                minCost=pCost;
            }
            continue;
        }

        for(int i=1;i<=n;i++){
            if(bus[sCity][i]==BUSMAX || isVisited[i]){
               continue; 
            }
            que.push({pCost+bus[sCity][i],i});
        }
    }

    return minCost;
}

int main(){
    sync_off;
    initialize();
    cout<<solve()<<"\n";

    return 0;
}