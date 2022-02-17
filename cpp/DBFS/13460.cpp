/*
13460번: 구슬 탈출 2
https://www.acmicpc.net/problem/13460
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 10
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<char>> board(MAX,vector<char>(MAX));

pair<int,int> redStart;
pair<int,int> blueStart;

void initialize()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]=='B'){
                blueStart=make_pair(i,j);
            }
            else if(board[i][j]=='R'){
                redStart=make_pair(i,j);
            }
        }
    }
}

struct MARBLE{
    pair<int,int> red;
    pair<int,int> blue;
};

int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool moveMarble(int i, int &y, int &x, int comy, int comx){
    //벽에 도달하기 전 까지
    while(board[y][x]!='#'&&!(y==comy&&x==comx)){
        //출구
        y+=d[i][0];
        x+=d[i][1];
        if(board[y][x]=='O'){
            return true;
        }
    }

    y-=d[i][0];
    x-=d[i][1];
    return false;
}

bool isVisited[MAX][MAX][MAX][MAX];
int solve()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    isVisited[i][j][k][l]=false;
                }
            }
        }
    }

    queue<pair<int,MARBLE>> que;
    MARBLE temp;
    temp.red=redStart; temp.blue=blueStart;
    que.push({0,temp});
    isVisited[redStart.first][redStart.second][blueStart.first][blueStart.second]=true;
    
    while(!que.empty()){
        int cnt=que.front().first;
        pair<int,int> red=que.front().second.red;
        pair<int,int> blue=que.front().second.blue;
        que.pop();

        if(cnt>=10){
            continue;
        }
        
        bool isFine=true;
        for(int i=0;i<4;i++){
            int ry=red.first;   int rx=red.second;
            int by=blue.first;  int bx=blue.second;

            bool isRedFirst;
            switch(i){
                case 0:
                    (ry<by)?isRedFirst=true:isRedFirst=false;
                    break;
                case 1:
                    (ry<by)?isRedFirst=false:isRedFirst=true;
                    break;
                case 2:
                    (rx<bx)?isRedFirst=true:isRedFirst=false;
                    break;
                case 3:
                    (rx<bx)?isRedFirst=false:isRedFirst=true;
                    break;
            }

            bool redResult;
            bool blueResult;
            if(isRedFirst){
                redResult = moveMarble(i,ry,rx,by,bx);
                blueResult = moveMarble(i,by,bx,ry,rx);
            }
            else{
                blueResult = moveMarble(i,by,bx,ry,rx);    
                redResult = moveMarble(i,ry,rx,by,bx);            
            }

            if(blueResult){
                continue;
            }
            else if(redResult){
                return cnt+1;
            }

            if(!isVisited[ry][rx][by][bx]){
                isVisited[ry][rx][by][bx]=true;
                MARBLE mar;
                mar.red.first=ry; mar.red.second=rx;
                mar.blue.first=by; mar.blue.second=bx;
                que.push({cnt+1,mar});
            }

        }
    }

    return -1;
}

int main()
{
    //sync_off;
    initialize();
    cout<<solve();

    return 0;
}