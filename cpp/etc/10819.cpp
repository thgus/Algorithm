#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int count = 0;
	vector<int> a;
	int arr[2];
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	
	sort(a.begin(), a.end());

	arr[0] = a.back();
	arr[1] = a.front();

	count += abs(arr[1] - arr[0]);

	for (int i = 1; i < n / 2; i++) {
		count += abs(a[i] - arr[0]) + abs(arr[1] - a[n - i - 1]);
		//cout << arr[1] << " " << arr[0] << endl;
		arr[0] = a[i];
		arr[1] = a[n - i - 1];
		reverse(a.begin(), a.end());
	}

	if (n % 2 != 0) {
		if (abs(a[n / 2 ] - arr[0]) > abs(a[n / 2] - arr[1]))
			count += abs(a[n / 2] - arr[0]);
		else
			count += abs(a[n / 2] - arr[1]);
	}

	cout << count;
	

	return 0;
}