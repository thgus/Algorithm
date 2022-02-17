/*
2805��: ���� �ڸ���
https://www.acmicpc.net/problem/2805

�� �̺�Ž��;;
���������� ��� �������� �ð��ʰ� ���ڱ���;;

�� �ڷ���
unsinged int�� ������ �۱���;;; long long�� �е������� ������ ���� ������;;
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000000

using namespace std;

int main() {
	sync_off;
	int m, n;
	cin >> n >> m;

	vector<int> vec;
	int temp;

	int begin = 0;
	int end = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > end) {
			end = temp;
		}
		vec.push_back(temp);
	}
	
	int mid;

	int point = -1;

	long long cut;
	while (begin <= end) {
		mid = (begin + end) / 2;
		cut = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] - mid > 0) {
				cut += vec[i] - mid;
			}
		}
		if (cut >= m) {
			if ( mid > point ) {
				point = mid;
			}
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << point;
	
	return 0;
}