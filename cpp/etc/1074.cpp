/*
1074번: Z
https://www.acmicpc.net/problem/1074

재귀로 푸는구나... DP로 푸는줄 알았어;; 
2번이나 틀렸네;;
다행히 시간초과는 안남
// 실수 1 (x,y좌표 반대로 되어있는거 헷갈림)
// 실수 2 (2^(15)*2(15) 하면 int 값 범위 넘어감 sum 변수 long으로 변경 )
*/

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long find(int n ,int w, long sum, pair<int,int> point, pair<int,int> start, pair<int,int> end) {
	pair < int, int> p0 = make_pair(start.first, start.second);
	pair < int, int> p1 = make_pair(start.first, (start.second + end.second + 1) / 2);
	pair < int, int> p2 = make_pair((start.first + end.first + 1) / 2, start.second);
	pair < int, int> p3 = make_pair((start.first + end.first + 1) / 2, (start.second + end.second + 1) / 2);

	if (n == 1) {
		if (point == p0) {
			return sum;
		}
		else if (point == p1) {
			return sum + 1;
		}
		else if (point == p2) {
			return sum + 2;
		}
		else if (point == p3) {
			return sum + 3;
		}
	}
	
	/*
	cout << point.first << " " << point.second << "\n";
	cout << start.first << " " << start.second << "\n";
	cout << end.first << " " << end.second << "\n";
	cout << n << " " << w << " " << sum << "\n\n";
	*/

	/*
	cout << p0.first << " " << p0.second << " \n";
	cout << p1.first << " " << p1.second << " \n";
	cout << p2.first << " " << p2.second << " \n";
	cout << p3.first << " " << p3.second << " \n\n";
	*/
	
	if ((p3.first <= point.first) && (p3.second <= point.second)) {
		return find(n - 1, w / 2, sum + 3 * (pow(4, (n - 1))), point, p3, make_pair(p3.first + ((w / 2) - 1), p3.second + ((w / 2) - 1)));
	}
	else if ((p2.first <= point.first) && (p2.second <= point.second)) {
		return find(n - 1, w / 2, sum + 2 * (pow(4, (n - 1))), point, p2, make_pair(p2.first + ((w / 2) - 1), p2.second + ((w / 2) - 1)));
	}
	else if ((p1.first <= point.first) && (p1.second <= point.second)) {
		return find(n - 1, w / 2, sum + (pow(4, (n - 1))), point, p1, make_pair(p1.first + ((w / 2) - 1), p1.second + ((w / 2) - 1)));
	}
	else if ((p0.first <= point.first) && (p0.second <= point.second)) {
		return find(n - 1, w / 2, sum , point, p0, make_pair(p0.first + ((w / 2) - 1), p0.second + ((w / 2) - 1)));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		//크기 2^n
	int r, c;	//r행 c열
	cin >> n;
	cin >> r;
	cin >> c;
	long long w = pow(2, n);

	cout << find(n, w, 0, make_pair(r, c), make_pair(0, 0), make_pair(w - 1, w - 1));


	return 0;
}