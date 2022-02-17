/*
1786번: 찾기
https://www.acmicpc.net/problem/1786

https://velog.io/@jihoson94/%EB%AC%B8%EC%9E%90%EC%97%B4-%EA%B2%80%EC%83%89-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%A0%95%EB%A6%ACKMP-%ED%8C%B0%EB%A6%B0%EB%93%9C%EB%A1%AC

https://m.blog.naver.com/kks227/220917078260
https://vvshinevv.tistory.com/2
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//pi도 kmp를 적용하여 시간 단축하여 구하기
vector<int>	getPi(string p) {
	vector<int> pi(p.length(), 0);

	int matched = 0;
	for (int index = 1; index < p.length(); index++) {
		while (p[index] != p[matched]) { //문자가 같지 않다면 
				//매칭되는 접두사(접미사) 내에서 또 매칭되는 단어(같은 접두사 접미사)들이 있는지 확인 -> 인덱스 이동
				//ex)	  012345 6
				//		S ababab|c|
				//		B	abab|a|bc
				//			0123 4 56
				//	=> S의 c와 B의 a에서 매칭이 되지 않았으므로 B의 접두사와 S의 접미사로 매칭된 abab에 또 패턴이 있는지 확인 
				//		abab는 이미 이전 비교에서 값이 나와 pi[3(0에서 시작하므로 길이 4이면 3)]=2(ab)라는 값이 나왔으므로 이를 활용하면 됨.
				//			abab와 같이 같다고 매칭된 단어들은 S의 접미사 부분이지만 동시에 S의 접두사(시작)
				//			매칭된 길이는 항상 S의 비교 길이보다 작기 때문에 이미 매칭된 길이의 pi값은 이미 계산이 되어 있다.
				//		비교하던 6번에서 pi[3]를 뺀 4번부터 다시 비교를 해야할 것 같지만?
				//		이미 비교대상 중 ab는 접두사 접미사로 같다는 것을 알고 있으므로 6번 부터 계산해도 됨. 그냥 위의 사실만 유념해서 변수에 값을 저장해줌.
				//			(위에서 6번에서 계산이 끊겼는데 다시 6번부터 계산을 하므로 결국 걸리는 시간은 문자열의 길이 => 기존 알고리즘보다 시간단축! )
				//		  012345 6
				//		S ababab|c|
				//		B     ab|a|babc 

			//첫글자 부터 매칭 안됨
			if (matched == 0) {
				pi[index] = 0;
				break;
			}
			//매치되는 길이(접두사)에 가장 긴 접두사&접미사 길이를 matched에 저장
			//위의 경우를 모자면 이미 S와 B에서 abab(pi[3])에 ab(접두사 접미사의 길이 =2 )가 매칭되어있으므로 이 값을 활용하는 것과 같음.
			matched = pi[matched - 1];

		}

		if (p[index] == p[matched]) { //두 문자가 같다면
			//매치되는 길이가 1 증가함
			matched += 1;
			//pi에 길이 저장
			pi[index] = matched;
			//위의 과정을 하나의 식으로 압축
			//pi[index] = ++matched;

		}
	}

	return pi;
}

vector<int> KMP(string t, string p, vector<int> pi) {
	vector<int> result;
	int find;

	int matchedIndex = 0;
	for (int index = 0; index < t.size(); index++) {

		//현재 문자를 비교했는데
		while (t[index] != p[matchedIndex]) { //비교 문자가 같을 때 까지
			//첫글자 부터 맞지 않음.
			if (matchedIndex == 0) {
				break;
			}
			//위에서 첫글자부터 맞지 않는 것은 제외시켰으므로
			//이 줄로 왔다는 것은 이전(현재 비교하고 있는 바로 이전 인덱스 까지)는 맞았다는 말인데
			//이 맞은 문자 중에서 접두사와 접미사가 같은 부분이 있는지를 pi배열을 통해 확인하고
			//같은 부분 이후부터 검색하면 되므로 이의 값을 matchedIndex에 넣어줌.
			matchedIndex = pi[matchedIndex - 1];
		}

		if (t[index] == p[matchedIndex]) {
			//p의 마지막 인덱스에 도착
			if (matchedIndex >= p.size() - 1) {
				result.push_back(index - matchedIndex + 1);
				//접두사로 시작하는 위치에서부터 다시 시작
				matchedIndex = pi[matchedIndex];
			}
			else {
				matchedIndex += 1;
			}
		}

	}

	return result;
}

void solution(string t, string p) {
	vector<int> result = KMP(t, p, getPi(p));

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int main() {
	sync_off;

	string t;
	string p;
	getline(cin, t);
	getline(cin, p);

	solution(t, p);

	return 0;
}