/*
11404번: 플로이드
https://www.acmicpc.net/problem/11404
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 987654321

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<int>> vec(101, vector<int>(101, MAX));

int main() {
	sync_off;
	int n, m;
	cin >> n;
	cin >> m;
	int a, b, c;

	for (int i = 1; i <= n; i++) {
		vec[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		//a->b도시로 가는 버스는 여러개일 수 있으니 가장 낮은 비용의 버스를 초기값으로 넣어둠		
		if (vec[a][b] > c) {
			vec[a][b] = c;
		}
	}

	// i 도시를 경유해서 가는 경우
	for (int i = 1; i <= n; i++) {
		//j도시에서 i도시로 갈 수 있는지 확인
		for (int j = 1; j <= n; j++) {
			if ((i == j) || (vec[j][i] == MAX)) {
				continue;
			}
			//i도시에서 갈 수 있는 도시
			for (int k = 1; k <= n; k++) {
				vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vec[i][j] == MAX) {
				cout << 0 << " ";
			}
			else {
				cout << vec[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}