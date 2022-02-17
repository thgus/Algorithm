/*
19236번: 청소년 상어
https://www.acmicpc.net/problem/19236
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Shark {
	bool isExist;
	int num, y, x, d;
	bool operator<(Shark i) {
		return num < i.num;
	}
};

vector<vector<int>> vec(4, vector<int>(4));
vector<Shark> s;

void initialize()
{
	int d;
	s.push_back({ false,0,-1,-1,0 });
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> vec[i][j] >> d;
			s.push_back({ true,vec[i][j],i,j,d });
		}
	}

}

int result = 0;
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };

void printVector() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << vec[i][j] << ":" << s[vec[i][j]].d << " ";
		}
		cout << "\n";
	}
}

void changeFish(int index1, int index2) {
	int temp1y = s[index1].y;	int temp1x = s[index1].x;
	int temp2y = s[index2].y;	int temp2x = s[index2].x;

	s[index2].y = temp1y;	s[index2].x = temp1x;
	s[index1].y = temp2y;	s[index1].x = temp2x;

	int temp = vec[temp1y][temp1x];
	vec[temp1y][temp1x] = vec[temp2y][temp2x];
	vec[temp2y][temp2x] = temp;
}

void moveFish(int sharkY, int sharkX) {
	for (int i = 1; i <= 16; i++) {
		if (!s[i].isExist)   continue;

		int direction = s[i].d;
		do {
			int nexty = s[i].y + dy[direction];
			int nextx = s[i].x + dx[direction];
			if (nexty >= 0 && nexty < 4 && nextx >= 0 && nextx < 4 && !(nexty == sharkY && nextx == sharkX)) {
				s[i].d = direction;
				changeFish(vec[nexty][nextx], i);
				break;
			}
			direction = ((direction) % 8) + 1;
		} while (direction != s[i].d);
	}
}

void bfs(int y, int x, int score) {
	int index = vec[y][x];
	int direction = s[index].d;

	s[index].isExist = false;
	moveFish(y, x);

	vector<vector<int>> saveMap = vec;
	vector<Shark> saveShark = s;

	for (int i = 1; i <= 4; i++) {
		int nexty = y + dy[direction] * i;
		int nextx = x + dx[direction] * i;

		if (nexty >= 0 && nexty < 4 && nextx >= 0 && nextx < 4 ) {
			if (!s[vec[nexty][nextx]].isExist) {
				continue;
			}
			bfs(nexty, nextx, score + vec[nexty][nextx]);
			vec = saveMap;	s = saveShark;
		}
		else {
			break;
		}
	}

	result = max(result, score);
}

void solve()
{
	sort(s.begin(), s.end());
	bfs(0, 0, vec[0][0]);
	cout << result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}