/*
15685번: 드래곤 커브
https://www.acmicpc.net/problem/15685
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<bool>> map(101,vector<bool>(101,false));

int turn90_direction(int d){
    switch(d){
        case 0: return 1;
        case 1: return 2;
        case 2: return 3;
        case 3: return 0;
    }
}

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

void curve_start(int x, int y, int d, int g){
    vector<int> save_direction;
    save_direction.push_back(d);
    map[y][x]=true;

    x+=dx[d];
    y+=dy[d];
    map[y][x]=true;

    while(g--){
        for(int i=save_direction.size()-1;i>=0;i--){
            int cdirection=save_direction[i];
            cdirection=turn90_direction(cdirection);
            //save_direction[i]=cdirection;
            save_direction.push_back(cdirection);

            x+=dx[cdirection];
            y+=dy[cdirection];
            map[y][x]=true;
        }
    }
}

void print_map(){
    int mlen=9;
    for(int i=0;i<=mlen;i++){
        for(int j=0;j<=mlen;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    sync_off;
    
    int n;
    cin>>n;

    int x,y,d,g;
    while(n--){
        cin>>x>>y>>d>>g;
        curve_start(x,y,d,g);
    }

    int result=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(map[i][j]&&map[i+1][j]&&map[i][j+1]&&map[i+1][j+1]){
                result++;
            }
        }
    }
    cout<<result;

    return 0;
}