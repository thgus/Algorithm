/*
2263번: 트리의 순회
https://www.acmicpc.net/problem/2263

나중에 한번 반복문으로 풀어보자
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n;
vector<int> in;
vector<int> post;

void solution(int is, int ie, int ps, int pe) {
	if (is == ie) {
		cout << in[is] << " ";
		return;
	}

	int i;
	for (i = is; in[i] != post[pe]; i++);
	cout << in[i] << " ";
	if (i - 1 >= 0 && is < i) {
		//cout << is << i - 1 << ps << i - 1 - (ie - pe) << "!\n";
		solution(is, i - 1, ps, i - 1 - (ie - pe));
	}
	if (i + 1 <= ie) {
		//cout << i + 1 << ie << i-(ie-pe) << pe - 1 << "?\n";
		solution(i + 1, ie, i - (ie - pe), pe - 1);
	}
}

void initializer() {
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		in.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		post.push_back(temp);
	}
}

int main() {
	sync_off;
	initializer();
	solution(0, n - 1, 0, n - 1);

	return 0;
}