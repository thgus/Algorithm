/*
18809번: Gaaaaaaaaaarden 
https://www.acmicpc.net/problem/18809
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
int g,r;
vector<vector<int>> garden;
vector<pair<int,int>> ground;

void initialize()
{
    cin>>n>>m>>g>>r;
    garden.resize(n,vector<int>(m));

    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            
            switch(temp){
                case 0:
                    garden[i][j]=0;
                    break;
                case 1:
                    garden[i][j]=1;
                    break;
                case 2:
                    ground.push_back({i,j});
                    garden[i][j]=1;
                    break;
            }
        }
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<m){
        return true;
    }
    else{
        return false;
    }
}

int max_flower=0;
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
vector<int> green;
vector<int> red;
vector<bool> isCheck;
vector<vector<pair<int,int>>> map;

// 0: 호수/ 1: 땅/ 2:그린 /3:레드/ 4:꽃
void blossom(){
    int cur_flower=0;
    queue<pair<int,int>> que;

    for(int i=0;i<green.size();i++){
        int y=ground[green[i]].first;
        int x=ground[green[i]].second;
        que.push({y,x});
        map[y][x].first=2;
        map[y][x].second=0;
    }

    for(int i=0;i<red.size();i++){
        int y=ground[red[i]].first;
        int x=ground[red[i]].second;
        que.push({y,x});
        map[y][x].first=3;
        map[y][x].second=0;
    }

    while(!que.empty()){
        int cur_y=que.front().first;
        int cur_x=que.front().second;
        int cur_type=map[cur_y][cur_x].first;
        int cur_time=map[cur_y][cur_x].second;
        que.pop();

        if(map[cur_y][cur_x].first==4)  continue;

        for(int i=0;i<4;i++){
            int next_y=cur_y+d[i][0];
            int next_x=cur_x+d[i][1];
            if(isBoundary(next_y,next_x)&&garden[next_y][next_x]!=0){
                if(map[next_y][next_x].first==1){
                    map[next_y][next_x].first=cur_type;
                    map[next_y][next_x].second=cur_time+1;
                    que.push({next_y,next_x});
                }
                else if(map[next_y][next_x].first==2){
                    if(cur_type==3&&cur_time+1==map[next_y][next_x].second){
                        map[next_y][next_x].first=4;
                        cur_flower++;
                    }
                }
                else if(map[next_y][next_x].first==3){
                    if(cur_type==2&&cur_time+1==map[next_y][next_x].second){
                        map[next_y][next_x].first=4;
                        cur_flower++;
                    }
                }
            }
        }
    }
    
    max_flower=max(max_flower,cur_flower);
}

void chose_red_ground(int index, int num){
    if(num==r){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[i][j].first=1;
                map[i][j].second=0;
            }
        }
        blossom();
        return;
    }

    for(int i=index;i<isCheck.size();i++){
        if(isCheck[i])  continue;

        red[num]=i;
        isCheck[i]=true;
        chose_red_ground(i+1,num+1);
        isCheck[i]=false;
    }

}

void chose_green_ground(int index, int num){
    if(num==g){
        chose_red_ground(0,0);
        return;
    }
    
    for(int i=index;i<isCheck.size();i++){
        if(isCheck[i])  continue;

        green[num]=i;
        isCheck[i]=true;
        chose_green_ground(i+1,num+1);
        isCheck[i]=false;
    }
}

void solve()
{
    isCheck.resize(ground.size(),false);
    green.resize(g);
    red.resize(r);
    map.resize(n,vector<pair<int,int>>(m));

    chose_green_ground(0,0);

    cout<<max_flower;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}