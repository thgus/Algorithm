/*
1516번: 게임 개발
https://www.acmicpc.net/problem/1516
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 500
#define MAXCOST 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
//first: time, second: 진입 차수
vector<pair<int,int>> building(MAX+1);
//먼저 지어져야 하는 건물 -> 이후에 지어질 수 있는 건물
vector<vector<int>> rule(MAX+1);

void initialize()
{
    cin>>n;

    int prior; 
    int time, degree;
    for(int i=1;i<=n;i++){
        cin>>time;
        degree=0;
        while(1){
            cin>>prior;
            if(prior==-1){
                break;
            }
            degree++;
            rule[prior].push_back(i);
        }
        building[i].first=time;
        building[i].second=degree;
    }
}

void solve()
{
    vector<int> spendTime(n+1,0);
    queue<int> que;

    for(int i=1;i<=n;i++){
        if(building[i].second==0){
            que.push(i);
            spendTime[i]=0;
        }
    }

    while(!que.empty()){
        int cur=que.front();
        que.pop();
        spendTime[cur]+=building[cur].first;

        for(int i=0;i<rule[cur].size();i++){
            int index=rule[cur][i];
            spendTime[index]=max(spendTime[index],spendTime[cur]);
            if(--building[index].second==0){
                que.push(index);
            }
        }
    }

    int result=0;
    for(int i=1;i<=n;i++){
        cout<<spendTime[i]<<"\n";
    }
    
}

int main()
{
    initialize();
    solve();

    return 0;
}