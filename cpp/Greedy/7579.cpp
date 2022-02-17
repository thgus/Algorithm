/*
7579번: 앱
https://www.acmicpc.net/problem/7579
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<int> memory(1);
vector<int> cost(1);

int maxCost=0;
void initialize()
{
    cin>>n>>m;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        memory.push_back(temp);
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        cost.push_back(temp);
        maxCost+=temp;
    }
}

void solve()
{
    //dp에 n비용으로 가장 많이 확보할 수 있는 메모리를 저장
    // => 배낭 알고리즘 사용
    vector<int> dp(maxCost+1,0);
    for(int cur=1;cur<=n;cur++){
        int curMemory=memory[cur];
        int curCost=cost[cur];

        for(int i=maxCost;i>0;i--){
            if(i<curCost){
                break;
            }
            dp[i]=max(dp[i],dp[i-curCost]+curMemory);
        }
    }

    //i비용에서 문제에서 요구하는 m메모리 크기를 넘기면 출력
    for(int i=1;i<=maxCost;i++){
        if(dp[i]>=m){
            cout<<i;
            break;
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