/*
21608번: 상어 초등학교
https://www.acmicpc.net/problem/21608
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> vec;
vector<vector<bool>> list;
int n;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<n){
        return true;
    }
    else{
        return false;
    }
}

void print_vec(){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

void solve(int a, int b, int c, int d, int e)
{   
    pair<int,int> p;
    int max_friend=-1;
    int max_empty=-1;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(vec[y][x])   continue;

            int cur_friend=0;
            int cur_empty=0;
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];

                if(!isBoundary(ny,nx))  continue;
                if(vec[ny][nx]==0)  cur_empty++;
                if(vec[ny][nx]==b)  cur_friend++;
                if(vec[ny][nx]==c)  cur_friend++;
                if(vec[ny][nx]==d)  cur_friend++;
                if(vec[ny][nx]==e)  cur_friend++;
            }

            if(max_friend<cur_friend){
                max_friend=cur_friend;
                max_empty=cur_empty;

                p.first=y;
                p.second=x;
            }
            else if(max_friend==cur_friend){
                if(max_empty<cur_empty){
                    max_empty=cur_empty;

                    p.first=y;
                    p.second=x;
                }
            }
        }
    }

    vec[p.first][p.second]=a;
}

long long cal_result(){
    long long total_score=0;

    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            int num=0;
            int cur=vec[y][x];
            
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];

                if(!isBoundary(ny,nx))  continue;
                int next=vec[ny][nx];
                if(list[cur][next]) num++;
            }

            if(num==0)  continue;

            int score=1;
            while(--num){
                score*=10;
            }

            total_score+=score;
        }
    }

    return total_score;
}

void initialize()
{
    cin>>n;
    vec.resize(n,vector<int>(n,0));
    list.resize(n*n+1,vector<bool>(n*n+1,false));

    int a,b,c,d,e;
    for(int i=0;i<n*n;i++){
        cin>>a>>b>>c>>d>>e;
        solve(a,b,c,d,e);

        list[a][b]=list[a][c]=list[a][d]=list[a][e]=true;
    }
}

int main()
{
    sync_off;
    initialize();

    cout<<cal_result();

    return 0;
}