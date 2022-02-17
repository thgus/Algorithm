/*
17144번: 미세먼지 안녕!
https://www.acmicpc.net/problem/17144
*/

#include <iostream>
#include <vector>

#define SIZEMAX 50
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r,c,t;
vector<vector<int>> space(SIZEMAX+1,vector<int>(SIZEMAX+1,0));
vector<int> airCleaner;

void initialize()
{
    cin>>r>>c>>t;
    int temp;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>temp;
            space[i][j]=temp;

            //공기청정기가 놓인 곳
            //공기청정기는 항상 1열에 놓여있으므로 행만 기억
            if(temp==-1){
                airCleaner.push_back(i);
            }
        }
    }
}

//먼지 확산
void diffusionDust(){
    int x,y;
    int _x,_y;

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    //먼지가 확산되는 양은 기존에 있던 먼지 양의 1/5배로 확산되어야 하는데
    //순서대로 space를 확인하게 되면서 이전 배열에서 확산된 먼지 양이 더해져
    //다음 배열에서 확산되는 양이 많아지거나 혹은 적어지는 일을 방지하기 위해
    //space를 건들지 않고 새로운 temp라는 배열을 만들어 여기에 확산, 없어지는 먼지 양을 저장
    vector<vector<int>> tempSpace(SIZEMAX+1,vector<int>(SIZEMAX+1,0));
    
    //먼지가 있는 경우 탐색
    for(int y=1;y<=r;y++){
        for(int x=1;x<=c;x++){
            //먼지가 없는 경우 다음 칸으로 이동
            if(space[y][x]<1){
                continue;
            }

            //확산된 방향 갯수
            int diffusionNUM=0;

            //4방향으로 탐색
            for(int i=0;i<4;i++){
                _y=y+d[i][0];
                _x=x+d[i][1];

                //탐색 칸이 공간 범위 내 이고 공기청정기가 없는 칸이라면
                if(_y>=1&&_x>=1&&_y<=r&&_x<=c&&space[_y][_x]!=-1){
                    //먼지 확산
                    tempSpace[_y][_x]+=space[y][x]/5;
                    //확산된 방향 증가
                    diffusionNUM++;
                }
            }

        //확산된 방향 만큼 현재 장소의 먼지 없어짐
        tempSpace[y][x]-=(space[y][x]/5)*diffusionNUM;
        }
    }

    //확산되고 없어지는 먼지양을 space에 반영
    for(int y=1;y<=r;y++){
        for(int x=1;x<=c;x++){
            space[y][x]+=tempSpace[y][x];
        }
    }

}

//현재 공간 상태 프린트
void printSpace(){
    cout<<"\n";
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout<<space[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//공기청정기 작동
//공기청정기가 위에서는 반시계 아래서는 시계방향으로 돌아가니
//거꾸로 탐색(위의 경우 → ↑ ← ↓ 방향으로 움직였다면 반대로 ↑ → ↓ ←로 이동)하면서 먼지를 한칸 앞으로 변경함
void operatingAirCleaner(){
    int topX,topY;
    int downX, downY;
    int top, down;

    for(int i=0;i<airCleaner.size();i+=2){
        top=airCleaner[i];
        down=airCleaner[i+1];

        topY=top-1;
        topX=1;
        downY=down+1;
        downX=1;

        //1번째
        while(topY>1){
            space[topY][topX]=space[topY-1][topX];
            topY-=1;
        }
        while(downY<r){
            space[downY][downX]=space[downY+1][downX];
            downY+=1;
        }
        
        //2번째
        while(topX<c&&downX<c){
            space[topY][topX]=space[topY][topX+1];
            topX+=1;
            space[downY][downX]=space[downY][downX+1];
            downX+=1;
        }

        //printSpace();

        //3번째
        while(downY>down){
            space[downY][downX]=space[downY-1][downX];
            downY-=1;
        }
        while(topY<top){
            space[topY][topX]=space[topY+1][topX];
            topY+=1;
        }
        
        //4번째
        while(topX>2&&downX>2){
            space[topY][topX]=space[topY][topX-1];
            space[downY][downX]=space[downY][downX-1];
            downX-=1; topX-=1;
        }

        space[top][2]=0;
        space[down][2]=0;

    }
}

int sumDust(){
    int sum=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(space[i][j]>0){
                sum+=space[i][j];
            }
        }
    }

    return sum;
}

void solve()
{
    while(t-->0){
        diffusionDust();
        //printSpace();
        operatingAirCleaner();
        //printSpace();
    }
    cout<<sumDust();
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}