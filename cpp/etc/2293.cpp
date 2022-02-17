/*
[BOJ]2293번: 동전1
https://www.acmicpc.net/problem/2293
*/

#include<iostream>
#include<vector>


using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coin(10001, 0);
	vector<int> mem(10001, 0);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	//0인 경우는 동전 하나만 사용한다는 뜻이기 때문에 경우의 수 1
	mem[0] = 1;

	//1,2,5 동전이 있으면 1만 사용 + 2추가 + 5추가
	for (int i = 1; i <= n; i++) {
		//추가하는 동전 크기부터 시작해서 원하는 액수까지
		for (int j = coin[i]; j <= k; j++) {
			//경우의수 더하기 
			//ex) 동전 크기 5, 원하는 액수 7 => 5=5+0, 6=5+1, 7=5+2
			// 7 = 5의 경우의수 + 2의 경우의수
			mem[j] += mem[j - coin[i]];
		}
	}

	cout << mem[k];

	return 0;
}