/*
1043번: 거짓말
https://www.acmicpc.net/problem/1043

분리집합 신기하네
union-find 사용하면 되나?
https://hombody.tistory.com/86

그냥 배열에 표시해주는거 보다 union-find로 하는게 시간 절약되나?
얼마나 차이나길래
*/

#include <iostream>
#include <vector>

#define MAX 50
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

/*
 n: 사람의 수
 m: 파티의 수
 tp: 알고있는 사람의 수
*/
int n, m;
int tp;

vector<int> parent(MAX+1);
vector<vector<int>> party(MAX+1, vector<int>(0));
vector<int> knowPerson;

int findParent(int i) {
	if (parent[i] == i) {
		return i;
	}
	else {
		return parent[i] = findParent(parent[i]);
	}
}

void unionP(int a, int b) {
	int ap = findParent(a);
	int bp = findParent(b);
	parent[bp] = ap;
}

void initialize()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	cin >> tp;

	int p;
	for (int i = 0; i < tp; i++) {
		cin >> p;
		knowPerson.push_back(p);
	}

	int partyNum;
	int partyPerson;
	for (int i = 0; i < m; i++) {
		cin >> partyNum;
		for (int j = 0; j < partyNum; j++) {
			cin >> partyPerson;
			party[i].push_back(partyPerson);
		}
	}

}

void printParent(){
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<"";
    }
    cout<<"\n";
}

void solve() {
	//만약 아는사람이 없다면
	if (knowPerson.size() == 0) {
		//모든 파티에서 거짓말 해도 됨
		cout << m;
		return;
	}

	//아는사람 대표
	int knp = knowPerson[0];
	//아는 사람들 끼리 그룹 형성
	for (int i = 1; i < knowPerson.size(); i++) {
		unionP(knp, knowPerson[i]);
	}

	//파티 탐색
	//거짓말을 할 수 있는 파티는 파티원들이 이전 파티와 다음 파티에서 진실을 아는 사람을 만나면 X
	for (int i = 0; i < m; i++) {     
        /* 아래와 같이 코드를 짜면 이후 파티에서 진실을 아는 사람을 만나도 이전 파티에서 만나는 사람들과 연관 안됨
        반례)
        6 5
        1 6
        2 1 2
        2 2 3
        2 3 4
        2 4 5
        2 5 6

		bool donLie = false;
		for (int j = 0; j < party[i].size(); j++) {
			//진실을 아는 사람이 파티에 왔는지 확인
			//진실을 아는 그룹 안에 속한 사람이 있다면
			if (findParent(knp) == findParent(party[i][j])) {
				donLie = true;
				break;
			}
		}

		//진실을 아는 사람이 파티에 없다면 다음 파티 탐색
		if (!donLie) {
			continue;
		}
    
		//파티에 온 인원을 소문을 아는 사람 그룹으로 엮음
		for (int j = 0; j < party[i].size(); j++) {
			unionP(knp, party[i][j]);
		}
        */

        //파티에 온 인원 한 그룹으로 엮음
        for(int j=1;j<party[i].size();j++){
            unionP(party[i][j-1],party[i][j]);
        }

        //printParent();
	}

	int lieParty = 0;
	for (int i = 0; i < m; i++) {
		bool donLie = false;

		//파티 인원 중 진실을 알 가능성이 있는지(진실을 아는 그룹에 속하는지) 확인
		for (int j = 0; j < party[i].size(); j++) {
			//진실을 아는 그룹에 속하면 반복 종료
			if (findParent(knp) == findParent(party[i][j])) {
				donLie = true;
				break;
			}
		}

		//진실을 아는 사람이 없었다면 거짓말 해도 되는 파티 횟수 증가
		if (!donLie) {
			lieParty++;
		}
	}
    
	cout << lieParty;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}