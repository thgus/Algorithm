/*
1978번: 소수 찾기
https://www.acmicpc.net/problem/1978

에라토스테네스의 체
*/

#include<iostream>
#include<vector>
#include<cmath>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000

using namespace std;

int main() {
	sync_off;
	vector<bool> vec(MAX + 1, false);
	vec[1] = true;
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (vec[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			vec[j] = true;
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (!vec[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}