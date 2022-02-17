#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	vector<long long> vec1;
	vector<long long> vec2;
	long long num;

	cin >> n;

	num = 0;

	//맨 처음에 0이 나오는 경우의 수는 0이고 그 외의 1~9가 나오는 경우의 수는 1
	vec1.push_back(0);
	vec2.push_back(0);
	for (int i = 1; i < 10; i++) {
		vec1.push_back(1);
		vec2.push_back(1);
	}

	//n의 길이만큼 계산
	for (int i = 1; i < n; i++) {
		// 1~9로 시작하는 값이 가질 수 있는 경우의 수 구하기
		for (int j = 0; j <= 9; j++) {
			// 값이(0)이면 다음으로 나올 수 있는 값은 하나 큰 값(1)밖에 나오지 않기 때문에
			// 값(0)의 다음값은 그 하나 큰 값(1)의 경우의 수 만큼 존재
			if (j == 0) {
				vec2[j] = vec1[j + 1];
			}
			// 값이(9)이면 다음 값이 나오는 경우의 수는 마지막 값의 바로 하나 작은 값(8)밖에 나오지 않음
			else if (j == 9) {
				vec2[j] = vec1[j - 1];
			}
			// 그 외에는 앞과 뒷 숫자의 경우의 수를 더한 만큼 존재
			else {
				vec2[j] = (vec1[j + 1] + vec1[j - 1]) % 1000000000;
			}
		}
		for (int j = 0; j < vec2.size(); j++)
			vec1[j] = vec2[j];
	}

	for (int i = 0; i < vec2.size(); i++) {
		num += vec2[i];
		num = num % 1000000000;
		
		//num += vec2[i] % 1000000000;
	}

	cout << num;

	return 0;
}