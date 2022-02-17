/*
2042번: 구간 합 구하기
https://www.acmicpc.net/problem/2042
*/

#include <iostream>
#include <vector>
#include <cmath>

#define NMAX 1000000
#define NLOG (int)ceil(log2(NMAX))
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, k;
vector<long long> vec(NMAX+1);
vector<long long> tree(1 << (NLOG+1));

long long makeTree(int index, int s, int e) {
	if (s == e) {
		return tree[index] = vec[s];
	}
	else {
		return tree[index] = makeTree(index * 2, s, (s + e) / 2) + makeTree(index * 2 + 1, (s + e) / 2 + 1, e);
	}
}

long long findSum(int index, int curs, int cure, int s, int e) {
	if (curs == s && cure == e) {
		return tree[index];
	}

	int middle = (curs + cure) / 2;
	if (e <= middle) {
		return findSum(index * 2, curs, middle, s, e);
	}
	else if (s > middle) {
		return findSum(index * 2 + 1, middle + 1, cure, s, e);
	}
	else {
		return findSum(index * 2, curs, middle, s, middle) + findSum(index * 2 + 1, middle + 1, cure, middle + 1, e);
	}
}

void changeTree(int index, int curs, int cure, long long target, long long changeNum) {

	tree[index] += ((long long)changeNum - (long long)vec[target]);
	if (curs == cure) {
		return;
	}

	int middle = (curs + cure) / 2;
	if (target >= curs && target <= middle) {
		changeTree(index * 2, curs, middle, target, changeNum);
	}
	else {
		changeTree(index * 2 + 1, middle + 1, cure, target, changeNum);
	}
}

int main()
{
	sync_off;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}
	makeTree(1, 1, n);

	long long a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			changeTree(1, 1, n, b, c);
			vec[b] = c;
		}
		else if (a == 2) {
			cout << findSum(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}