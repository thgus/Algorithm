/*
17471번:게리맨더링
https://www.acmicpc.net/problem/17471
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> population;
vector<vector<int>> graph;

void initialize()
{
    cin>>n;
    population.resize(n);
    graph.resize(n);
    for(int i=0;i<n;i++){
        cin>>population[i];
    }

    int next;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>next;
            graph[i].push_back(next-1);
        }
    }
}

int dfs(vector<bool> &vec, bool flag){
    int people_size=0;
    int start;
    for(int i=0;i<n;i++){
        if(vec[i]==flag){
            people_size++;
            start=i;
        }
    }
    if(people_size==0)  return -1;

    bool visited[n];
    memset(visited, false,sizeof(bool)*n);

    int people_num=0;
    int sum=0;

    queue<int> que;
    que.push(start);
    visited[start]=true;

    while(!que.empty()){
        int cur=que.front();
        que.pop();

        people_num++;
        sum+=population[cur];

        for(int next:graph[cur]){
            if(vec[next]!=flag)  continue;
            if(visited[next])  continue;
            visited[next]=true;
            que.push(next);
        }
    }

    if(people_num!=people_size){
        return -1;
    }
    else{
        return sum;
    }
}

void print_vec(vector<bool> vec){
    for(int i=0;i<n;i++){
        cout<<vec[i];
    }
    cout<<"\n";
}

void make_seq(vector<bool> &vec, int &ret, int cur){
    if(cur==n){
        int sum1=dfs(vec,true);
        int sum2=dfs(vec,false);
        
        //cout<<sum1<<" "<<sum2<<"\n";
        //print_vec(vec);
        
        if(sum1!=-1&&sum2!=-1){
            if(ret==-1||ret>abs(sum1-sum2)){
                ret=abs(sum1-sum2);
            }
        }
        return;
    }

    vec[cur]=true;
    make_seq(vec,ret,cur+1);
    vec[cur]=false;
    make_seq(vec,ret,cur+1);
}

void solve()
{
    vector<bool> vec(n,false);

    int min_sub=-1;
    make_seq(vec,min_sub,0);
    cout<<min_sub;

    //dfs(vec,false);
}

int main()
{
    sync_off;
 
    initialize();
    solve();

    return 0;
}