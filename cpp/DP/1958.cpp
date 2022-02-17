/*
1958번: LCS3
https://www.acmicpc.net/problem/1958

A: dababcf
B: ababdef
C: df
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 3
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve(string str[MAX])
{
    vector<vector<vector<int>>> mat(str[0].size()+1, vector<vector<int>>(str[1].size()+1, vector<int>(str[2].size()+1,0)));
    for (int i = 0; i < str[0].size(); i++)
    {
        for(int j=0;j<str[1].size();j++)
        {
            for(int k=0;k<str[2].size();k++)
            {
                if(str[0][i]==str[1][j]&&str[1][j]==str[2][k]){
                    mat[i+1][j+1][k+1]=mat[i][j][k]+1;
                }
                else{
                    mat[i+1][j+1][k+1]=max(mat[i][j+1][k+1],max(mat[i+1][j+1][k],mat[i+1][j][k+1]));
                }
            }
        }
    }

    cout<<mat[str[0].size()][str[1].size()][str[2].size()];
}

int main()
{
    sync_off;
 
    string str[MAX];
    for(int i=0;i<MAX;i++){
        cin>>str[i];
    }
    solve(str);

    return 0;
}