/*
15657번: N과 M(8)
https://www.acmicpc.net/problem/15657
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> seq;
vector<int> vec;

// p는 수열에 들어갈 수 있는 가장 작은 수의 인덱스.(비내림차순 위함)
// c는 지금까지 수열 길이
void bfs(int p, int c) {
	// 수열이 길이가 m이라는 조건을 만족하면 출력
	if (c == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	//다음 수열에 들어올 수 있는 수는 p보다(수열에서 가장 큰 수) 같거나 큰 경우만 가능
	for (int i = p; i <= n ; i++) {
		seq.push_back(vec[i]);
		//현재 수열에서 가장 큰 수 i.
		//	인덱스가 현재 수열에서 가장 큰 수부터 시작해 증가하는 연산밖에 하지 않고
		//	vec은 오름차순으로 정렬되어 있으므로 i가 seq에서 가장 큰 수이다.
		//수열에 하나를 넣었으므로 수열 길이 1 증가
		bfs(i, c + 1);
		//bfs를 빠져나왔다는 것은 수열의 길이가 m이라는 조건을 만족했다는 뜻이므로 넣은 숫자를 수열에서 pop해주기
		seq.pop_back();
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int temp;

	// 편의를 위해 배열의 인덱스 1부터 시작하기 위해 0에 더미값을 넣어줌
	vec.push_back(-1);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	//사전 순으로 증가하는 순서로 출력하기 위해 정렬
	sort(vec.begin(), vec.end());

	//bfs시작
	bfs(1, 0);

	return 0;
}