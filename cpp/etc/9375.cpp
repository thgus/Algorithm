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
	int n; //해빈이가 가진 의상의 수
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

			// 카테고리별 저장
			for (int k = 0; k < categoryNum.size(); k++) {
				if (categoryNum[k].name == clothCategory ) {
					categoryNum[k].num++;
					flag = true;
				}
			}
			// 저장이 안되어있다면
			if (!flag) {
				category t;
				t.name = clothCategory;
				t.num = 1;
				categoryNum.push_back(t);
			}
		}
		
		int count = 1;
		//카테고리마다 하나씩 골라서 코디 카운트
		for (int j = 0; j < categoryNum.size(); j++) {
			count = count * (categoryNum[j].num + 1); // 한 카테고리 안의 옷 갯수 + 안입는 경우
			
		}

		result[i] = count - 1; // 아무것도 안입는 경우 제외
	}

	for (int i = 0; i < testCase; i++)
		cout << result[i] << "\n";

	return 0;
}