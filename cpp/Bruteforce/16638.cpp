/*
16638번: 괄호 추가하기 2
https://www.acmicpc.net/problem/16638
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int len;
string str;

void initialize()
{
	cin >> len >> str;
}

void print_vec(vector<long long> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

long long cal_num(vector<long long> num, vector<char>& operator_index) {
	//print_vec(num);

	//* 연산
	for (int i = 0; i < operator_index.size(); i++) {
		if (operator_index[i] != '*')	continue;

		int next_index = i+1;
		while (num[next_index] == LLONG_MIN) {
			next_index++;
		}
		num[next_index] *= num[i];
		num[i] = LLONG_MIN;
	}

	//+,- 연산
	for (int i = 0; i < operator_index.size(); i++) {
		if (operator_index[i] == '*')	continue;
		if (num[i] == LLONG_MIN)	continue;

		int next_index = i+1;
		while (num[next_index] == LLONG_MIN) {
			next_index++;
		}
		switch (operator_index[i]) {
		case '+':
			num[next_index] = num[next_index] + num[i];
			break;
		case '-':
			num[next_index] = num[i] - num[next_index];
			break;
		}
	}

	//cout << num[num.size() - 1] << "\n";
	return num[num.size() - 1];
}

long long back_tracking(vector<long long>& num, vector<char>& operator_index, int index) {
	long long cur_cal = LLONG_MIN;
	
	if (index >= operator_index.size()) {
		return cal_num(num, operator_index);
	}

	cur_cal = max(cur_cal, back_tracking(num, operator_index, index+1));

	long long save1 = num[index];
	long long save2 = num[index + 1];

	switch (operator_index[index]) {
	case '+':
		num[index + 1] += num[index];
		num[index] = LLONG_MIN;

		cur_cal = max(cur_cal, back_tracking(num, operator_index, index + 2));

		num[index] = save1;
		num[index + 1] = save2;
		break;
	case '-':
		num[index + 1] = num[index] - num[index + 1];
		num[index] = LLONG_MIN;

		cur_cal = max(cur_cal, back_tracking(num, operator_index, index + 2));

		num[index] = save1;
		num[index + 1] = save2;
		break;
	}

	return cur_cal;
}

void solve()
{
	vector<long long> num;
	int last_num = 0;
	vector<char> operator_index;
	for (int i = 1; i < len - 1; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			num.push_back(stoi(str.substr(last_num, i - last_num)));
			operator_index.push_back(str[i]);
			last_num = i + 1;
		}
	}
	num.push_back(stoi(str.substr(last_num, len - last_num)));

	cout << back_tracking(num, operator_index, 0);
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}