/*
12852번: 1로 만들기 2
https://www.acmicpc.net/problem/12852
*/

#include<iostream>
#include<vector>

using namespace std;

void dp(int n, vector<int> &dt, vector<int> &vec) {
	
	vec[0] = 0; dt[0] = 0;
	vec[1] = 0; dt[1] = 0;
	vec[2] = 1; dt[2] = 2;
	vec[3] = 1; dt[3] = 0;

	for (int i = 4; i <= n  ; i++) {
		//0:3나누기 1:2나누기 2:1빼기
		vector<int>temp(3, 10000001);
		
		if (i % 3 == 0) {
			temp[0] = vec[i / 3] + 1;
		}
		
		if (i % 2 == 0) {
			temp[1] = vec[i / 2] + 1;
		}
		temp[2] = vec[i - 1] + 1;

		if (temp[0] < temp[1]) {
			if (temp[0] < temp[2]) {
				//temp[0]의 값이 제일 작음
				dt[i] = 0;
				vec[i] = temp[0];
			}
			else {
				//temp[2]의 값이 제일 작음
				dt[i] = 2;
				vec[i] = temp[2];
			}
		}
		else {
			if (temp[1] < temp[2]) {
				//temp[1]의 값이 제일 작음
				dt[i] = 1;
				vec[i] = temp[1];
			} 
			else {
				//temp[2]의 값이 제일 작음
				dt[i] = 2;
				vec[i] = temp[2];
			}
		}

	}

}

int main() {
	int n;
	cin >> n;

	vector<int> dt(1000001, 0);
	vector<int> vec(1000001, 0);

	dp(n, dt, vec);

	cout << vec[n] << "\n";
	int temp = n;

	cout << n << " ";
	while (temp > 1) {
		if (dt[temp] == 0) {
			temp = temp / 3;
		}
		else if (dt[temp] == 1) {
			temp = temp / 2;
		}
		else if (dt[temp] == 2) {
			temp = temp - 1;
		}
		cout << temp << " ";

	}


	return 0;
}