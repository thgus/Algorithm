/*
15787번: 기차가 어둠을 헤치고 은하수를
https://www.acmicpc.net/problem/15787
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<int> train;

void solve1(int i, int x)
{
	train[i] |= (1 << x);
}

void solve2(int i, int x)
{
	train[i] &= (~(1 << x));
}

void solve3(int i)
{
	train[i] *= 2;
	train[i] &= (~(1 << (20)));
}

void solve4(int i)
{
	train[i] /= 2;
}

void initialize()
{
	cin >> n >> m;
	train.resize(n, 0);

	int i, x;
	int order;
	for (int j = 0; j < m; j++) {
		cin >> order;
		switch (order) {
		case 1:
			cin >> i >> x;
			solve1(i - 1, x - 1);
			break;
		case 2:
			cin >> i >> x;
			solve2(i - 1, x - 1);
			break;
		case 3:
			cin >> i;
			solve3(i - 1);
			break;
		case 4:
			cin >> i;
			solve4(i - 1);
			break;
		}
	}

	vector<bool> bit((1 << 20), false);
	int go_train = 0;
	for (int i = 0; i < n; i++) {
		if (bit[train[i]])   continue;
		bit[train[i]] = true;
		go_train++;
	}
	cout << go_train;
}

int main()
{
	sync_off;
	initialize();

	return 0;
}