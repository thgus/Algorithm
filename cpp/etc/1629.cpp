/*
1629번: 곱셈
https://www.acmicpc.net/problem/1629
분할정복

풀이 1
시간초과 O(n) => 같은 연산을 계속 함
그래서 같은 연산을 계속 하지 않도록 공간을 만들어둘까 했는데 찾아보니 더 좋은 풀이가 있어서 대신 사용

풀이 2
buttom up방식
2*2=4 4*4=8 ....
10을 11번 곱해야 한다면 일단 11을 2로 나눠줌
10^11=10^5*10^5*10 => 이 경우 10^5만 구하면 10^11의 값을 알 수 있음
10^5=10^2*10^2*10 => 이 경우 10^2만 구하면 10^5의 값을 알 수 있음
10^2=10^1*10^1
이를 아래에서 위의 방향으로 수행하면 중복된 연산 없이 값을 구할 수 있음
O(nlongn)
*/

#include<iostream>
#include<algorithm>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//풀이 1
/* 
long long dc(int _a, int _b, int _c) {
	if (_b == 1) {
		return _a % _c;
	}
	return (dc(_a, (_b / 2), _c) * dc(_a, _b - (_b / 2), _c)) % _c;
}
*/

//풀이 2
long long dc(int _a, int _b, int _c) {
	if (_b == 1) {
		//반례) 4 1 2
		//return _a;
		return _a % _c;
	}
	long long mul = dc(_a, _b / 2, _c);
	mul = (mul * mul) % _c;
	// 홀수인 경우는 한번 더 곱해줘야 함
	if (_b % 2 == 1) {
		mul = (mul*_a) % _c;
	}

	return mul;
}


int main() {
	sync_off;
	int a, b, c;
	cin >> a >> b >> c;

	cout << dc(a, b, c);

	return 0;
}