/*
1007번: 벡터 매칭
https://www.acmicpc.net/problem/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

double result;

void solve(vector<pair<int, int>>& vec, int index, int num, vector<bool> &isStart)
{
	if (num == vec.size() / 2) {
		long long x = 0;
		long long y = 0;
		for (int i = 0; i < isStart.size(); i++) {
			if (!isStart[i]) {
				x += vec[i].first;
				y += vec[i].second;
			}
			else {
				x -= vec[i].first;
				y -= vec[i].second;
			}
		}
		result = min(result, sqrt((x * x) + (y * y)));
		return;
	}

	for (int i = index + 1; i < isStart.size(); i++) {
		isStart[i] = true;
		solve(vec, i, num + 1, isStart);
		isStart[i] = false;
    }

}

void initialize()
{
	int t;
	scanf("%d", &t);

	int n;
	while (t--) {
        result=9223372036854775807;
		scanf("%d", &n);
		vector<pair<int, int>> vec(n);
		int a, b;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			scanf("%d", &b);
			vec[i]={ a,b };
		}

		vector<bool> isStart(n, false);
		solve(vec, -1, 0, isStart);
		printf("%.7f\n",result);
	}
}

int main()
{
	//sync_off;
	initialize();

	return 0;
}