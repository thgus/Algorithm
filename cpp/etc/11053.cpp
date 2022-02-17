/*
11053번: 가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053

이거 그냥 for문 돌려서 깡으로 풀어도 되나?
찾아보니 dp(O(N^2))와 이진탐색(O(nlogn)) 두가지로 풀 수 있다.
dp는 2중 for문을 사용
	이건 쉬울거 같으니
이진탐색은 lowbundary를 사용해서 작은수로 치환
	=> 어치피 길이만 구하는거 수열이 어떻게 구성되는가는 상관 없이 가능성만 보고 간다.

나는 이진탐색으로 간다.
이 문제는 결국 앞의 순열보다 뒤에 더 좋은 순열이 나올 수 있는 가능성이 있다는 전제의 문제
그리고 중요한건 길이만 구하는 문제이므로 일단 가장 괜찮은 순열을 구하고 이를 치환해주면서 가능성을 열어둠.
 값이 최대값보다 작다면 해당 값이 들어갈 수 있는 부분과(lower_boundary 사용)값 치환해주기.
 어차피 필요한건 길이니까 치환을 하더라도 길이는 변하지 않음.
 또한 마지막 값보다 크면 순열에 추가하는데 중간에 치환을 해서 이전과 같은 순열이 아니더라도
 어차피 길이가 길어지는 기준(순열에 추가되는 기준)은 순열이 어떻게 구성되어있는가는 상관 없이
	현재 값이 마지막 값보다 크냐 작냐의 문제
 
 **** 이 방법은 순열을 구하는게 아니라 순열의 길이를 구하는 방법. seq에 모범 순열이 들어있다고 장담할 수 없음.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> A(1001);
	vector<int> seq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	std::vector<int>::iterator it;
	seq.push_back(A[0]);
	for (int i = 1; i < n; i++) {
		//맨 뒷자리 수 보다 크다면 순열에 추가
		if (seq[seq.size() - 1] < A[i]) {
			seq.push_back(A[i]);
		}
		else { //맨 뒷자리 수보다 작다면 중간 값들과 치환
			it = lower_bound(seq.begin(), seq.end(), A[i]);
			*it = A[i];
		}
	}

	cout << seq.size();

	return 0;
}