/*
7662번: 이중 우선순위 큐
https://www.acmicpc.net/problem/7662

입력 데이터의 수를 나타내는 정수 T
Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)
연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n
Q에 남아 있는 값 중 최댓값과 최솟값을 출력

depue 사용
=> 데이터 삽입, 삭제가 앞 뒤 둘다에서 이루어질 수 있음.
=> 이거 시간초과남. 초기화하고 정렬하는데 시간이 넘 오래걸리는듯;;

map 사용 
=> map 레드블랙트리로 되어있다고하던데 난 레드블랙트리 만들 자신은 없으니 그냥 STL 사용
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
		//key에 정수, value에 해당 정수 갯수
		map<long long, int> map;
		while (k-- > 0) {
			cin >> x >> n;
			if (x == 'I') { //삽입
				std::map<long long, int>::iterator it = map.find(n);
				if (it!=map.end()) {
					it->second = it->second + 1;
				}
				else {
					map.insert(make_pair(n, 1));
				}
			}
			else if (x == 'D') { //삭제
				if (map.empty()) { //map이 비였다면 삭제할게 없으므로
					continue;
				}
				if (n == -1) { //작은수 삭제
					if (map.begin()->second == 1) {
						map.erase(map.begin());
					}
					else {
						map.begin()->second -= 1;
					}
				}
				else if (n == 1) { //큰 수 삭제
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