/*
https://www.acmicpc.net/problem/1620
[BOJ] 1620번: 나는야 포켓몬 마스터 이다솜
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

//와 진짜 어렵고 모르겟어

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	//map 처음사용해봐;; 신기하다
	map<string, int> encyclopedia;
	vector<string> name;
	char in[21];
	string s;

	for (int i = 0; i < n; i++) {
		scanf("%s", &in);
		s = in;
		encyclopedia.insert(pair<string, int>(in,i+1));
		name.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", &in);
		
		if ('0' <= in[0] && in[0] <= '9') { //숫자를 입력받음
			int sti = stoi(in);
			cout << name[sti -1 ] << "\n";
		}
		else { //문자를 입력받음
			s = in;
			cout << encyclopedia[s] << "\n";
		}
	}

	return 0;
}
