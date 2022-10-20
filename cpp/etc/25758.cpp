/*
25758번: 유전자 조합
https://www.acmicpc.net/problem/25758
*/

#include <iostream>
#include <vector>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<string> vec;

void solve()
{
	int alphabetLen = 'Z' - 'A' + 1;
	vector<int> frontCnt(alphabetLen, 0);
	vector<int> endCnt(alphabetLen, 0);

	vector<vector<bool>> frontIndex(alphabetLen, vector<bool>(n, false));
	vector<vector<bool>> endIndex(alphabetLen, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		char cf = vec[i][0];
		char ce = vec[i][1];

		int ncf = cf - 'A';
		int nce = ce - 'A';

		frontCnt[ncf]++;
		endCnt[nce]++;

		frontIndex[ncf][i] = true;
		endIndex[nce][i] = true;
	}

	set<char> result;
	for (int i = 0; i < alphabetLen; i++)
	{
		for (int j = 0; j < alphabetLen; j++)
		{
			if (frontCnt[i] == 0 || endCnt[j] == 0)	continue;

			if (frontCnt[i] == 1 && endCnt[j] == 1 )
			{
				bool flag = false;

				for (int k = 0; k < n; k++)
				{
					if (frontIndex[i][k] && endIndex[j][k])
					{
						flag = true;
						break;
					}
				}

				if (flag)	continue;
			}

			result.insert('A' + ((i > j) ? i : j));
		}
	}

	cout << result.size() << "\n";
	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << (*it) << " ";
	}
}

int main()
{
	sync_off;

	//initialize===========================================
	cin >> n;
	vec.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	//=====================================================
	solve();

	return 0;
}