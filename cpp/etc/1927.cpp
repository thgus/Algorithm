/*
1927��: �ּ� ��
https://www.acmicpc.net/problem/1927

���� ���� max���� �ֻ���̾��ٸ�
�̹����� min���� �� ��ܿ� �÷�����

	�θ� ��ȣ : n
	�ڽ� ��ȣ : n*2, n*2+1

����:
�θ���� ���ؼ� �ڽ��� ���� �� ������ �ø���
�ֻ�ܱ��� �ö󰡸� �� Ʈ������ ���� ���� ����� ��
	�ֻ�ܿ� �ִ� ���� ���� �ڽĳ��麸�� �� ���� ���̰� 
	�� �ֻ���� ������ �۴ٴ°� ���� �۴ٴ� ��
����:
���� ������ ��带 ��ܿ� �ø�
�¿� �ڽĵ��� ��(�ֻ�� ��带 �����ϸ� �� �ڽ��� �ϳ��� ���� ���� ��)�ϸ鼭 ���� ������
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
	// heap�� 1���� �����ϴ� 0�� �����Ⱚ �־��ֱ�
	// ���߿� �׳� �ε������� -1 ���ִ°ŷ� �ٲܱ� ������
	vec.push_back(0);
	int n;	// ������ ����
	cin >> n;

	int x; //���꿡 ���� ������ ��Ÿ���� ����. 0�̸� ���

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		if (x == 0) {
			// �̹� vec[0]�� ���̵����Ͱ� ������ 
			// size�� 1�϶��� ������ ���� ���� ���
			if (vec.size()==1) {
				cout << "0\n";
				continue;
			}
			else {
				cout << vec[1] << "\n";
				vec[1] = vec[vec.size() - 1];
				vec.pop_back();
				
				//�θ�
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

			//�ڽ�
			int me = vec.size()-1;

			// �ڽİ��� �θ𰪺��� ������
			while (vec[me] < vec[me/2]) {				
				int temp = vec[me];
				vec[me] = vec[me/2];
				vec[me/2] = temp;

				if (me/2 <= 1) {	// �ֻ�ܱ��� ��ȯ��
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