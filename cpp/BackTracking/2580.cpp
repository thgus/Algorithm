/*
2580번: 스도쿠
https://www.acmicpc.net/problem/2580
*/

#include <iostream>
#include <vector>

#define MAX 9
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> sudoku(MAX, vector<int>(MAX));
vector<pair<int, int>> blank;

void initialize()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
            {
                blank.push_back({i, j});
            }
        }
    }
}

void printResult(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool backTracking(int s)
{
    if(s==blank.size()){
        return true;
    }

    int y = blank[s].first;
    int x = blank[s].second;

    for(int cur=1;cur<=MAX;cur++){
        bool isContinue=false;
        
        for(int i=0;i<MAX;i++){
            if(sudoku[y][i]==cur||sudoku[i][x]==cur){
                isContinue=true;
                break;
            }
        }
        if(isContinue)  continue;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int _x=(x/3)*3+j;
                int _y=(y/3)*3+i;
                if(sudoku[_y][_x]==cur){
                    isContinue=true;
                    break;
                }
            }
        }
        if(isContinue)  continue;

        sudoku[y][x]=cur;
        if(!backTracking(s+1)){
            sudoku[y][x]=0;
        }
        else{
            return true;
        }

    }

    return false;
}

void solve()
{
    backTracking(0);
    printResult();
}

int main()
{
    initialize();
    solve();

    return 0;
}