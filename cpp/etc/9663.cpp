/*
9663��: N-Queen
https://www.acmicpc.net/problem/9663

��Ʈ��ŷ�� ����� ������..
dfs...
�����Ѱ� �ð��ʰ��� ����;; 
ã�ƺ��� 2�����迭�� �Ź� �Ű������� �������༭ �ð��� �����ɸ��°� ���ٰ� �Ѵ�.
https://www.acmicpc.net/board/view/45970

2���� �迭 ��� X
2�����迭�� ����ϸ� ���� �� ���� ��ġ�� ��� ó���ؾ���.
���� �밢���̶�� ��Ģ�� ������ �̵��� �������� ��� ó������.
�ϳ��� ������ �ϳ��� queen�ۿ� ���� ���ϴ� ���� ��� �迭 �ϳ�
�ϳ��� �밢������ �ϳ��� queen�ۿ� ���� ���ϴ� �밢�� ��� �迭 �ϳ���(��,��)
�̷������� �ϸ� �ѹ��� �������� ���� �� ���� ���� �ľ� ����.
https://rile1036.tistory.com/65

�� ���� �ִ� ��ġ�� �����ؼ� ���ϴ� ����� ����.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 15

using namespace std;

vector<bool> col(MAX, true);
//�밢�� ����� ���� 2*n-1��
vector<bool> l_d(MAX * 2, true);
vector<bool> r_d(MAX * 2, true);
int n;

int result;

void dfs(int _y) {	
	if (_y == n) {
		result++;
		return;
	}

	int sum = 0;
	for (int x = 0; x < n; x++) {
		if (!(col[x]) || !(l_d[n - _y + x - 1]) || !(r_d[_y + x])) {
			continue;		
		}
		//cout << x << " " << _y << " " << n - _y + x - 1 << " " << _y + x << "\n";
		col[x] = l_d[n - _y + x - 1] = r_d[_y + x] = false;
		dfs(_y + 1);
		col[x] = l_d[n - _y + x - 1] = r_d[_y + x] = true;
	}
	//cout << "\n";
}

int main() {
	sync_off;
	cin >> n;
	result = 0;

	dfs(0);
	cout << result;
	
	return 0;
}