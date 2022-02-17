/*
9095번: 1, 2, 3더하기
https://www.acmicpc.net/problem/9095
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> vec(12, 0);
	
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;

	for (int i = 4; i <= 11; i++) {
		vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
	}

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << vec[n]<<"\n";
	}

	return 0;
}