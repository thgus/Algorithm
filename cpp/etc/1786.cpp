/*
1786��: ã��
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

//pi�� kmp�� �����Ͽ� �ð� �����Ͽ� ���ϱ�
vector<int>	getPi(string p) {
	vector<int> pi(p.length(), 0);

	int matched = 0;
	for (int index = 1; index < p.length(); index++) {
		while (p[index] != p[matched]) { //���ڰ� ���� �ʴٸ� 
				//��Ī�Ǵ� ���λ�(���̻�) ������ �� ��Ī�Ǵ� �ܾ�(���� ���λ� ���̻�)���� �ִ��� Ȯ�� -> �ε��� �̵�
				//ex)	  012345 6
				//		S ababab|c|
				//		B	abab|a|bc
				//			0123 4 56
				//	=> S�� c�� B�� a���� ��Ī�� ���� �ʾ����Ƿ� B�� ���λ�� S�� ���̻�� ��Ī�� abab�� �� ������ �ִ��� Ȯ�� 
				//		abab�� �̹� ���� �񱳿��� ���� ���� pi[3(0���� �����ϹǷ� ���� 4�̸� 3)]=2(ab)��� ���� �������Ƿ� �̸� Ȱ���ϸ� ��.
				//			abab�� ���� ���ٰ� ��Ī�� �ܾ���� S�� ���̻� �κ������� ���ÿ� S�� ���λ�(����)
				//			��Ī�� ���̴� �׻� S�� �� ���̺��� �۱� ������ �̹� ��Ī�� ������ pi���� �̹� ����� �Ǿ� �ִ�.
				//		���ϴ� 6������ pi[3]�� �� 4������ �ٽ� �񱳸� �ؾ��� �� ������?
				//		�̹� �񱳴�� �� ab�� ���λ� ���̻�� ���ٴ� ���� �˰� �����Ƿ� 6�� ���� ����ص� ��. �׳� ���� ��Ǹ� �����ؼ� ������ ���� ��������.
				//			(������ 6������ ����� ����µ� �ٽ� 6������ ����� �ϹǷ� �ᱹ �ɸ��� �ð��� ���ڿ��� ���� => ���� �˰��򺸴� �ð�����! )
				//		  012345 6
				//		S ababab|c|
				//		B     ab|a|babc 

			//ù���� ���� ��Ī �ȵ�
			if (matched == 0) {
				pi[index] = 0;
				break;
			}
			//��ġ�Ǵ� ����(���λ�)�� ���� �� ���λ�&���̻� ���̸� matched�� ����
			//���� ��츦 ���ڸ� �̹� S�� B���� abab(pi[3])�� ab(���λ� ���̻��� ���� =2 )�� ��Ī�Ǿ������Ƿ� �� ���� Ȱ���ϴ� �Ͱ� ����.
			matched = pi[matched - 1];

		}

		if (p[index] == p[matched]) { //�� ���ڰ� ���ٸ�
			//��ġ�Ǵ� ���̰� 1 ������
			matched += 1;
			//pi�� ���� ����
			pi[index] = matched;
			//���� ������ �ϳ��� ������ ����
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

		//���� ���ڸ� ���ߴµ�
		while (t[index] != p[matchedIndex]) { //�� ���ڰ� ���� �� ����
			//ù���� ���� ���� ����.
			if (matchedIndex == 0) {
				break;
			}
			//������ ù���ں��� ���� �ʴ� ���� ���ܽ������Ƿ�
			//�� �ٷ� �Դٴ� ���� ����(���� ���ϰ� �ִ� �ٷ� ���� �ε��� ����)�� �¾Ҵٴ� ���ε�
			//�� ���� ���� �߿��� ���λ�� ���̻簡 ���� �κ��� �ִ����� pi�迭�� ���� Ȯ���ϰ�
			//���� �κ� ���ĺ��� �˻��ϸ� �ǹǷ� ���� ���� matchedIndex�� �־���.
			matchedIndex = pi[matchedIndex - 1];
		}

		if (t[index] == p[matchedIndex]) {
			//p�� ������ �ε����� ����
			if (matchedIndex >= p.size() - 1) {
				result.push_back(index - matchedIndex + 1);
				//���λ�� �����ϴ� ��ġ�������� �ٽ� ����
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