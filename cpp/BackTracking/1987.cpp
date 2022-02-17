/*
1987번: 알파벳
https://www.acmicpc.net/problem/1987
*/

#include<iostream>
#include<vector>

#define MAX 20
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int r,c;

vector<vector<char>> vec(MAX,vector<char>(MAX));
void initialize(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>vec[i][j];
        }
    }
}

int d[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
vector<bool> isVisitedAlp(26);
int maxLen=0;

void dfs(int x, int y, int len){
    int _x,_y;

    if (maxLen < len)
    {
        maxLen = len;
    }

    for (int k = 0; k < 4; k++)
    {
        _y = y + d[k][0];
        _x = x + d[k][1];
        if (_y >= 0 && _y < r && _x >= 0 && _x < c)
        {
            if (!isVisitedAlp[vec[_y][_x] - 'A'])
            {
                isVisitedAlp[vec[_y][_x] - 'A'] = true;
                dfs(_x, _y, len + 1);
                isVisitedAlp[vec[_y][_x] - 'A'] = false;
            }
        }
    }
}

void solve(){
    isVisitedAlp[vec[0][0]-'A']=true;
    dfs(0,0,1);
    cout<<maxLen;
}

int main(){
    sync_off;
    initialize();
    solve();

    return 0;
}