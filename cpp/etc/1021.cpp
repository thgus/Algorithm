#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main() {
	list<int> lis;
	vector<int> vec;

	int n, m;

	cin >> n;
	cin >> m;

	int temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		lis.push_back(i);
	}

	list<int>::iterator it;
	int count = 0;
	int t;
	bool flag;

	for (int i = 0; i < m; i++) {
		it = lis.begin();
		t = 0;
		flag = true;

		//원소 위치 찾기
		while (*it != vec[i]) {
			it++;
			t++;
		}

		//원소가 뒤쪽에 가깝게 위치해 있는 경우
		if (t > lis.size() - t - 1) {
			t = lis.size() - t;
			flag = false;
		}

		count += t;

		//원소 이동
		if (flag) {
			for (int j = 0; j < t; j++) {
				lis.push_back(lis.front());
				lis.pop_front();
			}
		}
		else {
			for (int j = 0; j < t; j++) {
				lis.push_front(lis.back());
				lis.pop_back();
			}
		}

		//원소를 뽑아냄
		lis.pop_front();
	}

	cout << count;

	return 0;
}