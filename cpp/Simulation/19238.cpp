/*
19238번: 스타트 택시
https://www.acmicpc.net/problem/19238
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node{
    int y,x;
    int fuel;
};

int n;

Node find_passenger(vector<vector<int>> &map, int sy, int sx){
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<pair<int,pair<int,int>>> que;
    que.push({0,{sy,sx}});
    visited[sy][sx]=true;

    bool find_passenger=false;
    int py,px;
    int tlen;

    while(!que.empty()){
        int len=que.front().first;
        int y=que.front().second.first;
        int x=que.front().second.second;
        que.pop();
        
        if(find_passenger&&tlen<len){
            break;
        }

        if(map[y][x]>0){
            if(!find_passenger){
                py=y;   px=x;
                tlen=len;
            }   
            else{
                if((y<py)||(y==py&&x<px)){
                    py=y;   px=x;
                    tlen=len;
                }
            }
            find_passenger=true;
            continue;
        }

        for(int i=0;i<4;i++){
            int ny=y+d[i][0];
            int nx=x+d[i][1];
            if(ny<0||ny>=n||nx<0||nx>=n)    continue;
            if(map[ny][nx]==-1)   continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            que.push({len+1,{ny,nx}});
        }
    }

    if(find_passenger){
        return {py,px,tlen};
    }
    else{
        return {-1,-1,-1};
    }
}

int main()
{
    sync_off;
    
    int m,fuel;
    cin>>n>>m>>fuel;
    vector<vector<int>> map(n,vector<int>(n,0));
    
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            if(temp==1){
                map[i][j]=-1;
            }
        }
    }

    int sy,sx;
    cin>>sy>>sx;
    sx--;   sy--;

    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    int py,px,dy,dx;

    vector<pair<int,pair<int,int>>> direction(m+1,{-1,{-1,-1}});
    for(int j=1;j<=m;j++){
        cin>>py>>px>>dy>>dx;
        py--;   dy--;
        px--;   dx--;
        map[py][px]=j;
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[py][px]=true;
        
        queue<pair<int,pair<int,int>>> que;
        que.push({0,{py,px}});
        while(!que.empty()){
            int len=que.front().first;
            int y=que.front().second.first;
            int x=que.front().second.second;
            que.pop();

            if(y==dy&&x==dx){
                direction[j]={len,{dy,dx}};
                break;
            }

            for(int i=0;i<4;i++){
                int ny=y+d[i][0];
                int nx=x+d[i][1];
                if(ny<0||ny>=n||nx<0||nx>=n)    continue;
                if(map[ny][nx]==-1)   continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx]=true;
                que.push({len+1,{ny,nx}});
            }
        }

        if(direction[j].first==-1){
            cout<<"-1";
            return 0;
        }
    }

    for(int i=0;i<m;i++){
        Node result = find_passenger(map,sy,sx);
        if(result.fuel==-1){
            cout<<"-1";
            return 0;
        }

        int num=map[result.y][result.x];
        if(result.fuel+direction[num].first>fuel){
            cout<<"-1";
            return 0;
        }
        else{
            fuel-=result.fuel+direction[num].first;
            fuel+=direction[num].first*2;
            map[result.y][result.x]=0;

            sy=direction[num].second.first;
            sx=direction[num].second.second;
        }
    }
    cout<<fuel;
    return 0;
}