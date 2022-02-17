/*
https://www.acmicpc.net/problem/1620
[BOJ] 1620��: ���¾� ���ϸ� ������ �̴ټ�
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

//�� ��¥ ��ư� �𸣰پ�

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	//map ó������غ�;; �ű��ϴ�
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
		
		if ('0' <= in[0] && in[0] <= '9') { //���ڸ� �Է¹���
			int sti = stoi(in);
			cout << name[sti -1 ] << "\n";
		}
		else { //���ڸ� �Է¹���
			s = in;
			cout << encyclopedia[s] << "\n";
		}
	}

	return 0;
}
