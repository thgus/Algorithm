/*
3190번: 뱀
https://www.acmicpc.net/problem/3190
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map;
priority_queue<pair<int,char>> pq;

void initialize()
{
    cin>>n;
    map.resize(n,vector<int>(n,-1));

    int k;
    cin>>k;
    int a,b;
    while(k--){
        cin>>a>>b;
        map[a-1][b-1]=0;
    }

    int l;
    cin>>l;

    int t;
    char c;
    while(l--){
        cin>>t>>c;
        pq.push({-t,c});
    }
}

int d[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int turn_direction(int d, char c){
    switch(d){
        case 1:
            if(c=='L')    return 4;
            if(c=='D')    return 3;
        case 2:
            if(c=='L')    return 3;
            if(c=='D')    return 4;
        case 3:
            if(c=='L')    return 1;
            if(c=='D')    return 2;
        case 4:
            if(c=='L')    return 2;
            if(c=='D')    return 1;
    }
}

bool isBoundary(int y, int x){
    if(y>=0&&y<n&&x>=0&&x<n){
        return true;
    }
    else{
        return false;
    }
}

void print_vec(vector<vector<int>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve()
{
    pair<int,int> head={0,0};
    pair<int,int> tail={0,0};
    int dir=1, t=1;
    map[0][0]=1;

    while(1){
        int ny=head.first+d[dir][0];
        int nx=head.second+d[dir][1];

        if(!isBoundary(ny,nx))  break;
        if(map[ny][nx]>0)  break;

        if(map[ny][nx]==-1){
            int ty=tail.first+d[map[tail.first][tail.second]][0];
            int tx=tail.second+d[map[tail.first][tail.second]][1];
            map[tail.first][tail.second]=-1;
            tail={ty,tx};
        }

        map[ny][nx]=dir;
        head.first=ny;
        head.second=nx; 

        if(-pq.top().first==t){
            dir=turn_direction(dir,pq.top().second);
            map[head.first][head.second]=dir;
            pq.pop();
        } 
        //cout<<t<<":";
        //print_vec(map);
        t++;
    }

    cout<<t;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}