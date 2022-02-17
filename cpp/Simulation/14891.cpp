/*
14891번: 톱니바퀴
https://www.acmicpc.net/problem/14891
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<string> gear(4);
vector<vector<int>> lr(4, vector<int>(2));	//현재 left,right의 인덱스 저장

void initialize()
{
	for (int i = 0; i < 4; i++) 
	{
		cin >> gear[i];
	}

	for (int i = 0; i < 4; i++) 
	{
		lr[i][0] = 2;
		lr[i][1] = 6;
	}
}

void print_drection() 
{
	for (int i = 0; i < 4; i++) 
	{
		cout << lr[i][0] << " " << lr[i][1] << "\n";
	}
	cout << "\n";
}

// 반시계 방향으로 회전
void left_turn(int num)
{
	lr[num][0]++;
	lr[num][1]++;

	if (lr[num][0] > 7)  lr[num][0] = 0;
	if (lr[num][1] > 7) lr[num][1] = 0;

}

// 시계 방향으로 회전
void right_turn(int num)
{
	lr[num][0]--;
	lr[num][1]--;

	if (lr[num][0] < 0)  lr[num][0] = 7;
	if (lr[num][1] < 0) lr[num][1] = 7;
}

// 왼쪽 톱니바퀴
void left(int num, int d)
{
	if (num < 0)   return;

	char fre = gear[num + 1][lr[num + 1][1]];
	char cur = gear[num][lr[num][0]];
	if (fre == cur)    return;

	if (d == 1)
	{
		left(num - 1, -1);
		right_turn(num);
	}
	else if (d == -1)
	{
		left(num - 1, 1);
		left_turn(num);
	}
}

// 오른쪽 톱니바퀴
void right(int num, int d)
{
	if (num >= 4)  return;

	char fre = gear[num - 1][lr[num - 1][0]];
	char cur = gear[num][lr[num][1]];
	if (fre == cur)    return;

	if (d == 1)
	{
		right(num + 1, -1);
		right_turn(num);
	}
	else if (d == -1)
	{
		right(num + 1, 1);
		left_turn(num);
	}
}

void solve()
{
	int k;
	cin >> k;

	int num, direction;
	while (k--)
	{
		cin >> num >> direction;
		num--;  //인덱스는 0부터 시작하니 -1

		if (direction == 1)
		{
			right(num + 1, -1);
			left(num - 1, -1);
			right_turn(num);
		}
		else if (direction == -1)
		{
			right(num + 1, 1);
			left(num - 1, 1);
			left_turn(num);
		}

	}
}

//결과 계산 및 출력
void result() 
{
	int score[4] = { 1,2,4,8 };

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int cur_index = (lr[i][1] + 2) % 8;
		if (gear[i][cur_index] == '1')
		{
			sum += score[i];
		}
	}

	cout << sum;
}

int main()
{
	sync_off;
	initialize();
	solve();
	result();

	return 0;
}