/*
1918번: 후위 표기식
https://www.acmicpc.net/problem/1918

코드 좀 다듬어야겠다;;;
이렇게 푸는거 맞는지부터 모르겠네;
*/

#include<iostream>
#include<algorithm>
#include<stack>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

stack<char> ope;
string str;

int main() {
	sync_off;

	cin >> str;

	char c;
	string result = "";
	
	for (int i = 0; i < str.size(); i++) {
		c = str[i];
		if (c >= 'A' && c <= 'Z') {
			result += c;
		}
		else if (c == '(') {
			ope.push(c);
		}
		else if (c == ')') {
			while (ope.top() != '(') {
				c = ope.top();
				ope.pop();
				result += c;
			}
			ope.pop();
		}
		else if (c == '*' || c == '/') {
			//A+B*C*D
			while (!ope.empty() && (ope.top() == '*' || ope.top() == '/')) {
				char temp = ope.top();
				if (temp == '(') {
					break;
				}
				result += temp;
				ope.pop();
			}
			ope.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!ope.empty()) {
				char temp = ope.top();
				if (temp == '(') {
					break;
				}
				result += temp;
				ope.pop();
			}
			ope.push(c);
		}
	}

	while (!ope.empty()) {
		c = ope.top();
		result += c;
		ope.pop();
	}

	cout << result;

	return 0;
}