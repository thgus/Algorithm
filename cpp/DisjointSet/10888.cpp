/*
10888번: 두 섬간의 이동
https://www.acmicpc.net/problem/10888
*/

#include <iostream>
#include <vector>

#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

long long find_parent(vector<long long>& parent, long long i) {
	if (parent[i] == i) {
		return i;
	}
	else {
		return parent[i] = find_parent(parent, parent[i]);
	}
}

long long cal_combination(long long n) {
	return (n * (n - 1)) / 2;
}

void solve()
{
	int n;
	cin >> n;

	vector<long long> set_num(n + 1, 1);
	vector<long long> parent(n + 1);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	vector<long long> bridge(n + 1);
	long long cur;

	bridge[1] = 0;	bridge[2] = 1;
	long long term1 = 1;
	long long term2 = 2;
	for (int i = 3; i <= n; i++) {
		term1 += term2++;
		bridge[i] = bridge[i - 1] + term1;
	}

	long long pair = 0;
	long long bridge_sum = 0;
	bridge[1] = 0;
	while (--n) {
		cin >> cur;
		long long next = cur + 1;

		long long cur_parent = find_parent(parent, cur);
		long long next_parent = find_parent(parent, next);

		long long cur_end_parent = cur_parent + set_num[cur_parent] - 1;
		long long next_end_parent = next_parent + set_num[next_parent] - 1;

		parent[next_parent] = cur_parent;

		//두 섬 (i,j)가 왕래 가능할 때 섬 i에서 섬 j까지 가기 위해 이용해야 하는 최소 다리 개수의 합
		long long set_size = set_num[cur_parent] + set_num[next_parent];
		bridge_sum -= bridge[set_num[cur_parent]] + bridge[set_num[next_parent]];
		bridge_sum += bridge[set_size];

		//두 섬 간에 왕래가 가능한 섬들 (i,j) (i<j) 쌍들의 개수
		pair -= cal_combination(set_num[cur_parent]) + cal_combination(set_num[next_parent]);
		set_num[cur_parent] += set_num[next_parent];
		pair += cal_combination(set_num[cur_parent]);

		cout << pair << " " << bridge_sum << "\n";
	}
}

int main()
{
	sync_off;
	solve();

	return 0;
}