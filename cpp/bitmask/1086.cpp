/*
1086번: 박성원
https://www.acmicpc.net/problem/1086

어렵다.
https://travelbeeee.tistory.com/445
12345678 => (12345*1000+678) mod K => (12345 mod K)*(10000 mod K) + (678 mod K)
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> vec;
int k;

void initialize()
{
	cin >> n;

	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	cin >> k;
}

long long gcd(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


void solve()
{
	vector<vector<long long>> dp(1 << n, vector<long long>(k, 0));
	dp[0][0] = 1;

	long long denominator = 1;
	for (int i = 2; i <= n; i++) {
		denominator *= i;
	}

	vector<int> mod_digit(51);
	mod_digit[0] = 1;
	//123*(a)+45라면 45의 길이(2)의 +1 a=100 => a는 10을 3번 곱함
	//그러므로 mod_digit의 1에는 10^2, 2에는 10^3
	//이 때 10^50이 다 들어가면 자료형을 초과하므로 나머지를 계산해서 넣어주기	(나머지는 최대 100)
	for (int i = 1; i < 51; i++) {
		mod_digit[i] = (mod_digit[i - 1] * 10) % k;
	}

	//위에가 123*(a)+45d에서 a를 구하는 과정이었다면
	//지금은 123의 나머지를 구하는 과정
	vector<int> mod_vec(n,0);
	for (int i = 0; i < n; i++) {
		for (char c : vec[i]) {
			mod_vec[i] = mod_vec[i] * 10 + c - '0';
			mod_vec[i] %= k;
		}
	}

	for (int i = 0; i < (1 << n) - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))    continue;

			for (int l = 0; l < k; l++) {
				if (dp[i][l] == 0)	continue;

				int remainder = l * mod_digit[vec[j].size()];
				remainder += mod_vec[j];
				remainder %= k;

				dp[i | (1 << j)][remainder] += dp[i][l];
			}

		}
	}

	long long numerator = dp[(1 << n) - 1][0];
	if (numerator == 0) {
		cout << "0/1";
	}
	else {
		long long g = gcd(numerator, denominator);
		cout << numerator/g << "/" << denominator/g;
	}

}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}