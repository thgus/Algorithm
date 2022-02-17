/*
7662��: ���� �켱���� ť
https://www.acmicpc.net/problem/7662

�Է� �������� ���� ��Ÿ���� ���� T
Q�� ������ ������ ������ ��Ÿ���� ���� k (k �� 1,000,000)
������ ��Ÿ���� ����(��D�� �Ǵ� ��I��)�� ���� n
Q�� ���� �ִ� �� �� �ִ񰪰� �ּڰ��� ���

depue ���
=> ������ ����, ������ �� �� �Ѵٿ��� �̷���� �� ����.
=> �̰� �ð��ʰ���. �ʱ�ȭ�ϰ� �����ϴµ� �ð��� �� �����ɸ��µ�;;

map ��� 
=> map �����Ʈ���� �Ǿ��ִٰ��ϴ��� �� �����Ʈ�� ���� �ڽ��� ������ �׳� STL ���
*/

#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int k;
	cin >> t;
	
	char x;
	int n;
	bool isSorted = false;
	while (t-- > 0) {
		cin >> k;
		//key�� ����, value�� �ش� ���� ����
		map<long long, int> map;
		while (k-- > 0) {
			cin >> x >> n;
			if (x == 'I') { //����
				std::map<long long, int>::iterator it = map.find(n);
				if (it!=map.end()) {
					it->second = it->second + 1;
				}
				else {
					map.insert(make_pair(n, 1));
				}
			}
			else if (x == 'D') { //����
				if (map.empty()) { //map�� �񿴴ٸ� �����Ұ� �����Ƿ�
					continue;
				}
				if (n == -1) { //������ ����
					if (map.begin()->second == 1) {
						map.erase(map.begin());
					}
					else {
						map.begin()->second -= 1;
					}
				}
				else if (n == 1) { //ū �� ����
					if ((--map.end())->second == 1) {
						map.erase(--map.end());
					}
					else {
						(--map.end())->second -= 1;
					}
				}
			}
		}
		if (map.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << (--map.end())->first << " " << map.begin()->first << "\n";
		}

	}
	return 0;
}