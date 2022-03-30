#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> dp;
vector<int> vec;
void dfs(int start, int end)
{

}

void solve(int n)
{
	// 근우턴에서 나올 수 있는 최선


	// 명우 턴에서 나올 수 있는 최선


	dp.clear();
	vec.clear();
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		vec.resize(n);
		for (int i = 0; i < n; i++)	cin >> vec[i];

		solve(n);
	}

}