/*
12865번: 평범한 배낭
https://www.acmicpc.net/problem/12865

https://gsmesie692.tistory.com/113
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//가치 저장
//vector<vector<int>> vec(100001, vector<int>(101, 0));
vector<int> vec(100001);

int main() {
	sync_off;
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> object(101);
	int w, v;

	//object.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		cin >> w >> v;
		object[i] = make_pair( w,v );
	}
	
	int rw;	//남은 배낭 무게
	//j 물건, i 무게
	/*
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i >= object[j].first) {
				rw = i - object[j].first;
				vec[i][j] = max(object[j].second + vec[rw][j - 1], vec[i][j - 1]);
			}
			else {
				vec[i][j] = vec[i][j - 1];
			}
		}
		cout << "\n";
	}
	*/

	//1차원 배열로 풀기 
	//2차원배열에서 값이 없으면 위의 값을 내려받는데 이의 과정을 생락할 수 있게 함.
	for (int j = 1; j <= n; j++) {
		//배낭의 남은 무게만큼 이전 배열에서 값을 가져오는데
		//이전 배열이 먼저 갱신되지 않도록 무게는 작아지도록 반복
		for (int i = k; i > 0; i--) {
			if (i >= object[j].first) {
				rw = i - object[j].first;
				vec[i] = max(vec[i], object[j].second + vec[rw]);
			}
		}
	}

	cout << vec[k];

	return 0;
}