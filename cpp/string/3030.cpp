#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

string player1, player2;

void solve(vector<pair<int,int>> &vec)
{
	bool flag = false;

	int aScore, bScore;
	aScore = bScore = 0;

	int turn = 1;
	for (pair<int, int> cur : vec)
	{
		// �̹� 2��Ʈ �̰�µ� ��� ��
		if (aScore == 2 || bScore == 2)	flag = true;

		int a = cur.first;
		int b = cur.second;

		// 6���� �� �̻��� �̱��� ����
		if (a < 6 && b < 6)	flag = true;
		// 1��Ʈ 2��Ʈ������ 6:6�̸� �Ѽ�Ʈ �� ��
		if (turn<3 && (a >= 6 && b >= 6))
		{
			if ((a != 6 && b != 6) || abs(a - b) != 1)	flag = true;
		}
		else
		{
			// �̱� ����� ������� 2���� �̻� �̱��� ����
			if (abs(a - b) < 2)	flag = true;
		}

		// federer�� �̱��� ����
		if (player1 == "federer"&&a < b)	flag = true;
		if (player2 == "federer"&&a > b)	flag = true;

		if (a > b)	aScore++;
		else bScore++;

		turn++;
	}

	// 2��Ʈ ���� �̱�� �ƴ�
	if (aScore != 2 && bScore != 2)	flag = true;
	if (aScore == 2 && bScore == 2)	flag = true;

	if (flag)
	{
		cout << "ne\n";
	}
	else
	{
		cout << "da\n";
	}
	
}

void initialize()
{
	cin >> player1 >> player2;

	int n;
	cin >> n;
	getchar();

	string str;
	while (n--)
	{
		vector<pair<int, int>> vec;
		getline(cin,str);

		int index = 0;
		int nIndex = 0;
		while (1)
		{
			nIndex = str.find(":", index);
			int a = stoi(str.substr(index, nIndex - index));
			
			index = str.find(" ", nIndex);
			int b;
			if (index == -1)
			{
				b = stoi(str.substr(nIndex+1, str.size()-1 - nIndex));
				vec.push_back({ a,b });
				break;
			}
			else
			{
				b = stoi(str.substr(nIndex+1, index -1 - nIndex));
				vec.push_back({ a,b });
			}
			
			index++;
		}
		solve(vec);

	}
}

int main()
{
	initialize();
	
	return 0;
}
