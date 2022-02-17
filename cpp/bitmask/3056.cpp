/*
3056번: 007
https://www.acmicpc.net/problem/3056
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<double>> vec;

void initialize()
{
	cin >> n;
	vec.resize(n, vector<double>(n));

	double d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];		}
	}
}

struct Node {
	int jimi_num;
	int jimi_bit;
	int mission_bit;
	double percent;

	bool operator<(const Node n) const {
		return n.percent < percent;
	}
};

void solve()
{
	cout.precision(6);
	cout << fixed;

	vector<double> dp(1 << n, 0);
	dp[0] = 1;

	//첫번째 지미본드부터 n번째 지미본드까지 차례대로 미션을 할당해주기
	//첫번째 지미본드부터 시작한다면 1,2,3번 미션을 차례대로 배부해 준다고 치고 bit를 (001), (010), (100)로 표현할 수 있음.
	//두번째 지미본드는 첫번째 지미본드가 고르지 않은 미션을 고르면 되는데 
	//만약 첫번째 지미본드가 1번을 골랐다면(001) 두번째 지미본드는 2번, 3번을 고를 수 있음. 이를 비트로 표현하면 2번을 고름 (011), (101)
	//	 => 1의 갯수를 지미본드의 번호로 사용할 수 있음.
	for (int i = 0; i < (1 << n)-1; i++) {
		int cur_jimi = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))	cur_jimi++;
		}

		for (int j = 0; j < n; j++) {
			if (~i & (1 << j)) {
				dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * (vec[cur_jimi][j] / 100));
			}
		}
	}

	cout << dp[(1 << n) - 1] * 100;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}