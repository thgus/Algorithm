/*
9328번: 열쇠
https://www.acmicpc.net/problem/9328
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define MAX 101
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t;
int h, w;

/*
'.'는 빈 공간을 나타낸다.
'*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
'$'는 상근이가 훔쳐야하는 문서이다.
알파벳 대문자는 문을 나타낸다.
알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
*/

vector<vector<char>> totalmap(MAX, vector<char>(MAX));
queue<pair<int, int>> startingPoint;

void solve(int key)
{
	int result = 0;
	vector<vector<bool>> isVisited(MAX, vector<bool>(MAX, false));
	vector<vector<pair<int, int>>> doormap(26);

	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	while (!startingPoint.empty()) {
		int starty = startingPoint.front().first;
		int startx = startingPoint.front().second;
		startingPoint.pop();

		queue<pair<int, int>> que;
		que.push({ starty,startx });

		while (!que.empty()) {
			int cury = que.front().first;
			int curx = que.front().second;
			que.pop();

			if (isVisited[cury][curx]) {
				continue;
			}
			isVisited[cury][curx] = true;

			char curchar = totalmap[cury][curx];

			if (curchar == '$') {
				result++;
			}
			else if (curchar >= 'a' && curchar <= 'z') {
				int index = curchar - 'a';
				key |= (1 << index);

				for (int i = 0; i < doormap[index].size(); i++) {
					startingPoint.push({ doormap[index][i].first,doormap[index][i].second });
				}
			}
			else if (curchar >= 'A' && curchar <= 'Z') {
				int index = curchar - 'A';
				if ((key & (1 << index))==0) {
					doormap[index].push_back({ cury,curx });
					isVisited[cury][curx] = false;
					continue;
				}
			}

			for (int i = 0; i < 4; i++) {
				int nexty = cury + d[i][0];
				int nextx = curx + d[i][1];
				if (nexty >= 0 && nexty < h && nextx >= 0 && nextx < w) {
					if (!isVisited[nexty][nextx]&&totalmap[nexty][nextx]!='*') {
						que.push({ nexty,nextx });
					}
				}
			}

		}
	}

	cout << result << "\n";
}

void initialize()
{
	cin >> t;
	while (t--) {
		cin >> h >> w;

		char c;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				totalmap[i][j] = c;

				if ((i == 0 || j == 0 || i==h-1 || j==w-1 ) && c != '*') {
					startingPoint.push({ i,j });
				}
			}
		}

		string keystr;
		cin >> keystr;

		int key = 0;
		if (keystr != "0") {
			for (int i = 0; i < keystr.size(); i++)
			{
				int keyIndex = keystr[i] - 'a';
				key |= (1 << keyIndex);
			}
		}

		solve(key);

	}
}

int main()
{
	sync_off;
	initialize();

	return 0;
}