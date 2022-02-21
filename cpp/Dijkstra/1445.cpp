#include<iostream>
#include<vector>
#include<queue>

#define MAX 50

using namespace std;

int n, m;
char map[MAX][MAX];

int sy, sx;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

struct Node
{
	int y, x;
	int pass;
	int near;

	bool operator<(const Node n) const
	{
		if (pass == n.pass)	return near > n.near;
		return pass > n.pass;
	}
};

bool comp(Node a, Node b)
{
	if (a.pass == a.pass)
		return a.near <= b.near;
	return a.pass < b.pass;
}

vector<vector<Node>> dp(MAX, vector<Node>(MAX));

void initialize()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			dp[i][j] = { i,j,(int)1e9,(int)1e9 };
			if (map[i][j] == 'S')
			{
				map[i][j] = '.';
				sy = i;
				sx = j;
			}
		}
	}

	dp[sy][sx] = { sy,sx, 0,0 };
}

void solve()
{
	Node result;

	priority_queue<Node> que;
	que.push({ sy,sx,0,0 });
	dp[sy][sx].near = 0;
	dp[sy][sx].pass = 0;

	while (!que.empty())
	{
		Node cur = que.top();
		que.pop();

		if (map[cur.y][cur.x] == 'F')
		{
			bool flag = false;
			for (int k = 0; k < 4; k++)
			{
				int ky = cur.y + dy[k];
				int kx = cur.x + dx[k];
				if (ky < 0 || ky >= n || kx < 0 || kx >= m)	continue;
				
				if (map[ky][kx] == 'g')
				{
					flag = true;
					break;
				}
			}
			if (flag)	cur.near--;

			cout << cur.pass << " " << cur.near;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)	continue;

			Node next = cur;
			next.y = ny;
			next.x = nx;

			if (map[ny][nx] == 'g')
			{
				next.pass++;
			}
			else
			{
				bool flag = false;
				for (int k = 0; k < 4; k++)
				{
					int ky = ny + dy[k];
					int kx = nx + dx[k];
					if (ky < 0 || ky >= n || kx < 0 || kx >= m)	continue;

					if (map[ky][kx] == 'g')
					{
						flag = true;
						break;
					}
				}
				if (flag)	next.near++;
			}

			if (comp(dp[ny][nx], next))	continue;
			dp[ny][nx] = next;
			que.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}