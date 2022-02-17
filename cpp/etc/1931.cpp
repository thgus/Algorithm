#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//회의실 사용 끝나는 시간 비교
const bool compareE(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) //끝나는 시간이 같으면
		return a.first < b.first;	//시작시간 기준 오름차순
	else
		return a.second < b.second;
}

// 그리디 배낭
int main() {
	int n;
	cin >> n;

	//회의 시작,끝 시간 저장
	vector<pair<int,int>> lis;
	int start, end;

	//회의 시간 입력
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		lis.push_back(pair<int,int>(start, end));
	}
	
	int count = 0;	//회의 횟수
	end = -1;	//마지막 회의가 끝난 시간

	//회의실 사용 끝나는 시간을 기준으로 오름차순 정렬
	sort(lis.begin(), lis.end(), compareE);

	for (int i = 0; i < lis.size(); i++) {
		//회의실 사용 시작시간이 마지막 회의가 끝난 시간보다 이후면
		if (end <= lis[i].first) {
			//회의횟수 증가
			count++;
			//회의실 사용 끝 시간을 현재 회의실 사용 끝 시간으로 변경
			end = lis[i].second;
		}
	}

	cout << count;

	return 0;
}