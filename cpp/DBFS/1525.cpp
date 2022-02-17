/*
1525번: 퍼즐
https://www.acmicpc.net/problem/1525

아래 코드 메모리초과임
나중에 배열을 이용해서 visited 하고싶음
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> vec(3, vector<int>(3));
bool visited[9][9][9][9][9][9][9][9][9];
pair<int, int> z;

void initialize()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vec[i][j];

			if (vec[i][j] == 0) {
				z.first = i;
				z.second = j;
			}
		}
	}
}

struct Node {
	vector<vector<int>> puz;
	pair<int, int> zero;
	int time;
};

void print_vec(vector<vector<int>>& m) {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m[i][j];
		}
		cout << "\n";
	}
}

void solve()
{
	queue<Node> que;
	que.push({ vec,z,0 });
	visited[vec[0][0]][vec[0][1]][vec[0][2]][vec[1][0]][vec[1][1]][vec[1][2]][vec[2][0]][vec[2][1]][vec[2][2]] = true;

	int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
	
	while (!que.empty()) {
		vector<vector<int>> cpuz = que.front().puz;
		pair<int, int> cz = que.front().zero;
		int time = que.front().time;
		que.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 2 && j == 2)	continue;
				if (cpuz[i][j] != i * 3 + j + 1) goto Brk;
			}
		}

		cout << time;
		return;

	Brk:
		for (int i = 0; i < 4; i++) {
			int ny = cz.first + d[i][0];
			int nx = cz.second + d[i][1];

			if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3) {
				vector<vector<int>> npuz = cpuz;
				int temp = npuz[ny][nx];
				npuz[ny][nx] = npuz[cz.first][cz.second];
				npuz[cz.first][cz.second] = temp;

				if (visited[npuz[0][0]][npuz[0][1]][npuz[0][2]][npuz[1][0]][npuz[1][1]][npuz[1][2]][npuz[2][0]][npuz[2][1]][npuz[2][2]])
					continue;

				visited[npuz[0][0]][npuz[0][1]][npuz[0][2]][npuz[1][0]][npuz[1][1]][npuz[1][2]][npuz[2][0]][npuz[2][1]][npuz[2][2]] = true;
				que.push({ npuz,{ny,nx},time + 1 });
			}
		}
	}

	cout << "-1";
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}