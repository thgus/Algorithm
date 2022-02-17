/*
4991번: 로봇 청소기
https://www.acmicpc.net/problem/4991
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

struct Cleaner{
    int y,x;
    int move_len;
    int clear_bit;
};

bool isBoundary(int y, int x, int max_y, int max_x){
    if(y>=0&&y<max_y&&x>=0&&x<max_x){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<char>> &map, int h, int w, int trash_num, int start_y, int start_x)
{
    int min_step=1e9;
    int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<vector<int>>> dp(h,vector<vector<int>>(w,vector<int>(1<<trash_num,1e9)));

    queue<Cleaner> que;
    que.push({start_y,start_x,0,0});
    dp[start_y][start_x][0]=0;

    while(!que.empty()){
        Cleaner cur=que.front();
        que.pop();

        if(cur.clear_bit==(1<<trash_num)-1){
            min_step=min(min_step,cur.move_len);
            continue;
        }

        if(dp[cur.y][cur.x][cur.clear_bit]>cur.move_len){
            continue;
        }

        int next_len=cur.move_len+1;
        for(int i=0;i<4;i++){
            int next_y=cur.y+d[i][0];
            int next_x=cur.x+d[i][1];
            if(isBoundary(next_y,next_x,h,w)&&map[next_y][next_x]!='x'){
                int next_clear_bit=cur.clear_bit;
                if(map[next_y][next_x]>='0'&&map[next_y][next_x]<'0'+trash_num){
                    int t_index=map[next_y][next_x]-'0';
                    next_clear_bit|=(1<<t_index);
                }

                if(dp[next_y][next_x][next_clear_bit]>next_len){
                    dp[next_y][next_x][next_clear_bit]=next_len;
                    que.push({next_y,next_x,next_len,next_clear_bit});
                }
            }
        }
    }

    if(min_step!=1e9){
        cout<<min_step<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}

void initialize()
{
    int w,h;
    while(1){
        cin>>w>>h;
        if(w==0 && h==0)    break;

        vector<vector<char>> map(h,vector<char>(w));
        int start_y,start_x;
        int trash=0;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];

                if(map[i][j]=='o'){
                    start_y=i;
                    start_x=j;
                }
                else if(map[i][j]=='*'){
                    map[i][j]='0'+trash++;
                }
            }
        }

        solve(map,h,w,trash, start_y,start_x);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}