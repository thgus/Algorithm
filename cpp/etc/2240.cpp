/*
2240번: 자두나무
https://www.acmicpc.net/problem/2240

다이나믹 프로그래밍

필요한 요소 : 내가 서 있는 곳(위치), 자두가 떨어지는 시간, 이동횟수 => 총 자두를 몇개 먹었는가
	plum[위치][시간][이동횟수]= 먹은 자두 갯수
1. 자두가 1에서 떨어질 때
	내가 1에 서있음. => 움직임, 안움직임 (+1)
	내가 2에 서있음. => 움직임 (+1), 안움직임
2. 자두가 2에서 떨어질 때
	내가 1에 서있음. => 움직임 (+1), 안움직임 
	내가 2에 서있음. => 움직임, 안움직임 (+1)

*/
#include<iostream>
#include<algorithm> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int plum[3][1001][31] = { 0 };
	int treeList[1001] = { 0 };

	int t, w;	//t:시간, w: 움직인 횟수
	cin >> t;
	cin >> w;

	for (int i = 1; i <= t; i++) {
		cin >> treeList[i];
	}

	
	//초기 세팅
	if (treeList[1] == 1) {
		plum[1][1][0] = 1;
	}
	else if(treeList[1] == 2) {
		plum[2][1][1] = 1;	//1<=w<=30이므로 w-1은 항상 성립
	}

	for (int i = 2; i <= t; i++) {	// 시간
		for (int j = 0; j <= w; j++) {	//움직인 횟수
			if (treeList[i] == 1) {
				if (j == 0) {	// 지금까지 움직이지 않았다면 그 자리에서 받은 자두 갯수만 셈
					plum[1][i][j] = plum[1][i - 1][j] + 1;
					plum[2][i][j] = plum[2][i - 1][j];
				}
				else if(j > 0)
				{
					plum[1][i][j] = max(plum[1][i - 1][j] + 1, plum[2][i - 1][j - 1] + 1);
					plum[2][i][j] = max(plum[1][i - 1][j - 1], plum[2][i - 1][j]);
				}
			}
			else if (treeList[i] == 2) {
				if (j == 0) {
					plum[1][i][j] = plum[1][i - 1][j];
					plum[2][i][j] = plum[2][i - 1][j] + 1;
				}
				else if (j > 0) {
					plum[1][i][j] = max(plum[1][i - 1][j], plum[2][i - 1][j - 1]);
					plum[2][i][j] = max(plum[1][i - 1][j - 1] + 1, plum[2][i - 1][j] + 1);
				}
			}
			//cout << "plum[1][" << i << "][" << j << "]=" << plum[1][i][j] << "\n";
			//cout << "plum[2][" << i << "][" << j << "]=" << plum[2][i][j] << "\n";
		}
	}

	int m = -1;
	for (int i = 0; i <= w; i++) {
		m = max(m, max(plum[1][t][i], plum[2][t][i]));
	}
	cout << m;

	return 0;
}