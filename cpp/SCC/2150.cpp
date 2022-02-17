/*
2150번: Strongly Connected Component
https://www.acmicpc.net/problem/2150
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>

#define MAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int v,e;
vector<int> f_route[MAX+5];
vector<int> r_route[MAX+5];

void initialize()
{
    cin>>v>>e;

    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        f_route[a].push_back(b);
        r_route[b].push_back(a);
    }
}

bool visited[MAX+5];
stack<int> seq;

int idx;
vector<vector<int>> result(MAX);

void f_dfs(int num)
{
    for(int next:f_route[num])
    {
        if(visited[next])   continue;
        visited[next]=true;
        f_dfs(next);
        seq.push(next);
    }
}

void r_dfs(int num)
{
    for(int next:r_route[num])
    {
        if(visited[next])   continue;
        visited[next]=true;
        result[idx].push_back(next);

        r_dfs(next);
    }
}

void solve()
{
    memset(visited,false,sizeof(bool)*(MAX+5));
    for(int i=1;i<=v;i++)
    {
        if(visited[i])  continue;
        visited[i]=true;
        f_dfs(i);
        seq.push(i);
    }

    memset(visited,false,sizeof(bool)*(MAX+5));

    idx=0;
    while(!seq.empty())
    {
        int cur=seq.top();
        seq.pop();

        if(visited[cur])    continue;
        visited[cur]=true;

        result[idx].push_back(cur);

        r_dfs(cur);

        sort(result[idx].begin(),result[idx].end());

        idx++;
    }

    sort(result.begin(),result.begin()+idx);

    cout<<idx<<"\n";
    for(int i=0;i<idx;i++)
    {
        for(int cur:result[i])
        {
            cout<<cur<<" ";
        }
        cout<<"-1\n";
    }
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}