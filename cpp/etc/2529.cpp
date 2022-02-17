#include<iostream>
#include<list>
#include<vector>

using namespace std;

//코드 더러움
//min코드는 좀 더 손 봐야하는데 귀찮아서 일단 이렇게 함
int main() {
	int k;
	cin >> k;
	
	vector<char> vec;
	char c;

	for (int i = 0; i < k; i++) {
		cin >> c;
		vec.push_back(c);
	}

	vector<int> max;
	vector<int> min;
	list<int> temp;

	//max값 만들기
	temp.push_back(9);
	for(int i = 0; i < vec.size(); i++) {
		if (vec[i] == '>') {
			while(temp.size()!=0) {
				max.push_back(temp.front());
				temp.pop_front();
			}
			temp.push_back(8 - i);
		}
		else {
			temp.push_front(8 - i);
		}
	}
	while (temp.size() != 0) {
		max.push_back(temp.front());
		temp.pop_front();
	}

	//min값 만들기
	temp.push_back(9);
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == '<') {
			while (temp.size() != 0) {
				min.push_back(9 - temp.front());
				temp.pop_front();
			}
			temp.push_back(8 - i);
		}
		else {
			temp.push_front(8 - i);
		}
	}
	while (temp.size() != 0) {
		min.push_back(9 - temp.front());
		temp.pop_front();
	}
	

	for (int i = 0; i < max.size(); i++)
		cout << max[i];
	cout << "\n";
	for (int i = 0; i < min.size(); i++)
		cout << min[i];

	return 0;
}