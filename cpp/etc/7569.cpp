/*
7569번: 토마토
https://www.acmicpc.net/problem/7569

토마토들이 모두 익는지 그 최소 일수
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토
*/

#include<iostream>
#include<tuple>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H
	int m, n, h; //2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100
	//int arr[101][101][101];
	vector<vector<vector<int>>> vec(101,vector<vector<int>>(101,vector<int>(101)));

	
	cin >> m;
	cin >> n;
	cin >> h;
	
	int temp;
	//정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				//cin >> arr[i][j][k];
				cin >> vec[k][j][i];
			}
		}
	}
	
	queue<tuple<int,int,int,int>> que;
	vector<vector<vector<bool>>> visit(101, vector<vector<bool>>(101, vector<bool>(101, false)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {	
				if (vec[k][j][i] == 1) {
					que.push({ k,j,i,0 });
					//cout << k << " " << j << " " << i << "\n";
				}
			}
		}
	}
	
	int day = 0;
	tuple<int, int, int, int> t;
	while(!que.empty()){
		t = que.front();
		que.pop();

		//방문했다면 재방문 X. 
		//어차피 가장 처음에 방문했을 때가 day도 작을테니
		if (visit[get<0>(t)][get<1>(t)][get<2>(t)]) {
			continue;
		}

		visit[get<0>(t)][get<1>(t)][get<2>(t)] = true;
		//토마토 익음
		vec[get<0>(t)][get<1>(t)][get<2>(t)] = 1;

		//que는 fifo이므로 que의 day는 순차적으로 커지므로 
		// 가장 마지막 que에서 나온게 마지막 day
		day = get<3>(t);

		if (get<2>(t) > 0) {
			if (vec[get<0>(t)][get<1>(t)][get<2>(t) - 1] == 0) {
				//cout << "위 ";
				que.push({ get<0>(t),get<1>(t),get<2>(t) - 1,get<3>(t) + 1 });
			}
		}
		if (get<2>(t) < h - 1) {
			if (vec[get<0>(t)][get<1>(t)][get<2>(t) + 1] == 0) {
				//cout << "아래 ";
				que.push({ get<0>(t),get<1>(t),get<2>(t) + 1,get<3>(t) + 1 });
			}
		}
		if (get<0>(t) > 0) {
			if (vec[get<0>(t) - 1][get<1>(t)][get<2>(t)] == 0) {
				//cout << "왼 ";
				que.push({ get<0>(t) - 1,get<1>(t),get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<0>(t) < m - 1) {
			if (vec[get<0>(t) + 1][get<1>(t)][get<2>(t)] == 0) {
				//cout << "오 ";
				que.push({ get<0>(t) + 1,get<1>(t) ,get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<1>(t) > 0) {
			if (vec[get<0>(t)][get<1>(t) - 1][get<2>(t)] == 0) {
				//cout << "뒤 ";
				que.push({ get<0>(t),get<1>(t) - 1,get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<1>(t) < n - 1) {
			if (vec[get<0>(t)][get<1>(t) + 1][get<2>(t)] == 0) {
				//cout << "앞 ";
				que.push({ get<0>(t),get<1>(t) + 1,get<2>(t),get<3>(t) + 1 });
			}
		}
		//cout << "\n";
	}
	
	// 익지 않은 토마토가 있다면 flag=false
	bool flag = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (vec[k][j][i] == 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	if (flag) {
		cout << "-1";
	}
	else {
		cout << day;
	}

	return 0;
}