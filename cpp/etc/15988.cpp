//https://www.acmicpc.net/problem/15988

#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<long long> r(1000001,0);
	int num;

	r[1] = 1;
	r[2] = 2;
	r[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		r[i] = (r[i - 1] + r[i - 2] + r[i - 3]) % 1000000009;
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> num;
		cout << r[num] << "\n";
	}

	return 0;
}