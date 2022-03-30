#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<string> map;

struct Node {
	int len = 0;
	pair<int,int> red;
	pair<int,int> blue;
};

Node s;
int gy, gx;

void initialize()
{
	cin >> n >> m;
	
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'R')	s.red.first = i, s.red.second = j, str[j] = '.';
			else if (str[j] == 'B')	s.blue.first = i, s.blue.second = j, str[j] = '.';
			else if (str[j] == 'O')	gy = i, gx = j;
		}
		map.push_back(str);
	}
}

// À§ ¿Þ ¾Æ·¡ ¿À
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
pair<int, int> go(int y, int x, int d)
{
	int ny = y;
	int nx = x;

	while (map[ny][nx]=='.')
	{
		ny += dy[d];
		nx += dx[d];
	}

	if (map[ny][nx] == 'O')	return { ny,nx };
	
	ny -= dy[d], nx -= dx[d];
	map[ny][nx] = '!';

	return { ny,nx };
}

bool check_front(Node cur, int d)
{
	switch (d)
	{
	case 0:
		if (cur.blue.first < cur.red.first)	return true;
		else return false;
		break;
	case 1:
		if (cur.blue.second < cur.red.second)	return true;
		else return false;
		break;
	case 2:
		if (cur.blue.first > cur.red.first)	return true;
		else return false;
		break;
	case 3:
		if (cur.blue.second > cur.red.second)	return true;
		else return false;
		break;
	}
}

void map_reset(Node cur)
{
	map[cur.blue.first][cur.blue.second] = '.';
	map[cur.red.first][cur.red.second] = '.';
	map[gy][gx] = 'O';
}

void print_map()
{
	for (int i = 0; i < n; i++) {
		cout << map[i] << "\n";
	}
}

int play()
{
	bool visited[10][10][10][10] = { false };
	visited[s.blue.first][s.blue.second][s.red.first][s.red.second] = true;

	queue<Node> que;
	que.push(s);

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		if (cur.len > 10)	return 0;
		
		if (cur.blue.first == gy && cur.blue.second == gx)	continue;
		else if (cur.red.first == gy && cur.red.second == gx)	return 1;

		for (int i = 0; i < 4; i++)
		{
			Node next;
			if (check_front(cur, i))	next.blue = go(cur.blue.first, cur.blue.second, i), next.red=go(cur.red.first, cur.red.second, i);
			else next.red = go(cur.red.first, cur.red.second, i), next.blue = go(cur.blue.first, cur.blue.second, i);

			//print_map(); cout << "\n";
			map_reset(next);

			if (visited[next.blue.first][next.blue.second][next.red.first][next.red.second])	continue;
			visited[next.blue.first][next.blue.second][next.red.first][next.red.second] = true;

			next.len = cur.len + 1;
			que.push(next);

		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	cout << play();

	return 0;
}