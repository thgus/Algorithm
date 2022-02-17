/*
9252��: LCS 2
https://www.acmicpc.net/problem/9252

dp�� �����ϱ� �ʹ� ��ƴ�..
https://hibee.tistory.com/242
������ �ߴ� LCS�� �Ȱ��� �غ����� �ߴµ� �װ� �ִ� ���̴� ����ص� LCS�� ����ϱ⿣ ������ �ֳ�?
�ϳ��� ���ڰ� �ڿ� ���Եɼ��� �ְ� ġȯ�ɼ��� �ִ� ��찡 �־ �� ����� ���� �������ָ� ���� �ɰŰ��⵵ �ѵ�;
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
	string str1, str2;
	cin >> str1;
	cin >> str2;

	vector<vector<int>> vec(1001, vector<int>(1001, 0));

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i-1] == str2[j-1]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			else {
				vec[i][j] = max(vec[i][j - 1], vec[i - 1][j]);
			}
		}
	}
	int lcsSize = vec[str1.size()][str2.size()];
	cout << lcsSize << "\n";
	/*
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	int i = str1.size();
	int j = str2.size();

	vector<char> lcs;
	while (i >= 1 && j >= 1) {
		if (vec[i][j] == vec[i - 1][j]) {
			i -= 1;
		}
		else if (vec[i][j] == vec[i][j - 1]) {
			j -= 1;
		}
		else {
			lcs.push_back(str1[i - 1]);
			i -= 1;
			j -= 1;
		}
	}

	for (int i = lcs.size() - 1; i >= 0; i--) {
		cout << lcs[i];
	}
	
	return 0;
}