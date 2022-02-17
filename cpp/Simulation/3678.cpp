/*
3678번: 카탄의 개척자
https://www.acmicpc.net/problem/3678
*/

#include <iostream>
#include <vector>

#define MAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> v(MAX + 1);
vector<int> sum(6,0);

void solve()
{
	v[1] = 1;
	sum[1] = 1;
	int fre_max = 1;
	int mul = 1;
	int cur_max = 7;

	int a, b;
	for (int cur = 2; cur <= MAX; cur++) {
		vector<bool> isCan(6, true);

		if (cur == fre_max + 1) {
			a = cur - (6 * (mul - 1));
			b = a + 1;

			if (mul == 1)  a = b = 1;

			isCan[v[cur - 1]] = false;
			isCan[v[a]] = false;
		}
		else if ((cur-fre_max) % mul != 0) {
			isCan[v[cur - 1]] = false;
			isCan[v[a]] = false;
			isCan[v[b]] = false;

			a++;
			b++;
		}
		else {
			if (cur == cur_max) {
				fre_max = cur_max;
				cur_max += 6 * (++mul);
				isCan[v[b]] = false;
			}
			isCan[v[cur - 1]] = false;
			isCan[v[a]] = false;
		}

		int select_num;
		int select_acc = 1e9;
		for (int i = 1; i <= 5; i++) {
			if (isCan[i] && select_acc > sum[i]) {
				select_num = i;
				select_acc = sum[i];
			}
		}

		v[cur] = select_num;
		sum[select_num]++;
	}
}


void initialize()
{
	solve();

	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		cout << v[n] << "\n";
	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}