/*
20303번: 할로윈의 양아치
https://www.acmicpc.net/problem/20303
*/

#include <iostream>
#include <vector>
#include <queue>

#define FMAX 30000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m,k;
vector<int> candy;
vector<vector<int>> frend(FMAX+1);

void initialize()
{
    cin>>n>>m>>k;
    int temp;
    candy.push_back(0);
    for(int i=0;i<n;i++){
        cin>>temp;
        candy.push_back(temp);
    }
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        frend[a].push_back(b);
        frend[b].push_back(a);
    }
}

pair<int,int> bfs(vector<bool> &isVisited, int s){
    /*
     first : 인덱스. 친구 번호
     second.first : 모은 캔디 갯수
     second.second : 친구 수
    */
    queue<int> que;
    que.push(s);
    isVisited[s]=true;
    
    int collectCandy=0;
    int collectFrend=0;

    while(!que.empty()){
        int cur=que.front();
        collectCandy+=candy[cur];
        collectFrend++;
        que.pop();

        for(int i=0;i<frend[cur].size();i++){
            int next=frend[cur][i];
            if(!isVisited[next]){
                isVisited[next]=true;
                que.push(next);
            }
        }
    }

    return make_pair(collectCandy,collectFrend);
}

void solve()
{
    vector<bool> isVisited(n+1,false);

    //first: 캔디 갯수, second: 아이들 수
    vector<pair<int,int>> collect;
    for(int i=1;i<=n;i++){
        if(!isVisited[i]){
            collect.push_back(bfs(isVisited,i));
        }
    }

    vector<int> dp(k+1,0);
    for(int cur=0;cur<collect.size();cur++){
        int curCandy=collect[cur].first;
        int curFrend=collect[cur].second;

        for(int i=k;i>0;i--){
            if(i<curFrend){
                break;
            }
            dp[i]=max(dp[i],dp[i-curFrend]+curCandy);
        }
    }
    cout<<dp[k-1];
}

int main()
{
    initialize();
    solve();

    return 0;
}