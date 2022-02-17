/*
16637번: 괄호 추가하기
https://www.acmicpc.net/problem/16637
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int len;
string str;

void initialize()
{
	cin >> len >> str;
}

//befor_cal : 이전에 괄호를 사용해서 계산을 했는지
long long back_tracking(vector<int> &num, vector<char> &operator_index, long long cal, int index, bool befor_cal){
    long long cur_cal=LLONG_MIN;
    if(index>=operator_index.size()){
        return cal;
    }

    long long cur_result=cal;
    switch(operator_index[index]){
        case '+':
            cur_result+=num[index+1];
            break;
        case '-':
            cur_result-=num[index+1];
            break;
        case '*':
            cur_result*=num[index+1];
            break;
    }
    cur_cal=max(cur_cal,back_tracking(num,operator_index,cur_result,index+1,false));
    
    if(index<operator_index.size()-1){
        long long result2=cal;

        long long temp;
        switch (operator_index[index+1])
        {
        case '+':
            temp=num[index+1]+num[index+2];
            break;
        case '-':
            temp=num[index+1]-num[index+2];
            break;
        case '*':
            temp=num[index+1]*num[index+2];
            break;
        }

        switch(operator_index[index])
        {    
        case '+':
            result2+=temp;
            break;
        case '-':
            result2-=temp;
            break;
        case '*':
            result2*=temp;
            break;
        }

        cur_cal=max(cur_cal,back_tracking(num,operator_index,result2,index+2,true));
    }

    return cur_cal;
}

void solve()
{
	vector<int> num;
	int last_num = 0;
	vector<char> operator_index;
	for (int i = 1; i < len - 1; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			num.push_back(stoi(str.substr(last_num, i - last_num)));
			operator_index.push_back(str[i]);
			last_num = i + 1;
		}
	}
	num.push_back(stoi(str.substr(last_num, len - last_num)));

	cout << back_tracking(num, operator_index,num[0],0,false);
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}