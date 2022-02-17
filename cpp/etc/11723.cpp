/*
11723��: ���� 
https://www.acmicpc.net/problem/11723
*/

#include<iostream>
#include<set>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	set<int>::iterator iter;
	set<int> const all = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	set<int> s;
	
	string oper;
	int x;

	while (m > 0) {
		cin >> oper;
		// x���� ������ insert
		if (oper.compare("add") == 0) {
			cin >> x;
			if (s.find(x) == s.end()) {
				s.insert(x);
			}
		} // x���� ������ erase
		else if (oper.compare("remove") == 0) {
			cin >> x;
			if (s.find(x) != s.end()) {
				s.erase(x);
			}
		} // x���� ������ 1 ������ 0 ���
		else if (oper.compare("check") == 0) {
			cin >> x;
			iter = s.find(x);
			if (iter != s.end()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		} // x���� ������ erase ������ insert
		else if (oper.compare("toggle") == 0) {
			cin >> x;
			iter = s.find(x);
			if (iter != s.end()) {
				s.erase(x);
			}
			else {
				s.insert(x);
			}
		} // all�� �ʱ�ȭ
		else if (oper.compare("all") == 0) {
			s = all;
		} // ����
		else if (oper.compare("empty") == 0) {
			s.clear();
		}

		m--;
	}

	return 0;
}