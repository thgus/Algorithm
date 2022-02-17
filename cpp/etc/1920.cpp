#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool serch(vector<int> &a, int num) {
	int begin = 0;
	int end = a.size() - 1;
	int middle;
	while (begin <= end) {
		middle = (begin + end) / 2;
		if (a[middle] == num)
			return true;
		else if (a[middle] < num)
			begin = middle + 1;
		else
			end = middle - 1;
		//cout << begin << " " << middle << " " << end << endl;
	}
	return false;
}

int main() {
	int n, m, temp;
	vector<int> a;
	vector<int> out;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (serch(a, temp))
			out.push_back(1);
		else
			out.push_back(0);
	}

	for (int i = 0; i < m; i++)
		cout << out[i] << "\n";

	return 0;
}