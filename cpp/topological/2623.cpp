/*
2623번: 음악프로그램
https://www.acmicpc.net/problem/2623
*/

#include <iostream>
#include <vector>
#include <queue>

#define NMAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> prior(NMAX+1);
vector<int> d(NMAX+1,0);

void initialize()
{
    vector<vector<bool>> seq(NMAX+1,vector<bool>(NMAX+1,false));
    cin>>n>>m;

    string str;
    int temp;

    int a,b;
    for(int i=0;i<m;i++){
        cin>>temp;
        if(temp==0){
            continue;
        }

        cin>>a;
        for(int i=1;i<temp;i++){
            cin>>b;
            seq[a][b]=true;
            a=b;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(seq[i][j]){
                prior[i].push_back(j);
                d[j]++;
            }
        }
    }

}

void solve()
{
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            que.push(i);
        }
    }
    
    vector<int> result;
    while(!que.empty()){
        int cur=que.front();
        result.push_back(cur);
        que.pop();

        for(int i=0;i<prior[cur].size();i++){
            int next=prior[cur][i];
            if(--d[next]==0){
                que.push(next);
            }
        }
    }

    if(result.size()!=n){
        cout<<"0";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<result[i]<<"\n";
        }
    }

}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}