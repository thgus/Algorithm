/*
1035번: 조각 움직이기
https://www.acmicpc.net/problem/1035
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 5
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<bool> vec((1<<(MAX*MAX)),false);
int s_bit;
int n;

void initialize()
{
    char temp;
    s_bit=n=0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cin>>temp;
            if(temp=='*'){
                s_bit|=(1<<(i*MAX+j));
                n++;
            }
        }
    }
}

void print_map(int a){
    cout<<"\n";
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(a&(1<<(i*MAX+j))){
                cout<<"*";
            }
            else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<MAX&&x>=0&&x<MAX){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    queue<pair<int,int>> que;
    vec[s_bit]=true;
    que.push({0,s_bit});
    
    int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    while(!que.empty()){
        int cur_move=que.front().first;
        int cur_bit=que.front().second;
        que.pop();

        for(int i=0;i<MAX*MAX;i++){
            if(cur_bit&(1<<i)){
                int next_bit=cur_bit&(~(1<<i));
                int cur_y=i/MAX;
                int cur_x=i%MAX;

                for(int j=0;j<4;j++){
                    int next_y=cur_y+d[j][0];
                    int next_x=cur_x+d[j][1];
                    if(isBoundary(next_y,next_x)){
                        if(!vec[next_bit|(1<<(next_y*MAX+next_x))]){
                            vec[next_bit|(1<<(next_y*MAX+next_x))]=true;
                            que.push({cur_move+1,next_bit|(1<<(next_y*MAX+next_x))});
                        }
                    }
                }

                s_bit=i;
            }
        }

        int cur_pice=0;
        vector<vector<bool>> isVisited(MAX,vector<bool>(MAX,false));
        queue<pair<int,int>> q;
        q.push({s_bit/MAX,s_bit%MAX});
        isVisited[s_bit/MAX][s_bit%MAX]=true;

        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            cur_pice++;

            for(int i=0;i<4;i++){
                int next_y=y+d[i][0];
                int next_x=x+d[i][1];
                if(isBoundary(next_y,next_x)&&(cur_bit&(1<<(next_y*MAX+next_x)))){
                    if(!isVisited[next_y][next_x]){
                        isVisited[next_y][next_x]=true;
                        q.push({next_y,next_x});
                    }
                }
            }
        }

        if(cur_pice==n){
            cout<<cur_move;
            break;
        }
        
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}