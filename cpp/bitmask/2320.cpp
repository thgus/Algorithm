/*
2320¹ø:³¡¸»ÀÕ±â 
https://www.acmicpc.net/problem/2320
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> arr;

int match_char(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'E':
		return 1;
	case 'I':
		return 2;
	case 'O':
		return 3;
	case 'U':
		return 4;
	}
}

void solve()
{
	vector<vector<int>> score((1 << n + 1), vector<int>(5, -1));
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++)
	{
		que.push({ i,(1 << i) });

		score[(1 << i)][match_char(arr[i][0])] = arr[i].length();
	}

	while (!que.empty())
	{
		int cIndex = que.front().first;
		int cBit = que.front().second;
		que.pop();

		string cStr = arr[cIndex];
		char cl = cStr[cStr.length() - 1];
		int cScore = score[cBit][match_char(cStr[0])];

		for (int nIndex = 0; nIndex < n; nIndex++)
		{
			if (cBit & (1<< nIndex))	continue;
			int nBit = cBit | (1 << nIndex);

			string nStr = arr[nIndex];
			char cs = nStr[0];
			if (cl != cs)	continue;

			int nScore = cScore + nStr.length();
			if (score[nBit][match_char(cs)] >= nScore)	continue;
			score[nBit][match_char(cs)] = nScore;

			que.push({ nIndex,nBit });
		}
	}

	int max_score = -1;
	for (vector<int> vec:score)
	{
		for(int s:vec)
			if (max_score < s)	max_score = s;
	}
	cout << max_score;
}

int main()
{
	sync_off;

	//initialize===========================================
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//=====================================================
	solve();

	return 0;
}