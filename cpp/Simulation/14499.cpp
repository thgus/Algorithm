/*
14499번: 주사위 굴리기
https://www.acmicpc.net/problem/14499
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
int x, y;
vector<vector<int>> map;
vector<int> order;

void initialize()
{
	int k;
	cin >> n >> m;
	cin >> y >> x >> k;
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	order.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}
}

bool boundary(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < m) {
		return true;
	}
	else {
		return false;
	}
}

int dice[7] = { 0,0,0,0,0,0,0 };
int ctop, cleft, cright, cup, cdown, cbuttom;

void solve()
{
	//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
	int ny=y, nx=x;
	int ntop, nbuttom, nleft, nright, nup, ndown;

	ntop = ctop = 1; nbuttom = cbuttom = 6;
	nleft = cleft = 4; nright = cright = 3;
	nup = cup = 2;  ndown = cdown = 5;

	for (int cur : order) {
		switch (cur) {
		case 1:
			nx = x + 1; 	ny = y;
			ntop = cleft;  nbuttom = cright;
			nleft = cbuttom;   nright = ctop;
			nup = cup;	ndown = cdown;
			break;
		case 2:
			nx = x - 1;	 ny = y;
			ntop = cright; nbuttom = cleft;
			nleft = ctop;  nright = cbuttom;
			nup = cup;	ndown = cdown;
			break;
		case 3:
			ny = y - 1;	 nx = x;
			ntop = cdown;  nbuttom = cup;
			nup = ctop;    ndown = cbuttom;
			nright = cright;	nleft = cleft;
			break;
		case 4:
			ny = y + 1;	 nx = x;
			ntop = cup;    nbuttom = cdown;
			nup = cbuttom; ndown = ctop;
			nright = cright;	nleft = cleft;
			break;
		}

		if (!boundary(ny, nx)) continue;
		
		if (map[ny][nx] == 0) {
			map[ny][nx] = dice[nbuttom];
		}
		else {
			dice[nbuttom] = map[ny][nx];
			map[ny][nx] = 0;
		}

		ctop = ntop;   cbuttom = nbuttom;
		cleft = nleft; cright = nright;
		cdown = ndown; cup = nup;
		y = ny;   x = nx;
		cout << dice[ctop] << "\n";
	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}