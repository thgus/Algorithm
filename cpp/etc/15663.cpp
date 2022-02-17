/*
15663번: N과 M(9)
https://www.acmicpc.net/problem/15663

다른 풀이 방법
한 턴(n번째 줄)에서 사용했던 숫자는 사용하지 않음
 => 9 7 9 1이 있고 이 중 3개를 고른다면 1 7 9
	이 값이 1,10,100의 자리 수에 올 수 있는 경우의 수

	1. 각 자리에서 한번 사용했다면 그 이후는 사용하지 않아야 중복된 값이 나오지 않음.
			정렬을 한 이후에 사용한다면 마지막 값만 저장해 놔도 중복된 숫자인지 아닌지 알 수 있음.
	2. 하지만 만약 1의 자리에서 1을 고른다면 나머니 10, 100의 자리에서는 1을 고르면 안되기 때문에
		이러한 제약조건을 추가하기 위해 변수 배열을 추가

	1번(각 자리수에서 중본된 값을 사용하였는가)와 2번(다른 자리에서 사용한 수를 사용하였는가)를 따지면
		답을 구할 수 있음.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n, m;
//vector<vector<int>> result;
set<vector<int>> result;
vector<int> seq;
vector<int> vec;
bool isVisited[9] = { false };

void dfs(int p, int c) {
	if (c == m) {
		//이 순열이 나온적 없다면
		if (result.find(seq) == result.end()) {
			for (int i = 0; i < m; i++) {
				cout << seq[i] << " ";
			}
			result.insert(seq);
			cout << "\n";
		}
		//result.push_back(seq);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisited[i]) {
			continue;
		}
		seq.push_back(vec[i]);
		isVisited[i] = true;
		dfs(i + 1, c + 1);
		seq.pop_back();
		isVisited[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	dfs(0, 0);
	
	/*
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	return 0;
}