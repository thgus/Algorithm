/*
4577번:소코반 
https://www.acmicpc.net/problem/4577
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int alter(char c){
    switch(c){
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'L':
            return 2;
        case 'R':  
            return 3;
    }
}

void print_vec(int num, bool compleate, vector<vector<char>> &map){
    cout<<"Game "<<num<<": ";
    if(compleate){
        cout<<"complete\n";
    }
    else{
        cout<<"incomplete\n";
    }

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    sync_off;

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int count=1;

    while(1){
        int n,m;
        cin>>n>>m;
        if(m==0&&m==0)  break;
        vector<vector<char>> map(n,vector<char>(m));
        
        int left_box=0;
        int player_y,player_x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>map[i][j];

                if(map[i][j]=='w'||map[i][j]=='W'){
                    player_y=i;
                    player_x=j;
                }
                else if(map[i][j]=='b'){
                    left_box++;
                }
            }
        }

        string str;
        cin>>str;
        for(int i=0;i<str.size();i++){
            int dir=alter(str[i]);

            int ny=player_y+d[dir][0];
            int nx=player_x+d[dir][1];

            if(map[ny][nx]=='#')  continue;
            else if(map[ny][nx]=='.'){
                map[ny][nx]='w';
            }
            else if(map[ny][nx]=='+'){
                map[ny][nx]='W';
            }
            else if(map[ny][nx]=='b'||map[ny][nx]=='B'){
                int nby=player_y+d[dir][0]*2;
                int nbx=player_x+d[dir][1]*2;

                if(map[nby][nbx]=='.'||map[nby][nbx]=='+'){
                    if(map[nby][nbx]=='.'){
                        map[nby][nbx]='b';
                    }
                    else if(map[nby][nbx]=='+'){
                         map[nby][nbx]='B';
                         left_box--;
                    }
                    
                    if(map[ny][nx]=='b'){
                        map[ny][nx]='w';
                    }
                    else if(map[ny][nx]=='B'){
                        map[ny][nx]='W';
                        left_box++;
                    }
                }
                else{
                    continue;
                }
            }

            map[player_y][player_x]=(map[player_y][player_x]=='W')?'+':'.';
            player_y=ny;
            player_x=nx;

            if(left_box==0) break;
        }
        
        if(left_box){
            print_vec(count++,false,map);
        }
        else{
            print_vec(count++,true,map);
        }
    }
    return 0;
}