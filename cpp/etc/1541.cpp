#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

int main() {

	vector<string> symbols;
	vector<int> subNum;
	string value;
	cin >> value;
	
	string token;
	stringstream ss(value);

	//받은 문자열을 -기준으로 쪼개기 
	// => 문자열 식이 +로만 이루워짐, 식에서 +연산만 먼저 가능
	while (getline(ss, token, '-')) {
		symbols.push_back(token);
	}

	int sumNum;
	for (int i = 0; i < symbols.size(); i++) {
		sumNum = 0;

		//문자열에서 + 연산
		stringstream ss(symbols[i]);
		while (getline(ss, token, '+')) {
			sumNum += stoi(token);
		}
		subNum.push_back(sumNum);
	}

	//+연산한 값을 뺌 연산
	int result = subNum[0];
	for (int i = 1; i < subNum.size(); i++) {
		result -= subNum[i];
	}

	cout << result;

	return 0;
}