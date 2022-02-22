#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

/*
https://www.acmicpc.net/board/view/8301
"���� x�̻��� �� �ִ°�?"
���� ���ʿ� �ִ� ��ġ���� ������� ������ x�̻��� �ǵ��� �����⸦ ��ġ
*/

using namespace std;

int n, c;
vector<int> s;

bool check(int len)
{
	int save = c - 1;
	
	int left, right;
	left = 0;
	right = 1;
	while (1)
	{
		if (s[right] - s[left] >= len)
		{
			save--;
			left = right;
			right++;
		}
		else right++;

		if (right == s.size())	break;
		if (save == 0)	break;
	}

	//cout << len << " " << save << "\n";
	if (save == 0)	return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	s.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s.begin(),s.end());

	int max_len = -1e9;
	int left = 0;
	int right = s[n - 1];
	
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid))
		{
			left = mid + 1;
			max_len = max(max_len,mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << max_len;

	return 0;
}