#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int getNextDirection(int i){
    if(i==0){
        return 3;
    }
    else if(i==1){
        return 0;
    }
    else if(i==2){
        return 1;
    }
    else if(i==3){
        return 2;
    }
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int r,c,d;
    //d=0 북쪽, d=1 동쪽, d=2 남쪽, d=3 서쪽
    scanf("%d%d%d",&r,&c,&d);

    bool **map;
    bool **isVisited;

    map=(bool**)malloc(sizeof(bool*)*n);
    isVisited=(bool**)malloc(sizeof(bool*)*n);

    for(int i=0;i<n;i++){
        map[i]=(bool*)malloc(sizeof(bool)*m);
        isVisited[i]=(bool*)malloc(sizeof(bool)*m);
        memset(isVisited[i],false,sizeof(bool)*m);
        
        int temp;
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            map[i][j]=(temp==0)?false:true;
        }
    }

    int count=0;

    int dy[4]={-1,0,1,0};
    int dx[4]={0,1,0,-1};
    while(1){
        if(!isVisited[r][c]){
            isVisited[r][c]=true;
            count++;
        }

        int tempd=d;
        bool canGo=false;
        int nexty=0,nextx=0;

        for(int i=0;i<4;i++){
            tempd=getNextDirection(tempd);
            nexty=r+dy[tempd];
            nextx=c+dx[tempd];
            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m){
                if (!isVisited[nexty][nextx] && !map[nexty][nextx]){
                    canGo = true;
                    r=nexty;    c=nextx;    d=tempd;
                    break;
                }
            }
        }

        if(!canGo){
            nexty=r+dy[(d+2)%4];
            nextx=c+dx[(d+2)%4];
            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m&&!map[nexty][nextx]){
                r=nexty;
                c=nextx;
            }
            else{
                break;
            }
        }
    }

    printf("%d",count);

    return 0;
}