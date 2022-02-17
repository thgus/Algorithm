/*
14500번: 테트로미노
https://www.acmicpc.net/problem/14500
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

//세로크기 n, 가로크기 m
int n,m;
//종이에 쓰여 있는 수
vector<vector<int>> paper(MAX,vector<int>(MAX));

void initialize()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>paper[i][j];
        }
    }
}

int type1(int y, int x){
    int score1=0;
    int score2=0;
    if(y+3<n){
        score1=paper[y][x]+paper[y+1][x]+paper[y+2][x]+paper[y+3][x];
    }
    if(x+3<m){
        score2=paper[y][x]+paper[y][x+1]+paper[y][x+2]+paper[y][x+3];
    }
    return max(score1,score2);
}

int type2(int y, int x){
    int score=0;
    if(x+1<m&&y+1<n){
        score=paper[y][x]+paper[y+1][x]+paper[y][x+1]+paper[y+1][x+1];
    }
    return score;
}

int type3(int y, int x){
    int score1=0, score2=0, score3=0,score4=0;
    if(y+2<n&&x+1<m){
        score1=paper[y][x]+paper[y+1][x]+paper[y+2][x]+paper[y+2][x+1];
        score2=paper[y][x]+paper[y][x+1]+paper[y+1][x+1]+paper[y+2][x+1];
    }
    if(y+1<n&&x+2<m){
        score3=paper[y][x]+paper[y+1][x]+paper[y][x+1]+paper[y][x+2];
        score4=paper[y+1][x]+paper[y+1][x+1]+paper[y+1][x+2]+paper[y][x+2];
    }

    return max(score1,max(score2,max(score3,score4)));
}

int type4(int y, int x){
    int score1=0, score2=0;
    if(y+2<n&&x+1<m){
        score1=paper[y][x]+paper[y+1][x]+paper[y+1][x+1]+paper[y+2][x+1];
    }
    if(y+1<n&&x+2<m){
        score2=paper[y+1][x]+paper[y+1][x+1]+paper[y][x+1]+paper[y][x+2];
    }

    return max(score1,score2);
}

int type5(int y, int x){
    int score1=0, score2=0, score3=0,score4=0;
    if(x+2<m&&y+1<n){
        score1=paper[y][x]+paper[y][x+1]+paper[y+1][x+1]+paper[y][x+2];
        score2=paper[y+1][x]+paper[y+1][x+1]+paper[y][x+1]+paper[y+1][x+2];
    }
    if(x+1<m&&y+2<n){
        score3=paper[y][x+1]+paper[y+1][x+1]+paper[y+1][x]+paper[y+2][x+1];
        score4=paper[y][x]+paper[y+1][x]+paper[y+2][x]+paper[y+1][x+1];
    }

    return max(score1,max(score2,max(score3,score4)));
}

int type6(int y, int x){
    int score1=0, score2=0, score3=0,score4=0;
    if(y+2<n&&x+1<m){
        score1=paper[y+2][x]+paper[y][x+1]+paper[y+1][x+1]+paper[y+2][x+1];
        score2=paper[y][x]+paper[y][x+1]+paper[y+1][x]+paper[y+2][x];
    }
    if(y+1<n&&x+2<m){
        score3=paper[y][x]+paper[y+1][x+2]+paper[y][x+1]+paper[y][x+2];
        score4=paper[y][x]+paper[y+1][x]+paper[y+1][x+1]+paper[y+1][x+2];
    }

    return max(score1,max(score2,max(score3,score4)));
}

int type7(int y, int x){
    int score1=0, score2=0;
    if(y+2<n&&x+1<m){
        score1=paper[y][x+1]+paper[y+1][x]+paper[y+1][x+1]+paper[y+2][x];
    }
    if(y+1<n&&x+2<m){
        score2=paper[y][x]+paper[y+1][x+1]+paper[y][x+1]+paper[y+1][x+2];
    }

    return max(score1,score2);
}

void solve()
{
    int maxScore=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxScore=max(maxScore,max(type1(i,j),max(type2(i,j),max(type3(i,j),max(type4(i,j),type5(i,j))))));
            maxScore=max(maxScore,max(type6(i,j),type7(i,j)));
        }
    }
    cout<<maxScore;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}