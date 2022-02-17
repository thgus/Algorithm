/*
1927번: 최소 힙
https://www.acmicpc.net/problem/1927

기존 힙은 max값이 최상단이었다면
이번에는 min값을 최 상단에 올려놓기

	부모 번호 : n
	자식 번호 : n*2, n*2+1

삽입:
부모노드와 비교해서 자식의 값이 더 작으면 올리기
최상단까지 올라가면 그 트리에서 가장 작은 수라는 것
	최상단에 있는 노드는 그의 자식노드들보다 더 작은 수이고 
	이 최상단의 수보다 작다는건 제일 작다는 뜻
삭제:
가장 마지막 노드를 상단에 올림
좌우 자식들을 비교(최상단 노드를 삭제하면 두 자식중 하나가 가장 작은 수)하면서 점점 내려감
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec;
	// heap은 1부터 시작하니 0에 쓰레기값 넣어주기
	// 나중에 그냥 인덱스에서 -1 해주는거로 바꿀까 생각중
	vec.push_back(0);
	int n;	// 연산의 갯수
	cin >> n;

	int x; //연산에 대한 정보를 나타내는 정수. 0이면 출력

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		if (x == 0) {
			// 이미 vec[0]에 더미데이터가 있으니 
			// size가 1일때가 삽입한 수가 없는 경우
			if (vec.size()==1) {
				cout << "0\n";
				continue;
			}
			else {
				cout << vec[1] << "\n";
				vec[1] = vec[vec.size() - 1];
				vec.pop_back();
				
				//부모
				int me = 1;
				int child;
				int childValue;

				while (me * 2 < vec.size()) {
					
					child = me * 2;
					if ((child + 1) < vec.size()) {
						if (vec[child] > vec[child + 1]) {
							child = child + 1;
						}
					}
					
					if (vec[child] < vec[me]) {
						int temp = vec[child];
						vec[child] = vec[me];
						vec[me] = temp;
						me = child;
					}
					else {
						break;
					}
				}
				/*
				for (int t = 1; t < vec.size(); t++) {
					cout << vec[t] << " ";
				}
				*/
				//cout <<"\n"<< me * 2 << " " << vec.size() << "\n";

			}
		}
		else {
			vec.push_back(x);

			//자식
			int me = vec.size()-1;

			// 자식값이 부모값보다 작으면
			while (vec[me] < vec[me/2]) {				
				int temp = vec[me];
				vec[me] = vec[me/2];
				vec[me/2] = temp;

				if (me/2 <= 1) {	// 최상단까지 교환함
					break;
				}
				me = me/2;

			}

			/*
			for (int t = 1; t < vec.size(); t++) {
				cout << vec[t] << " ";
			}
			*/
		}
		
	}

	return 0;
}