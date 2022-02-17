/*
9252번: LCS 2
https://www.acmicpc.net/problem/9252

dp는 생각하기 너무 어렵다..
https://hibee.tistory.com/242
예전에 했던 LCS랑 똑같이 해보려고 했는데 그건 최대 길이는 출력해도 LCS를 출력하기엔 무리가 있나?
하나의 문자가 뒤에 삽입될수도 있고 치환될수도 있는 경우가 있어서 이 경우의 수만 생각해주면 어케 될거같기도 한데;
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