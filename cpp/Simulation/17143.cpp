/*
17143번: 낚시왕
https://www.acmicpc.net/problem/17143
*/

#include <iostream>
#include <vector>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Shark {
	bool isExist;
	int y, x, s, d, z;
};

void printField(vector<vector<int>>& vec) {
	cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

void solve()
{
	int r, c, m;
	cin >> r >> c >> m;

	vector<vector<int>> field(r, vector<int>(c, 0));
	vector<Shark> status(10001);

	int y, x, s, d, z;
	while (m--) {
		cin >> y >> x >> s >> d >> z;
		field[y-1][x-1] = z;
		status[z] = { true,y-1,x-1,s,d,z };
	}

	int result = 0;
	for (int x = 0; x < c; x++) {
		//printField(field);

		//사람 이동
		for (int y = 0; y < r; y++) {
			if (field[y][x] != 0) {
				status[field[y][x]].isExist = false;
				result += field[y][x];
				field[y][x] = 0;
				break;
			}
		}

		//상어 이동
		vector<vector<int>> temp(r, vector<int>(c, 0));
		for (int i = 1; i < status.size(); i++) {
			if (!status[i].isExist)	continue;

			int direction = status[i].d;
			int time = status[i].s;

			int nexty = status[i].y;
			int nextx = status[i].x;

			int quotient, remainder;
			switch (direction) {
			case 1:
				time += (r - 1) - nexty;
				quotient = (time / (r - 1));
				remainder = (time % (r - 1));

				if (quotient % 2 == 1) {
					nexty = remainder;
					status[i].d = 2;
				}
				else {
					nexty = ((r - 1) - remainder);
				}

				break;
			case 2:
				time += nexty;
				quotient = (time / (r - 1));
				remainder = (time % (r - 1));

				if (quotient % 2 == 0) {
					nexty = remainder;
				}
				else {
					nexty = ((r - 1) - remainder);
					status[i].d = 1;
				}

				break;
			case 3:
				time += nextx;
				quotient = (time / (c - 1));
				remainder = (time % (c - 1));

				if (quotient % 2 == 0) {
					nextx = remainder;
				}
				else {
					nextx = ((c - 1) - remainder);
					status[i].d = 4;
				}

				break;
			case 4:
				time += (c - 1) - nextx;
				quotient = (time / (c - 1));
				remainder = (time % (c - 1));

				if (quotient % 2 == 1) {
					nextx = remainder;
					status[i].d = 3;
				}
				else {
					nextx = ((c - 1) - remainder);
				}
				break;
			}

			status[i].y = nexty;
			status[i].x = nextx;

			if (temp[nexty][nextx] != 0) {
				if (temp[nexty][nextx] > i) {
					status[i].isExist = false;
				}
				else {
					status[temp[nexty][nextx]].isExist = false;
					temp[nexty][nextx] = i;
				}
			}
			else {
				temp[nexty][nextx] = i;
			}
		}

		field = temp;
	}

	cout << result;
}

int main()
{
	sync_off;
	solve();

	return 0;
}