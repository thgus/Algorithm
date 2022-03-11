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

	// 0: ������, 1: ���н���, 2: �ްԽ�, 3: �濡�� �޽�
	// �濡�� �޽��� �ִ� Aȸ
	// �ްԽ� 2�� ���� �ڽ� X
	// �������̳� ���н��ǿ��� �ڽ��� �� Bȸ �̻� �ؾ� �Ѵ�
	
	for (int i = 1; i < n; i++)
	{
		vector<vector<vector<int>>> temp(a + 1, vector<vector<int>>(b + 1, vector<int>(4, -1e9)));

		for (int j = 0; j <= a; j++)
		{
			for (int k = 0; k <= b; k++)
			{
				int mk = min(k + 1, b);

				// ������ -> ������
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][0] + vec[i].reading);
				// ������ -> ���н���
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][0] + vec[i].studyRoom);
				// ������ -> �ްԽ�
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][0] + vec[i].foyer);


				// ���н��� -> ������
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][1] + vec[i].reading);
				// ���н��� -> ���н���
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][1] + vec[i].studyRoom);
				// ���н��� -> �ްԽ�
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][1] + vec[i].foyer);


				// �ްԽ� -> ������
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][2] + vec[i].reading);
				// �ްԽ� -> ���н���
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][2] + vec[i].studyRoom);


				// �濡�� �޽� -> ������
				temp[j][mk][0] = max(temp[j][mk][0], dp[j][k][3] + vec[i].reading);
				// �濡�� �޽� -> ���н���
				temp[j][mk][1] = max(temp[j][mk][1], dp[j][k][3] + vec[i].studyRoom);
				// �濡�� �޽� -> �ްԽ�
				temp[j][k][2] = max(temp[j][k][2], dp[j][k][3] + vec[i].foyer);


				if (j + 1 <= a)
				{
					// ������ -> �濡�� �޽�
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][0] + vec[i].rest);
					// ���н��� -> �濡�� �޽�
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][1] + vec[i].rest);
					// �ްԽ� -> �濡�� �޽�
					temp[j + 1][k][3] = max(temp[j + 1][k][3], dp[j][k][2] + vec[i].rest);
					// �濡�� �޽� -> �濡�� �޽�
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