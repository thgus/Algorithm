/*
11758번: CCW
https://www.acmicpc.net/problem/11758

https://www.acmicpc.net/blog/view/27
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=honeyeah&logNo=110155336328 사선공식
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;


int main()
{
	sync_off;

	int x1, x2, x3;
	int y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int result = 0;
	int m = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (m > 0)	result = 1;
	else if (m < 0)	result = -1;

	cout << result;


	return 0;
}