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

	//���� ���ڿ��� -�������� �ɰ��� 
	// => ���ڿ� ���� +�θ� �̷����, �Ŀ��� +���길 ���� ����
	while (getline(ss, token, '-')) {
		symbols.push_back(token);
	}

	int sumNum;
	for (int i = 0; i < symbols.size(); i++) {
		sumNum = 0;

		//���ڿ����� + ����
		stringstream ss(symbols[i]);
		while (getline(ss, token, '+')) {
			sumNum += stoi(token);
		}
		subNum.push_back(sumNum);
	}

	//+������ ���� �� ����
	int result = subNum[0];
	for (int i = 1; i < subNum.size(); i++) {
		result -= subNum[i];
	}

	cout << result;

	return 0;
}