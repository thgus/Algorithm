/*
2233번: 사과나무
https://www.acmicpc.net/problem/2233
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

#define MAX 2000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int x,y;
int _x,_y;
int maxDepth;
string str;

vector<pair<int,int>> state(MAX+1);

void makeTree(vector<int> &depth, vector<vector<int>> &parent){
    //first: num, second: depth
    stack<pair<int,int>> s;

    depth[1]=1;
    s.push({1,1});
    state[1].first=1;
    if(1==_x)   x=1;
    if(1==_y)   y=1;

    int cur=0;

    int index=1;
    int num=1;

    while(!s.empty()){
        int curNum=s.top().first;
        int curDepth=s.top().second;

        int temp;

        index++;
        if(str[index-1]=='0'){
            parent[++num][0]=curNum;
            state[num].first=index;
            depth[num]=curDepth+1;
            s.push({num,curDepth+1});

            temp=num;
        }
        else{
            state[curNum].second=index;
            s.pop();

            temp=curNum;
        }

        if(index==_x)   x=temp;
        if(index==_y)   y=temp;
    }

    for(int i=1;i<=maxDepth;i++){
        for(int j=1;j<=n;j++){
            parent[j][i]=parent[parent[j][i-1]][i-1];
        }
    }

}

void initialize()
{  
    cin>>n;
    cin>>str;
    cin>>_x>>_y;
}

int lca(vector<int> &depth, vector<vector<int>> &parent){
    
    if(depth[x]>depth[y]){
        int temp=y;
        y=x;
        x=temp;
    }

    if(depth[y]!=depth[x]){
        for (int i = maxDepth; i >= 0; i--)
        {
            if (depth[y] - depth[x] >= (1 << i))
            {
                y = parent[y][i];
            }
        }
    }

    int result;
    if(x==y){
        result=x;
    }
    else{
        for(int i=maxDepth;i>=0;i--){
            if(parent[y][i]!=parent[x][i]){
                y=parent[y][i];
                x=parent[x][i];
            }
        }
        result=parent[x][0];
    }
    return result;
}

void solve()
{
    maxDepth=log2(n);
    vector<int> depth(MAX+1);
    vector<vector<int>> parent(MAX+1,vector<int>(maxDepth+1,0));

    makeTree(depth,parent);
    int result=lca(depth,parent);
    cout<<state[result].first<<" "<<state[result].second;
}

int main()
{
    initialize();
    solve();

    return 0;
}