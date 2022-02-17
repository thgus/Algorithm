/*
2407¹ø: Á¶ÇÕ
https://www.acmicpc.net/problem/2407

https://jaimemin.tistory.com/682
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

unsigned long long combination1(int n, int m) {
	//nCm = nCn-m
	if (n / 2 < m) {
		m = n - m;
	}

	unsigned long long com = 1;

	for (int i = 1; i <= m; i++) {
		com *= n - i + 1;
		com /= i;
	}

	return com;
}

////nCr = n-1Cr + n-1Cr-1
vector<vector<string>> vec(101, vector<string>(100, ""));
string combination2(int n, int m) {
	//nCn=1, nC0=1
	if (n == m || m == 0) {
		return "1";
	}
	
	if (vec[n][m] != "") {
		return vec[n][m];
	}

	//string add
	string str1 = combination2(n - 1, m);
	string str2 = combination2(n - 1, m - 1);

	//cout << str1 << " " << str2 << " ";

	int sum = 0;
	string result = "";

	while (!str1.empty() || !str2.empty() || sum!=0 ) {
		if (!str1.empty()) {
			sum += str1.back() - '0';
			str1.pop_back();
		}
		if (!str2.empty()) {
			sum += str2.back() - '0';
			str2.pop_back();
		}
		result += sum % 10 + '0';
		sum /= 10;
	}

	//error: ¡®reverse¡¯ was not declared in this scope
	//reverse(result.begin(), result.end());
	
	string temp = "";
	while (!result.empty()) {
		temp += result.back();
		result.pop_back();
	}
	result = temp;
	vec[n][m] = result;

	//cout << result << "\n";

	return result;
}

int main() {
	int n, m;

	cin >> n;
	cin >> m;

	//cout << combination1(n,m);
	cout << combination2(n, m);

	return 0;
}