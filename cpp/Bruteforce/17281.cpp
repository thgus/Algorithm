/*
17281번: 야구
https://www.acmicpc.net/problem/18281
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> result;

void initialize()
{
    cin>>n;

    result.resize(n,vector<int>(10));
    for(int i=0;i<n;i++){
        for(int j=1;j<=9;j++){
            cin>>result[i][j];
        }
    }
}

vector<bool> visited(10,false);
vector<int> seq(10);

int max_score=0;
void cal_score(){
    int index=1;
    int score=0;

    int baseman1,baseman2,baseman3;
    for(int i=0;i<n;i++){
        int life=3;
        baseman1=baseman2=baseman3=0;
        while(life){
            int cur_player=seq[index];
            int cur_result=result[i][cur_player];

            switch(cur_result){
                case 0:
                    life--;
                    break;
                case 1:
                    score+=baseman3;
                    baseman3=baseman2;
                    baseman2=baseman1;
                    baseman1=1;
                    break;
                case 2:
                    score+=baseman3+baseman2;
                    baseman3=baseman1;
                    baseman2=1;
                    baseman1=0;
                    break;
                case 3:
                    score+=baseman3+baseman2+baseman1;
                    baseman3=1;
                    baseman2=baseman1=0;
                    break;
                case 4:
                    score+=baseman3+baseman2+baseman1+1;
                    baseman3=baseman2=baseman1=0;
                    break;
            }
            index=(index%9)+1;
        }
    }

    max_score=max(max_score,score);
}

void dfs(int num){
    if(num==4){
        dfs(num+1);
        return;
    }

    if(num==10){
        cal_score();
        return;
    }

    for(int i=2;i<=9;i++){
        if(visited[i])  continue;
        visited[i]=true;
        seq[num]=i;
        dfs(num+1);
        visited[i]=false;
    }
}

void solve()
{
    seq[4]=1;
    visited[1]=true;
    dfs(1);

    cout<<max_score;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}