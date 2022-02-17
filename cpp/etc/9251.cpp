/*
9251번: LCS
https://www.acmicpc.net/problem/9251

LCS 알고리즘 참고
https://twinw.tistory.com/126
나는 길이만 구할 것 이므로 1차원 배열을 사용하겠음
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> vec(1001, 0);
	int last = 0;
	int temp;
	for (int i = 0; i < s2.length(); i++) {
		last = vec[0];
		for (int j = 0; j < s1.length(); j++) {		
			if (s1[j] == s2[i]) {
				temp = vec[j + 1];
				vec[j + 1] = last + 1;
				last = temp;
			}
			else {
				last = vec[j + 1];
				vec[j+1] = max(vec[j+1], vec[j]);
			}
		}
		/*
		for (int i = 1; i <= s1.length(); i++) {
			cout << vec[i];
		}
		cout << "\n";
		*/
	}

	cout << vec[s1.length()];

	return 0;
}