#include<iostream>
#include<string>
#include<stack>

using namespace std;

void solve(int b, int e, string str)
{
	stack<string> stk;
	int index = 0;

	string result = "";
	while (1)
	{
		int nIndex = str.find('<', index);

	}
}

int main()
{
	int b, e;
	string str;

	while (1)
	{
		cin >> b >> e;
		if (b == -1 && e == -1)	break;

		getchar();
		getline(cin, str);

		solve(b, e, str);
	}
}