/*
1461번: 도서관
https://www.acmicpc.net/problem/1461
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<int> book1;
vector<int> book2;

void initialize()
{
	cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 0) {
			book1.push_back(-temp);
		}
		else {
			book2.push_back(temp);
		}
	}
}

long long cal_len(vector<int> & book) {
	long long len = 0;
	sort(book.begin(), book.end());

	for (int eindex = book.size() - 1; eindex >= 0; eindex -= m) {
		int sindex = eindex - m + 1;
		if (sindex < 0)    break;

		int sub = book[eindex] - book[sindex];
		len += book[eindex] * 2;
	}
	if (book.size() % m != 0) {
		int index = book.size() % m;
		len += book[index - 1] * 2;
	}

	return len;
}

void solve()
{
	if (n == 0) {
		cout << "0";
		return;
	}

	long long result = 0;
	result += cal_len(book1);
	result += cal_len(book2);

	int end_len;
	if (book1.size()==0 && book2.size()==0) {
		end_len = 0;
	}
	else if (book1.size() == 0) {
		end_len = book2.back();
	}
	else if (book2.size() == 0) {
		end_len = book1.back();
	}
	else {
		end_len = max(book1.back(), book2.back());
	}
	result -= end_len;
	cout << result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}