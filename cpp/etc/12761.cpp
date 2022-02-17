#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> visited(100000, false);

//dfs
//���̿켱Ž���� ����ϱ� ������ �湮 Ƚ���� ������ �ʾƵ�
//���� ���� �湮�Ѱ� �湮 Ƚ���� ���� ���̹Ƿ�
//���� ���� �湮Ƚ���� �������� ���� �ּ� �湮 Ƚ���̴�.
int dfs(int A, int B, int n, int m) {

	//first=��ġ, second=�湮 Ƚ��
	queue<pair<int, int>> q;

	//������ ��ġ���� ����
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int loc = q.front().first;
		int num = q.front().second;
		q.pop();

		//�ֹ��� ��ġ�� ���ٸ� ����~!
		if (loc == m) {
			return num;
		}

		//+1
		//�迭 ũ�⸦ �Ѿ�� �ʰ�, ������ �湮���� �ʾҴٸ� �湮���� �ʾҴٸ�
		if (loc + 1 < m && !visited[loc + 1]) {
			//������ Ž���ϵ��� q�� ����
			q.push(make_pair(loc + 1, num + 1));
			//�湮 ǥ��
			visited[loc + 1] = true;	
		}
		//-1
		if (loc - 1 >= 0 && !visited[loc - 1]) {
			q.push(make_pair(loc - 1, num + 1));
			visited[loc - 1] = true;
		}
		//+A
		if (loc + A <= m && !visited[loc + A]) {
			q.push(make_pair(loc + A, num + 1));
			visited[loc + A] = true;
		}
		//+B
		if (loc + B <= m && !visited[loc + B]) {
			q.push(make_pair(loc + B, num + 1));
			visited[loc + B] = true;
		}
		//-A
		if (loc - A >= 0 && !visited[loc - A]) {
			q.push(make_pair(loc - A, num + 1));
			visited[loc - A] = true;
		}
		//-B
		if (loc - B >= 0 && !visited[loc - B]) {
			q.push(make_pair(loc - B, num + 1));
			visited[loc - B] = true;
		}
		//loc*A
		if (loc * A <= m && !visited[loc * A]) {
			q.push(make_pair(loc * A, num + 1));
			visited[loc * A] = true;
		}
		//loc*B
		if (loc * B <= m && !visited[loc * B]) {
			q.push(make_pair(loc * B, num + 1));
			visited[loc * B] = true;
		}
	}
}


int main() {
	//��ī������ ��
	int a, b;
	cin >> a >> b;
	
	//n=������ ��ġ, m=�ֹ��� ��ġ
	int n, m;
	cin >> n >> m;

	cout << dfs(a, b, n, m);

	return 0;
}