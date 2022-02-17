#include<iostream>
#include<algorithm>

using namespace std;

void findSqure( bool paper[128][128], int x1, int x2, int y1, int y2, int& white, int& blue) {
	
	bool flag = false;
	bool p = paper[x1][y1];

	//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;

	if (x1 == x2) {
		if (p)
			white++;
		else
			blue++;

		return;
	}

	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (p != paper[i][j]) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		int x = (x1 + x2) / 2;
		int y = (y1 + y2) / 2;

		findSqure(paper, x1, x, y1, y, white, blue);
		findSqure(paper, x1, x, y, y2, white, blue);
		findSqure(paper, x, x2, y1, y, white, blue);
		findSqure(paper, x, x2, y, y2, white, blue);
	}
	else {
		if (p)
			white++;
		else
			blue++;
	}

}

int main() {
	bool paper[128][128];
	int white = 0;
	int blue = 0;

	//색종이의 한 변의 길이
	int n;
	cin >> n;

	//색종이 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			//1(파란색)이면 true 0(하얀색)이면 false
			if (temp == 0)
				paper[i][j] = true;
			else
				paper[i][j] = false;
		}
	}
	findSqure(paper, 0, n, 0, n, white, blue);

	cout << white << '\n' << blue;

	return 0;
}