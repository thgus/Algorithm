/*
15666번: N과 M(12)
https://www.acmicpc.net/problem/15666

 각 자리에서 한번 사용했다면 그 이후는 사용하지 않아야 중복된 값이 나오지 않음.
	정렬을 한 이후에 사용한다면 마지막 값만 저장해 놔도 중복된 숫자인지 아닌지 알 수 있음.
		=> lastValue
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 8
#define MAXVALUE 10000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//vector<int> _vec : 수열에 들어갈 수 있는 숫자들이 있는 배열
//int _seq[] : vec에서 고른 숫자가 저장되어 있는 수열
//int _p : 비내림차순 조건을 만족하기 위해 순열에서 가장 큰 수를 저장
//int _c : 현재 몇개의 수를 골랐는지 확인. ( _c <= _m )
//int _n : 선택할 수 있는 자연수의 개수. vec의 사이즈
//int _m : 자연수 _n개 중 고를 수 있는 갯수.
void dfs(vector<int> vec, int seq[], int _p, int _c, int _n, int _m) {
	if (_c == _m) {
		for (int i = 0; i < _m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	int lastValue = -1;
	for (int i = _p; i < _n; i++) {
		if (lastValue == vec[i]) {
			continue;
		}
		lastValue = vec[i];
		seq[_c] = vec[i];
		dfs(vec, seq, i, _c + 1, _n, _m);
	}
}

int main() {
	sync_off

	int n, m;
	cin >> n >> m;
	vector<int> vec(MAX, MAXVALUE);
	int seq[MAX];
	
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	
	dfs(vec, seq, 0, 0, n, m);

	return 0;
}