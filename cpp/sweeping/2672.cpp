/*
2672번: 여러 직사각형의 전체 면적 구하기
https://www.acmicpc.net/problem/2672

어렵다.. 누구 도움을 받아야지 풀 수 있을 것 같아
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Square {
	double x, y, px, h, isLeft;
	bool operator<(Square i) {
		return x < i.x;
	}
};

int n;
vector<Square> vec;

void initialize()
{
	cin >> n;
	double x, y, w, h;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> w >> h;
		vec.push_back({ x,y,x + w, h,1 });
		vec.push_back({ x + w,y,x ,h,0 });
	}
}

void solve()
{
	sort(vec.begin(), vec.end());
	double result = 0;

	double lastxindex = -1;
	set<pair<pair<double, double>, double>> s;

	for (int i = 0; i < vec.size(); i++) {
		if (s.empty()) {
			lastxindex = vec[i].x;
			s.insert({ {vec[i].y,vec[i].h},vec[i].x });
			continue;
		}

		auto it = s.begin();
		double lastey = -1;
		while (it != s.end()) {
			double cury = (*it).first.first;
			double curh = (*it).first.second;

			if (cury + curh <= lastey) {
				it++;
				continue;
			}


			if (lastey > cury) {
				curh -= (lastey - cury);
			}

			result += (curh) * (vec[i].x - lastxindex);
			lastey = (*it).first.first + (*it).first.second;
			it++;
		}

		if (vec[i].isLeft) {
			s.insert({ {vec[i].y,vec[i].h},vec[i].x });
		}
		else {
			s.erase({ {vec[i].y,vec[i].h},vec[i].px });
		}
		lastxindex = vec[i].x;

	}

	// 예를들어 0.00997일 경우 0.01에 더 가까운데 *100%100 을 하면 뒤에 997부분이 잘려 0이 되어버리므로 0.001을 더한다.
	// .2까지만 출력하니까 0.001더해도 결과에는 지장 없음
	result += 0.001; 
	if (((int)(result * 100)) % 100 == 0) {
		printf("%d", (int)result);
	}
	else {
		printf("%.2f", result);
	}
}

int main()
{
	//sync_off;
	initialize();
	solve();

	return 0;
}