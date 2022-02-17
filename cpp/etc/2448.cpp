/*
2448번: 별 찍기-11
https://www.acmicpc.net/problem/2448
*/

#include <iostream>
#include <vector>
#include<cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
void initialize()
{
    cin>>n;
}

vector<vector<char>> vec(3072+1,vector<char>(6144+1,' '));
char star[3][6]={
    "  *  ",
    " * * ",
    "*****"
};

void printStar(){
    for(int i=0;i<n;i++){
        for(int j=0;j<(6*(n/3))-1;j++){
            cout<<(vec[i][j]=='*'?'*':' ');
        }
        cout<<"\n";
    }
}

void setStar(int _n, int x, int y){
    if(_n==3){
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                vec[y+i][x+j]=star[i][j];
            }
        }
        //1cout<<x<<" "<<y<<"\n";
        return;
    }
    setStar(_n/2,x,y+(_n/2));
    setStar(_n/2,x+(_n/2),y);
    setStar(_n/2,x+_n,y+(_n/2));
}

void solve()
{
    setStar(n, 0 ,0);
    printStar();
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}