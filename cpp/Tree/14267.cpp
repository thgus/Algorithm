/*
14267번: 회사 문화 1
https://www.acmicpc.net/problem/14267
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
    sync_off;
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> tree(n+1);
    int p;
    int root;
    for(int i=1;i<=n;i++){
        cin>>p;
        if(p==-1){
           root=i;
           continue;
        }
        tree[p].push_back(i);
    }

    int i,w;
    vector<int> score(n+1,0);
    while(m--){
        cin>>i>>w;
        score[i]+=w;
    }

    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        for(int next:tree[cur]){
            que.push(next);
            score[next]+=score[cur];
        }
    }

    for(int cur=1;cur<=n;cur++){
        cout<<score[cur]<<" ";
    }

    return 0;
}