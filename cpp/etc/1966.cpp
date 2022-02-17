#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

struct file
{
	int num;
	int importance;
};

bool compare(const file& a, const file& b) {
	return a.importance < b.importance;
}

int main() {
	int test_case;
	cin >> test_case;
	list<file> lis;

	//n=������ ��, m=�˰���� ����
	int n, m;
	for (int i = 0; i < test_case; i++) {
		cin >> n;
		cin >> m;

		for (int j = 0; j < n; j++) {
			file temp;
			temp.num = j;
			cin >> temp.importance;
			lis.push_back(temp);
		}

		int max;
		int count = 1;

		//�ִ� ã��
		//ù��° ���� �ִ��� �ƴϸ� ù��° �ڷ� ���� �ݺ�
		//�ִ��̰� ���� ���� ������ ���� �츮�� ã�� ���̶��
			//count���

		list<file>::const_iterator iter;

		while (1) {
			iter = max_element(lis.begin(), lis.end(), compare);
			if (iter==lis.begin()) {
				if ((*iter).num == m)
					break;
				else {
					count++;
					lis.pop_front();
				}
			}
			else {
				lis.push_back(lis.front());
				lis.pop_front();
			}
		}

		cout << count << "\n";
		
		lis.clear();
	}

	return 0;
}