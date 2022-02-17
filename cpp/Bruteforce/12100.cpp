/*
12100번: 2048(Easy)
https://www.acmicpc.net/problem/12100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 20
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> vec(MAX,vector<int>(MAX));

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
}

void sort2048(int d){
    for(int i=0;i<n;i++){
        vector<int> num;
        for(int j=0;j<n;j++){
            (d==0||d==1) ? num.push_back(vec[j][i]):num.push_back(vec[i][j]);
        }

        if(d==1||d==3){
            reverse(num.begin(),num.end());
        }
    
        int index=0;
        int y,x;

        vector<int> temp(n,0);
        for(int j=0;j<num.size();j++){
            if(num[j]==0){
                continue;
            }

            if(temp[index]==0){
                temp[index]=num[j];
            }
            else if(temp[index]==num[j]){
                temp[index]+=num[j];
                index++;
            }
            else{
                temp[++index]=num[j];
            }
        }

        if(d==1||d==3){
            reverse(temp.begin(),temp.end());
        }

        for(int j=0;j<n;j++){
            (d==0||d==1)?vec[j][i]=temp[j]:vec[i][j]=temp[j];
        }

    }
}

int maxBlock=0;
void bk(vector<vector<int>> board, int cnt){
    if(cnt==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxBlock=max(maxBlock,vec[i][j]);
            }
        }
        return;
    }

    //0: 위, 1: 아래, 2: 왼, 3: 오
    for(int i=0;i<4;i++){
        sort2048(i);

        bk(vec, cnt + 1);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                vec[i][j] = board[i][j];
            }
        }
    }

}

void solve()
{
    bk(vec,0);
    cout<<maxBlock;    
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}