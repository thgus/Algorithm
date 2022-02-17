/*
4902번: 삼각형의 값
https://www.acmicpc.net/problem/4902
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void print_vec(vector<vector<int>> &vec){
    cout<<"\n";
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int n;
int max_value;
void dfs1(vector<vector<int>> &len, int y, int x, int h, int sum){
    if(y==n)  return;

    int k=x+2*h;
    sum+=(x==0)?len[y][k]:len[y][k]-len[y][x-1];
    
    max_value=max(max_value,sum);

    dfs1(len,y+1,x,h+1,sum);
}

void dfs2(vector<vector<int>> &len, int y, int x, int h, int sum){
    int right=x;
    int left=x-2*h;
    int bound=2*y;
    if(left<0||right>bound) return;

    sum+=len[y][right]-len[y][left-1];
    max_value=max(max_value,sum);

    dfs2(len,y-1,x,h+1,sum);
}

int solve(vector<vector<int>> &vec)
{
    max_value=INT_MIN;
    vector<vector<int>> len(n);

    for (int i = 0; i < n; i++){
        int jm = (i + 1) + i;
        int sum = 0;
        for (int j = 0; j < jm; j++)
        {
            sum += vec[i][j];
            len[i].push_back(sum);
        }
    }

    for(int i=0;i<n;i++){
        int jm=(i+1)+i;
        for(int j=0;j<jm;j++){
            max_value=max(max_value,vec[i][j]);

            if(j%2==0){
                dfs1(len,i+1,j,1,vec[i][j]);
            }
            else{
                dfs2(len,i-1,j,1,vec[i][j]);
            }
        }
    }

    return max_value;
}

void input()
{
    int temp;
    int num=1;
    while(1){
        cin>>n;
        if(n==0)    return;

        vector<vector<int>> vec(n);
        for(int i=0;i<n;i++){
            int jm=(i+1)+i;
            for(int j=0;j<jm;j++){
                cin>>temp;
                vec[i].push_back(temp);
            }
        }

        cout<<num++<<". "<<solve(vec)<<"\n";
    }
}

int main()
{
    sync_off;
    input();

    return 0;
}