#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dy[8] = { -1,-1,-1,1,1,1,0,0 };
int dx[8] = { 1,0,-1,1,0,-1,-1,1 };

vector<vector<char>> map(6, vector<char>(6, '.'));
bool check(int y, int x, int d, char c)
{
	int ny = y + dy[d];
	int nx = x + dx[d];

	if (ny >= 0 && ny < 6 && nx >= 0 && nx < 6)
	{
		if (map[ny][nx] == '.')
		{
			return false;
		}
		else if (map[ny][nx] == c)
		{
			return true;
		}
		else
		{
			if (check(ny, nx, d, c)) {
				//cout << ny << " " << nx << "\n";
				map[ny][nx] = (map[ny][nx]=='W') ? 'B' : 'W';
				return true;
			}
		}
	}

	return false;
}

void print_map()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map[2][2] = map[3][3] = 'W';
	map[2][3] = map[3][2] = 'B';

	int t;
	cin >> t;

	bool isBlack = true;
	int y, x;
	while (t--)
	{
		//cin >> x >> y;
		cin >> y >> x;
		y--, x--;

		map[y][x] = (isBlack) ? 'B' : 'W';
		for (int i = 0; i < 8; i++)
		{
			check(y, x, i, map[y][x]);
		}

		isBlack = (isBlack) ? false : true;

		//print_map();
		//cout << "\n";
	}

	print_map();

	int wcnt, bcnt;
	wcnt = bcnt = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == '.')	continue;
			else if (map[i][j] == 'W')	wcnt++;
			else bcnt++;
		}
	}
	if (wcnt > bcnt)	cout << "White";
	else cout << "Black";

	return 0;
}
