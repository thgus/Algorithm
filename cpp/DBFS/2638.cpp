/*
2638번: 치즈
https://www.acmicpc.net/problem/2638

악 잘못풀었어
내일할래...
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<bool>> cheese(MAX,vector<bool>(MAX,false));
int leftCheese=0;

void initialize()
{
    cin>>n>>m;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            if(temp==1){
                cheese[i][j]=true;
                leftCheese++;
            }
        }
    }
}

int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void printStat(vector<vector<int>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printStat(vector<vector<bool>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void melt(){
    queue<pair<int,int>> que;
    vector<vector<int>> vec(MAX,vector<int>(MAX,0));
    vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,0));
    que.push({0,0});
    isVisited[0][0]=true;

    int x1,x2,y1,y2;
    while(!que.empty()){
        y1=que.front().first;
        x1=que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            x2=x1+d[i][0];
            y2=y1+d[i][1];
            if(x2>=0&&y2>=0&&x2<m&&y2<n){
                vec[y2][x2]+=1;
                if(!isVisited[y2][x2]&&!cheese[y2][x2]){
                    que.push({y2,x2});
                    isVisited[y2][x2]=true;
                }
            }
        }     
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cheese[i][j]&&vec[i][j]>=2){
                cheese[i][j]=false;
                leftCheese--;
            }
        }
    }

    //printStat(isVisited);
}

void solve()
{
    int time=0;
    while(leftCheese>0){
        melt();
        time++;
        //printStat(cheese);
    }
    cout<<time;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}