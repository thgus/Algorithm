/*
2166번: 다각형의 면적
https://www.acmicpc.net/problem/2166

https://code0xff.tistory.com/40
*/

#include<iostream>
#include<vector>
#include<cmath>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	//sync_off;
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	double result = 0;
	long long temp = 0;
	for (int i = 1; i < n - 1; i++) {
		temp += ((long long)vec[0].first * (long long)vec[i].second) + ((long long)vec[i].first * (long long)vec[i + 1].second) + ((long long)vec[i + 1].first * (long long)vec[0].second);
		temp -= ((long long)vec[0].second * (long long)vec[i].first) + ((long long)vec[i].second * (long long)vec[i + 1].first) + ((long long)vec[i + 1].second * (long long)vec[0].first);
	}
	result = (double)temp / 2;

	if (result >= 0) {
		printf("%.1f", result);
	}
	else {
		printf("%.1f", -result);
	}

	return 0;
}