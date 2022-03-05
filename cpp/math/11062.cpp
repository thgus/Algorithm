#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<bool>> isLeft;
vector<vector<int>> dp;
vector<int> vec;
void dfs(int start, int end, vector<int> score, int turn)
{
	dp[start][end] = score[turn];

	int next_turn = (turn + 1) % 2;
	if (start - 1 >= 0)
	{
		int next_score = score[next_turn] + vec[start - 1];
		if (dp[start - 1][end] < next_score)
		{
			isLeft[start-1][end] = true;
			dp[start - 1][end] = next_score;
			int score_save = score[next_turn];
			score[next_turn] = next_score;
			dfs(start - 1, end, score, next_turn);
			score[next_turn] = score_save;
		}
	}

	if (end + 1 < n)
	{
		int next_score = score[next_turn] + vec[end + 1];
		if (dp[start][end + 1] < next_score)
		{
			isLeft[start][end+1] = false;
			dp[start][end + 1] = next_score;
			int score_save = score[next_turn];
			score[next_turn] = next_score;
			dfs(start, end + 1, score, next_turn);
			score[next_turn] = score_save;
		}
	}
}

void solve(int n)
{
	dp.resize(n, vector<int>(n, 0));
	isLeft.resize(n, vector<bool>(n));

	vector<int> score(2, 0);
	int turn = (n % 2 == 0) ? 1 : 0;
	for (int i = 0; i < n; i++) {
		score[turn] = vec[i];
		dfs(i, i, score, turn);
	}

	int start, end;
	start = 0;
	end = n - 1;

	turn = 0;
	score[0] = score[1] = 0;
	while (start <= end)
	{
		int cur_index = (isLeft[start][end]) ? start : end;
		score[turn] += vec[cur_index];

		turn += 1;
		turn %= 2;
		(isLeft[start][end]) ? start++ : end--;
	}

	cout << score[0] << "\n";

	isLeft.clear();
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