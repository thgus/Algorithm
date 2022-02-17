/*
1865��: ��Ȧ
https ://www.acmicpc.net/problem/1865

���� ���� �˰���
= > �÷��̵� �ͼ��� O(N ^ 3)�̹Ƿ� �ð��ʰ�
= > ���ͽ�Ʈ��� �ٸ��� �����ε� �� �� ����.

�ݺ��� �������� ���Ƶ� ������ = > �� �� que ����;;
�޸� �ʰ� ����;;
Ž���� que�� Ǯ���µ� que�� �� ������ ������;; ������ ���� �� �������ϴϱ�;;

https://www.acmicpc.net/board/view/50494
���� ���� �ܼ� �׷��������� ����Ŭ ������ �ľ��� ���� dist[]�ʱ�ȭ�� � ������ ���־ ����� �����.
�ֳĸ� �Ÿ��� ���ϴ� �� �ƴ϶� ���������� ���� ����Ŭ�� ������ ��, ��ȭ�� �ľ��ϴ� ���̴ϱ��.

https://steady-coding.tistory.com/91

2�� �������� ���� �ִܰŸ��� 0->1->2�� ���ļ� 12+(-7)=5���� �մϴ�.
�׷��� ���ͽ�Ʈ�� �˰����� 1, 2�� ���� �߿��� dist[1]=12 > dist[2]=8�̶� �ؼ� 2�� ������ �湮
���� ���� ���� �˰����� 2�� for���� ���� ö���ϰ� ������ ��� ��츦 �� üũ�ϱ�� �մϴ�.
https://m.blog.naver.com/kks227/220796963742

���Ⱑ �����ϱ� ���� ��α� ����Ʈ
https://victorydntmd.tistory.com/104
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 987654321
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;

	int tc;
	cin >> tc;
	while (tc > 0) {
		tc--;

		//���� ���
		vector<vector<int>> road(501, vector<int>(501, MAX));

		int n, m, w;
		cin >> n >> m >> w;
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			if (road[s][e] > t) {
				road[s][e] = t;
				road[e][s] = t;
			}
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			road[s][e] = -t;
		}

		vector<int> d(501, MAX);	// ���� ��
		bool cycle = false;

		//������, value
		int st, v;
		d[1] = 0;

		//V(����)*E(����)�� �ݺ��� ����
		//�� �������� ��� ������ �湮�� �� �������� ��� V-1�� �湮�ؾ� ��
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					//�ڽſ��� ���ƿ��� ������ �ֳ�?
					//if (road[j][k] == MAX || j == k) {
					//	continue;
					//}

					//������ ���� ��ŭ ���ȴµ��� �� ������ �� �ִ� ���� �ִ�.
					//	=> ��������Ŭ. �������� ���� ������
					//�̸� Ȯ���ϱ� ���� ���� ����Ŭ�� ���ٸ� V-1���� �湮�ص� ��� ������ �ִ� �Ÿ��� �� �� ������
					// V��° �湮�� �ؼ� ���� �������ٸ� ���� ����Ŭ�� �ִٰ� �Ǵ�.
					if (d[k] > d[j] + road[j][k]) {
						if (i == n) {
							cycle = true;
							break;
						}
						d[k] = d[j] + road[j][k];
					}
				
				}
			}
		}
		if (cycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}