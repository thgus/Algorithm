#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int d, n;
	cin >> d >> n;

	vector<int> vec(d + 1);
	for (int i = 0; i < d; i++)
	{
		cin >> vec[i];
	}
	vec[d] = 0;

	bool flag = false;
	int buttom = d;

	vector<int> width(d + 1);
	width[0] = vec[0];
	for (int i = 1; i < d; i++)
	{
		width[i] = min(width[i - 1], vec[i]);
	}
	width[d] = 0;

	for (int i = 0; i < n; i++)
	{
		int r;
		cin >> r;

		while (buttom >= 0 && width[buttom] < r)
		{
			buttom--;
		}

		if (buttom < 0)
		{
			flag = true;
			break;
		}
		width[buttom] = 0;
	}

	if (flag)	buttom = -1;
	cout << buttom + 1;

	return 0;
}

