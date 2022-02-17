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

	//n=문서의 수, m=알고싶은 문서
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

		//최댓값 찾음
		//첫번째 값이 최댓값이 아니면 첫번째 뒤로 보냄 반복
		//최댓값이고 만약 지금 보내는 값이 우리가 찾는 값이라면
			//count출력

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