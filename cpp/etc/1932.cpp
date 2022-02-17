/*
1932번: 정수 삼각형
https://www.acmicpc.net/problem/1932

1차원 배열에 이전 값 저장
long long l;
l = 1;
for (int i = 2; i <= n; i++) {
	l = l + i;
=> n=500일 때 l=125250
}
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
	vector<int> vec(125251);
	vector<int> sum(125251);
	int n;
	cin >> n;

	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> vec[++count];
		}
	}

	sum[1] = vec[1];
	sum[2] = sum[1] + vec[2];
	sum[3] = sum[1] + vec[3];
	//cout << sum[1] << "\n";
	//cout << sum[2] << " " << sum[3] << "\n";

	count = 3;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			++count;
			if (j == 1) {
				sum[count] = sum[count - (i - 1)] + vec[count];
			}
			else if (j == i) {
				sum[count] = sum[count - i] + vec[count];
			}
			else {
				sum[count] = max(sum[count - (i - 1)], sum[count - i]) + vec[count];
			}
			//cout << sum[count] << " ";
		}
		//cout << "\n";
	}

	int max = 0;
	
	for (int i = count - n + 1; i <= count; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}
	cout << max;

	return 0;
}