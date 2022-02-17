#include<iostream>
#include<vector>

using namespace std;

//dp
int main() {
	int n;

	vector<int> box(2001, 0);
	vector<int> jump(2001, 1001);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	jump[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= i + box[i]; j++) {
			if (jump[j] > jump[i] + 1) { //더 작은 횟수로 변경
				jump[j] = jump[i] + 1;
			}
			cout << i << " " << jump[j] << "\n";
		}
	}

	if (jump[n - 1] == 1001)	//도착하지 못함
		cout << "-1";
	else
		cout << jump[n - 1];	//도착

	return 0;
}