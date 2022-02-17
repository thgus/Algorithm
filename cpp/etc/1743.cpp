#include<iostream>
#include<vector>

using namespace std;

bool pass[102][102] = { false };
bool visited[102][102] = { false };

int s = 0;

void findFood(int r, int c) {	
	if (!pass[r][c] || visited[r][c]) {
		visited[r][c] = true;
		return;
	}
	else {
		visited[r][c] = true;
		s++;
	}
	findFood(r + 1, c);
	findFood(r, c + 1);
	findFood(r - 1, c);
	findFood(r, c - 1);
}

int main() {
	int n, m, k;
	vector<pair<int, int>> food;

	cin >> n;
	cin >> m;
	cin >> k;

	int r, c;

	for (int i = 0; i < k; i++) {
		cin >> r;
		cin >> c;
		pass[r][c] = true;
		food.push_back(pair<int,int>(r,c));
	}

	int max = 0;

	for (int i = 0; i < k; i++) {
		s = 0;
		findFood(food[i].first, food[i].second);
		if (s > max)
			max = s;
	}

	cout << max;

}