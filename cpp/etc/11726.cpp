/*
11726번: 2xn 타일링
https://www.acmicpc.net/problem/11279

d[n] = d[n-2] + d[n-1]
d[n-2] : 오른쪽에 누워진 직사각형 2개 추가
		세워진 직사각형 경우의 수는 d[n-1]에서 채워짐
d[n-1] : 오른쪽에 세워진 직사각형 1개 추가

결과는 d[n]을 10,007로 나눈 나머지 출력
	하지만 계산을 하다보면 변수의 범위를 넘어가기 때문에
		계산을 할 때 마다 10,007으로 나눠준다 => 이렇게 해도 결과 같음
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<long long> vec(1001, 0);
	int n;
	cin >> n;
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	for (int i = 3; i <= n; i++) {
		vec[i] = (vec[i - 1] + vec[i - 2]) % 10007;
	}
	cout << vec[n];
	return 0;
}