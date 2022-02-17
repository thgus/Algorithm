/*
2098번: 외판원 순회
https://www.acmicpc.net/problem/2098

https://www.acmicpc.net/board/view/18838
1. 출발 지점으로 다시 돌아올 수 있다.
:0 -> 1 -> 0  -> 2 -> 3 와 같이 다시 돌아올 수 있다고 생각합니다.  기존에 0(0001) -> 1(0011) -> 2(0111) -> 3(1111) 이 최소 비용 거리라고 가정한다면,
결국 0(0000) -> 1(0010) -> 0(0011) -> 2(0111) -> 3(1111) (차선의 경로라고 가정) 으로밖에 이동할 수 없을 것입니다.
2. 기저 조건에서 돌아오는 조건이 없다.
: 모든 지점을 방문했지만, 다시 돌아오는 길이 없다면 문제가 될 것입니다.

https://withhamit.tistory.com/246 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 16
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map(MAX, vector<int>(MAX));

void initialize()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

vector<vector<int>> dp(((1 << MAX)), vector<int>(MAX,1e9));
int dfs(int cur, int visited) {
	if(visited==(1<<n)-1){
		if(map[cur][0]>0){
			return map[cur][0];
		}
		else{
			return 1e9;
		}
	}

	if(dp[visited][cur]!=1e9){
		return dp[visited][cur];
	}

	for(int next=0;next<n;next++){
		if(cur==next||map[cur][next]==0||(visited&(1<<next))>0){
			continue;
		}
		int cost=dfs(next,(visited|(1<<next)))+map[cur][next];
		dp[visited][cur]=min(dp[visited][cur],cost);
	}

	return dp[visited][cur];
}

void solve()
{
	cout<<dfs(0,1);	
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}