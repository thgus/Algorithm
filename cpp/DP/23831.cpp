#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	int reading;
	int studyRoom;
	int foyer;
	int rest;
};

int n;
int a, b;
vector<Node> vec;

void initialize()
{
	cin >> n;
	cin >> a >> b;

	for (int i = 0; i < n; i++)
	{
		Node node;
		cin >> node.reading >> node.studyRoom >> node.foyer >> node.rest;
		vec.push_back(node);
	}
}

void solve()
{
	vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(4, -1e9)));
	
	int mk = min(1, b);
	dp[0][mk][0] = vec[0].reading;
	dp[0][mk][1] = vec[0].studyRoom;
	dp[0][0][2] = vec[0].foyer;
	if (a > 0) dp[1][0][3] = vec[0].rest;

	// 0: 정독실, 1: 소학습실, 2: 휴게실, 3: 방에서 휴식
	// 방에서 휴식은 최대 A회
	// 휴게실 2일 연속 자습 X
	// 정독실이나 소학습실에서 자습은 총 B회 이상 해야 한다
	
	for (int i = 1; i < n; i++)
	{
		vector<vector<vector<int>>> temp(a + 1, vector<vector<int>>(b + 1, vector<int>(4, -1e9)));

		for (int j = 0; j <= a; j++)
		{
			for (int k = 0; k <= b; k++)
			{
				int mk = min(k + 1, b);

				// 정독실 -> 정독실
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][0] + vec[i].reading);
				// 정독실 -> 소학습실
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][0] + vec[i].studyRoom);
				// 정독실 -> 휴게실
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][0] + vec[i].foyer);


				// 소학습실 -> 정독실
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][1] + vec[i].reading);
				// 소학습실 -> 소학습실
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][1] + vec[i].studyRoom);
				// 소학습실 -> 휴게실
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][1] + vec[i].foyer);


				// 휴게실 -> 정독실
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][2] + vec[i].reading);
				// 휴게실 -> 소학습실
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][2] + vec[i].studyRoom);


				// 방에서 휴식 -> 정독실
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][3] + vec[i].reading);
				// 방에서 휴식 -> 소학습실
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][3] + vec[i].studyRoom);
				// 방에서 휴식 -> 휴게실
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][3] + vec[i].foyer);


				if (j + 1 <= a)
				{
					// 정독실 -> 방에서 휴식
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][0] + vec[i].rest);
					// 소학습실 -> 방에서 휴식
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][1] + vec[i].rest);
					// 휴게실 -> 방에서 휴식
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][2] + vec[i].rest);
					// 방에서 휴식 -> 방에서 휴식
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][3] + vec[i].rest);
				}
			}
		}

		dp = temp;
	}

	int result = -1;
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result = max(result, dp[i][b][j]);
		}
	}
	cout << result;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}