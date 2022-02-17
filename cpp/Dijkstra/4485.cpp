/*
4485번: 녹색 옷 입은 애가 젤다지?
https://www.acmicpc.net/problem/4485

문제 분류로는 다익스트라로 나와있는데 그냥 bfs로 풀면 안되나
priority_queue쓰는건 다 다익스트라인가
*/

#include<iostream>
#include<vector>
#include<queue>

#define MAPMAX 125
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map(MAPMAX,vector<int>(MAPMAX));

bool initialize(){
    cin>>n;
    if(n==0){
        return false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    return true;
}

int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int solve(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
    vector<vector<bool>> isVisited(MAPMAX,vector<bool>(MAPMAX,false));
    que.push({0,{0,0}});

    int lostRupee;
    int x,y;
    int _x,_y;

    while(!que.empty()){
        y=que.top().second.first;
        x=que.top().second.second;
        lostRupee=que.top().first+map[y][x];
        que.pop();

        if(isVisited[y][x]){
            continue;
        }
        isVisited[y][x]=true;

        if(y==n-1&&x==n-1){
            return lostRupee;
        }

        for(int i=0;i<4;i++){
            _y=y+direction[i][0];
            _x=x+direction[i][1];

            if (_y >= 0 && _y < n && _x >= 0 && _x < n && !isVisited[_y][_x]){
                que.push({lostRupee, {_y, _x}});
            }
        }
    }
    
    return -1;
}

int main(){
    sync_off;
    
    int n=0;
    while(1){
        if(!initialize()){
            break;
        }
        cout<<"Problem "<<++n<<": "<<solve()<<"\n";
    }

    return 0;
}