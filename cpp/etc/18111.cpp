/*
18111번: 마인크래프트
https://www.acmicpc.net/problem/18111

다른사람들 보니까 시간 엄청 줄은것도 있던데 한번 알아보자
이분탐색으로 하는건가?
*/

#include<iostream>
#include<vector>
#define MAX 256
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> vec(500, vector<int>(500));
	int maxh = 0;
	int minh = MAX;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (maxh < temp) {
				maxh = temp;
			}
			if (minh > temp) {
				minh = temp;
			}
			vec[i][j] = temp;
		}
	}

	int minTime = 256 * 2 * 500 * 500;
	int height = 0;

	int collectSoi;
	int needSoi;

	int time;
	for (int i = maxh; i >= minh; i--) {
		time = 0;
		collectSoi = 0;
		needSoi = 0;
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (vec[j][k] > i) {
					int digSoi = vec[j][k] - i;
					time += (digSoi * 2);
					collectSoi += digSoi;
				}
				else if (vec[j][k] < i) {
					int stackSoi = i - vec[j][k];
					time += stackSoi;
					needSoi += stackSoi;
				}
			}
		}

		if (needSoi <= collectSoi + b && minTime > time) {
			height = i;
			minTime = time;
		}
	}
	cout << minTime << " " << height;

	return 0;
}