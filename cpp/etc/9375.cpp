#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct category {
	string name;
	int num;
};

int main() {
	int testCase;
	int n; //�غ��̰� ���� �ǻ��� ��
	int result[100];
	bool flag;
	string clothName;
	string clothCategory;

	int dress;
	vector<category> categoryNum;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		
		dress = 0;
		categoryNum.clear();

		cin >> n;
		for (int j = 0; j < n; j++) {
			flag = false;

			cin >> clothName;
			cin >> clothCategory;
			dress++;

			// ī�װ��� ����
			for (int k = 0; k < categoryNum.size(); k++) {
				if (categoryNum[k].name == clothCategory ) {
					categoryNum[k].num++;
					flag = true;
				}
			}
			// ������ �ȵǾ��ִٸ�
			if (!flag) {
				category t;
				t.name = clothCategory;
				t.num = 1;
				categoryNum.push_back(t);
			}
		}
		
		int count = 1;
		//ī�װ����� �ϳ��� ��� �ڵ� ī��Ʈ
		for (int j = 0; j < categoryNum.size(); j++) {
			count = count * (categoryNum[j].num + 1); // �� ī�װ� ���� �� ���� + ���Դ� ���
			
		}

		result[i] = count - 1; // �ƹ��͵� ���Դ� ��� ����
	}

	for (int i = 0; i < testCase; i++)
		cout << result[i] << "\n";

	return 0;
}