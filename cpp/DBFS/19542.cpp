/*
19542번: 전단지 돌리기
https://www.acmicpc.net/problem/19542
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,s,d;
vector<vector<int>> vec(MAX+1);

void initialize()
{
    cin>>n>>s>>d;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
}

vector<int> isVisited(MAX+1,-1);
int result=0;
int dfs(int start){
    if(vec[start].size()==0){
        return isVisited[start]=1; 
    }

    int maxLen=0;
    isVisited[start]=0;

    for(int i=0;i<vec[start].size();i++){
        int next=vec[start][i];
        if(isVisited[next]==-1){
            isVisited[next]=true;

            result++;
            int len=dfs(next);

            if(len<=d){
                result-=1;
            }
            else{
                result+=1;
            }

            maxLen=max(maxLen,len);
        }
    }

    return isVisited[start]=maxLen+1;
} 

void solve()
{
    isVisited[s]=0;
    dfs(s);
    cout<<result;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}