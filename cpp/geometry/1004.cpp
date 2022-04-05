/*
1004번: 어린 왕자
https://www.acmicpc.net/problem/1004
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;


int main()
{
	sync_off;

	int t;
	cin >> t;

	while (t--)
	{
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;

		int n;
		cin >> n;

		int result = 0;
		while (n--)
		{
			int y, x, r;
			cin >> y >> x >> r;

			// 시작점
			int slen = (sy - y) * (sy - y) + (sx - x) * (sx - x);
			bool isStart = (r*r >= slen) ? true : false;

			// 끝점
			int elen = (ey - y) * (ey - y) + (ex - x) * (ex - x);
			bool isEnd = (r*r >= elen) ? true : false;

			if (!isStart && isEnd)	result++;
			else if (isStart && !isEnd)	result++;
		}

		cout << result << "\n";
	}

	return 0;
}