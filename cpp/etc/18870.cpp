/*
18870번: 좌표 압축
https://www.acmicpc.net/problem/18870
unique => 중복 원소를 뒤로 이동
	연속된 중복 원소에 해당되므로 정렬을 해줘야 함.
erase=> 중복 제거

이 문제는 서로 다른 좌표의 개수와 같아야 해서 접근하기 쉬운데
만약 같은 좌표의 개수도 같아야 하면 어떻게 접근해야 할지 의문
 ex) 0 5 7 7 9 면 0 1 2 2 3이 아니라 0 1 2 2 4 이런식으로 나와야 한다면?

 find(vec.begin(), vec.end(), f) - vec.begin()
 distance를 사용하는 방법도 있음.
	=> 시간초과
 정렬을 했으니 탐색 알고리즘을 좀 사용해야 할 것 같음.
 이진탐색 사용

 set도 생각했는데 set은 배열 순서가 없어서 숫자가 얼마나 큰 수인지 알 수 없으니 사용 안함.

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long> input;
	vector<long> vec;

	int n;
	cin >> n;

	long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
		input.push_back(x);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < input.size(); i++) {
		long v = input[i];
		cout << lower_bound(vec.begin(), vec.end(), v) - vec.begin() << " ";
	}
	

	return 0;
}