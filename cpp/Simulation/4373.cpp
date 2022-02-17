/*
5373번: 큐빙
https://www.acmicpc.net/problem/5373
*/

#include <iostream>
#include <vector>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void print_cube(vector<vector<vector<char>>> &cube, int index){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<cube[index][i][j];
        }
        cout<<"\n";
    }    
}

int get_turn_index(char c){ 
    switch(c){
        case 'U':  
            return 0;
        case 'D':  
            return 1;
        case 'F':  
            return 2;
        case 'B':  
            return 3;
        case 'L':  
            return 4;
        case 'R':  
            return 5;
    }
}

void turn(vector<vector<vector<char>>> &cube, int c, bool isForward){
    vector<vector<char>> vec(3,vector<char>(3));
    vec[1][1]=cube[c][1][1];
    
    if(isForward){
        for(int i=0;i<3;i++){
            vec[i][2]=cube[c][0][i];
            vec[2][2-i]=cube[c][i][2];
            vec[0][i]=cube[c][2-i][0];
            vec[2-i][0]=cube[c][2][2-i];
        }
    }
    else{
        for(int i=0;i<3;i++){
            vec[2-i][0]=cube[c][0][i];
            vec[0][i]=cube[c][i][2];
            vec[i][2]=cube[c][2][2-i];
            vec[2][2-i]=cube[c][2-i][0];
        }
    }

    cube[c]=vec;
}

void turn_side(vector<vector<vector<char>>> &cube, int c, bool isForward)
{
    // U: 윗 면 (0), D: 아랫 면 (1), F: 앞 면 (2), B: 뒷 면 (3), L: 왼쪽 면 (4), R: 오른쪽 면 (5)
    int d[6][4]={{2,4,3,5},{2,5,3,4},{0,5,1,4},{0,4,1,5},{0,2,1,3},{0,3,1,2}};
    int turn_seq[4][3][2]={{{0,0},{0,1},{0,2}},{{0,2},{1,2},{2,2}},{{2,2},{2,1},{2,0}},{{2,0},{1,0},{0,0}}};
    int turn_index[6][4]={{0,0,0,0},{2,2,2,2},{2,3,0,1},{0,3,2,1},{3,3,3,1},{1,3,1,1}};

    int temp[4][3];
    for (int i = 0; i < 4; i++)
    {
        int index = turn_index[c][i];
        int cur_side = d[c][i];
        for (int j = 0; j < 3; j++)
        {
            temp[i][j] = cube[cur_side][turn_seq[index][j][0]][turn_seq[index][j][1]];
        }
    }

    for(int i=0;i<4;i++){
        int index=turn_index[c][i];
        int cur_side=d[c][i];
        int next;
        if(isForward){
            next=(i-1);
            if(next<0)  next=3;
        }
        else{
            next=(i+1)%4;
        }

        for(int j=0;j<3;j++){
            cube[cur_side][turn_seq[index][j][0]][turn_seq[index][j][1]]=temp[next][j];
            //cube[cur_side][i][j]=temp[next][j];
        }
    }
}

void initialize()
{
    // U: 윗 면 (0), D: 아랫 면 (1), F: 앞 면 (2), B: 뒷 면 (3), L: 왼쪽 면 (4), R: 오른쪽 면 (5)
    vector<vector<vector<char>>> beginning(6,vector<vector<char>>(3,vector<char>(3)));
    string str="wyrogb";
    //string str="udfblr";
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                beginning[i][j][k]=str[i];
                //beginning[i][j][k]='0'+j*3+k;
            }
        }
    }

    int t,n;
    cin>>t;

    while(t--){
        vector<vector<vector<char>>> cube=beginning;
        int n;
        cin>>n;
        while(n--){
            cin>>str;
            int turn_index=get_turn_index(str[0]);

            if(str[1]=='+'){
                turn_side(cube,turn_index,true);
                turn(cube,turn_index,true);
            }
            else{
                turn_side(cube,turn_index,false);
                turn(cube,turn_index,false);
            }
        }

        print_cube(cube,0);
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}