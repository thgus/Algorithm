/*
14939번: 불 끄기
https://www.acmicpc.net/problem/14939

참고
https://blog.naver.com/pasdfq/221206211990
*/

#include <iostream>
#include <vector>

#define MAX 10
#define ON 'O'
#define OFF '#'
#define INF 1e9
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<string> status;
int n;

void initialize()
{
    n=MAX;
    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        status.push_back(temp);
    }
}

void convertSwitch(vector<string> &vec, int y, int x){
    (vec[y][x]==OFF)?vec[y][x]=ON:vec[y][x]=OFF;

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    for(int i=0;i<4;i++){
        int cury=y+d[i][0];
        int curx=x+d[i][1];
        if(cury>=0&&curx>=0&&cury<n&&curx<n){
            (vec[cury][curx]==OFF)?vec[cury][curx]=ON:vec[cury][curx]=OFF;
        }
    }
}

void solve()
{
    int result=INF;
    for(int i=0;i<(1<<n);i++){
        vector<string> copy=status;
        int ret=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))>0){
                convertSwitch(copy,0,j);
                ret++;
            }
        }

        for(int j=1;j<n;j++){
            for(int k=0;k<n;k++){
                if(copy[j-1][k]==ON){
                    convertSwitch(copy,j,k);
                    ret++;
                }
            }
        }

        bool isAllOff=true;
        for(int j=0;j<n;j++){
            if(copy[n-1][j]==ON){
                isAllOff=false;
                break;
            }
        }

        if(isAllOff){
            if(result>ret){
                result=ret;
            }
        }
    }

    if(result==INF){
        cout<<"-1";
    }
    else{
        cout<<result;
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}