/*
9663번: N-Queen
https://www.acmicpc.net/problem/9663

백트래킹의 기억을 더듬어가며..
dfs...
내가한건 시간초과가 나네;; 
찾아보니 2차원배열을 매번 매개변수로 전달해줘서 시간이 오래걸리는거 같다고 한다.
https://www.acmicpc.net/board/view/45970

2차원 배열 사용 X
2차원배열을 사용하면 놓을 수 없는 위치를 모두 처리해야함.
세로 대각선이라는 규칙이 있으니 이들을 공통으로 묶어서 처리하자.
하나의 열에는 하나의 queen밖에 놓지 못하니 세로 담당 배열 하나
하나의 대각선에도 하나의 queen밖에 놓지 못하니 대각성 담당 배열 하나씩(오,왼)
이런식으로 하면 한번의 연산으로 놓을 수 없는 곳을 파악 가능.
https://rile1036.tistory.com/65

이 퀸이 있는 위치를 저장해서 비교하는 방법도 있음.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 15

using namespace std;

vector<bool> col(MAX, true);
//대각선 경우의 수는 2*n-1개
vector<bool> l_d(MAX * 2, true);
vector<bool> r_d(MAX * 2, true);
int n;

int result;

void dfs(int _y) {	
	if (_y == n) {
		result++;
		return;
	}

	int sum = 0;
	for (int x = 0; x < n; x++) {
		if (!(col[x]) || !(l_d[n - _y + x - 1]) || !(r_d[_y + x])) {
			continue;		
		}
		//cout << x << " " << _y << " " << n - _y + x - 1 << " " << _y + x << "\n";
		col[x] = l_d[n - _y + x - 1] = r_d[_y + x] = false;
		dfs(_y + 1);
		col[x] = l_d[n - _y + x - 1] = r_d[_y + x] = true;
	}
	//cout << "\n";
}

int main() {
	sync_off;
	cin >> n;
	result = 0;

	dfs(0);
	cout << result;
	
	return 0;
}