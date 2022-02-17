#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void dfs(int **graph, bool *isVisited, int *gSize, int cur){
    isVisited[cur]=true;
    for(int i=0;i<gSize[cur];i++){
        int next=graph[cur][i];
        if(!isVisited[next]){
            dfs(graph,isVisited,gSize,next);
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int **graph;
    graph=(int**)malloc(sizeof(int*)*(n+1));

    int *gSize=(int*)malloc(sizeof(int)*(n+1));
    memset(gSize,0,sizeof(int)*(n+1));

    for(int i=1;i<=n;i++){
        graph[i]=(int*)malloc(0);
    }
    
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);  
        int indexA=gSize[a]++;
        int indexB=gSize[b]++;

        graph[a]=(int*)realloc(graph[a],(indexA+1)*sizeof(int));
        graph[b]=(int*)realloc(graph[b],(indexB+1)*sizeof(int));

        graph[a][indexA]=b;
        graph[b][indexB]=a;
    }

    bool *isVisited;
    isVisited=(bool*)malloc(sizeof(bool)*(n+1));
    memset(isVisited,false,(n+1));
    
    int result=0;
    for(int i=1;i<=n;i++){
        if(isVisited[i]){
            continue;
        }
        result++;
        dfs(graph,isVisited,gSize,i);
    }
    printf("%d",result);

    return 0;
}