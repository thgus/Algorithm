//https://www.acmicpc.net/problem/1965

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// dp
int main() {
	int n;
	vector<int> box(1000, 0);
	vector<int> mem(1000, 1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	int maxB;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && mem[i]<=mem[j]) {
				mem[i] = mem[j] + 1;
			}
		}
	}

	//for (int i = 0; i < n; i++)
	//	cout << mem[i] << " ";
	//cout << "\n";

	sort(mem.begin(), mem.end());

	cout << mem.back();
	

	return 0;
}