/*
16236번: 아기 상어
https://www.acmicpc.net/problem/16236
*/

#include<iostream>
#include<vector>
#include<queue>

#define MAX 20
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> space(MAX,vector<int>(MAX));

int x,y;

struct BabyShark{
    int size=2;
    int feedNum=0;
};

void initialize(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>space[i][j];

            //아기상어 스타팅 포인트
            if(space[i][j]==9){
                space[i][j]=0;
                y=i;
                x=j;
            }
        }
    }
}

//움직인 시간 반환
int findFeed(BabyShark &bs){
    queue<pair<int,pair<int,int>>> que;
    vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,false));
    que.push({0,{y,x}});
    isVisited[y][x]=true;

    int x1,x2,y1,y2;
    int d[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
    int len=-1;

    while(!que.empty()){
        y1=que.front().second.first;
        x1=que.front().second.second;

        if (space[y1][x1] > 0 && space[y1][x1] < bs.size) //빈공간이 아니고 물고기가 아기상어가 먹을 수 있는 크기일때
        {
            if (len != -1)
            {
                //cout<<y1<<" "<<x1<<"\n";
                if (len < que.front().first)
                {
                    break;
                }
                if ((y > y1) || (y == y1 && x > x1))
                {
                    y = y1;
                    x = x1;
                }
            }
            else
            {
                y = y1; x = x1;
                len = que.front().first;
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                y2 = y1 + d[i][0];
                x2 = x1 + d[i][1];

                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n)
                {
                    if (!isVisited[y2][x2] && space[y2][x2] <= bs.size)
                    {
                        isVisited[y2][x2] = true;
                        que.push({que.front().first + 1, {y2, x2}});
                    }
                }
            }
        }
        que.pop();
    }

    if(len!=-1){
        space[y][x]=0;
        bs.feedNum++;
        return len;
    }
    else{
        //움직인 시간 없음 => 먹이를 찾을 수 없음.
        return 0;
    }
}

void solve(){
    BabyShark bs;
    int time;
    int maxTime=0;

    while(1){
        time=findFeed(bs);
        if(time==0){
            cout<<maxTime;
            break;
        }
        maxTime+=time;
        //cout<<y<<" "<<x<<" "<<maxTime<<endl;
        if(bs.size==bs.feedNum){
            bs.size++;
            bs.feedNum=0;
        }
    }

}

int main(){
    sync_off;
    initialize();
    solve();
    
    return 0;
}