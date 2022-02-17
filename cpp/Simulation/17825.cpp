/*
17825번: 주사위 윷놀이
https://www.acmicpc.net/problem/17825
*/

#include <iostream>
#include <queue>
#include <vector>

#define HORSEMAX 4
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int dice[10];
int direction[33][2] = { {1},{2},{3},{4},{5},
	{10,6},{7},{8},{9},{29},{11},
	{12},{13},{14},{17,15},{16},
	{9},{18},{19},{20},{21},{25,22},
	{23},{24},{9},{26},{27},{28},
	{31},{30},{31},{32},{32} };
int score[33] = { 0,2,4,6,8,10,13,16,19,25,12,14,16,18,20,22,24,22,24,26,28,30,28,27,26,32,34,36,38,30,35,40,0 };

vector<bool> isBlue(33, false);
vector<int> horse_location(HORSEMAX, 0);
vector<bool> isHorseExist(33, false);

void initialize()
{
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	isBlue[5] = true;
	isBlue[14] = true;
	isBlue[21] = true;
}

int max_sum = 0;
void dfs(int sum, int dice_index) {
	if (dice_index == 10) {
		if (sum > max_sum)	max_sum = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int save_horse_location = horse_location[i];
		int cur_horse_location = save_horse_location;
		int cur_dice = dice[dice_index];

		int next_index = 0;
		if (isBlue[cur_horse_location])	next_index = 1;

		while (cur_dice--) {
			cur_horse_location = direction[cur_horse_location][next_index];
			next_index = 0;
		}

		if (cur_horse_location!=32&&isHorseExist[cur_horse_location])	continue;
		
		isHorseExist[save_horse_location] = false;
		isHorseExist[cur_horse_location] = true;
		horse_location[i] = cur_horse_location;
		dfs(sum+score[horse_location[i]],dice_index+1);
		isHorseExist[save_horse_location] = true;
		isHorseExist[cur_horse_location] = false;
		horse_location[i] = save_horse_location;
	}
}

void solve()
{
	dfs(0, 0);
	cout << max_sum;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}