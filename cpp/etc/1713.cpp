#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct recStudent {
	int studentNum; //번호
	int seq; //순서
	int vote; //표
};

bool compStuNum(const recStudent& s1, const recStudent& s2) {
	return s1.studentNum < s2.studentNum;
}
bool compSeq(const recStudent& s1, const recStudent& s2) {
	return s1.seq > s2.seq;
}
bool comVote(const recStudent& s1, const recStudent& s2) {
	return s1.vote > s2.vote;
}

int main() {
	int n;
	int rec;
	int seq = 0;

	list<recStudent> frame;
	list<recStudent>::iterator iter;

	cin >> n;
	cin >> rec;

	int recStu;
	bool flag;

	for (int i = 0; i < rec; i++) {
		flag = false;		
		cin >> recStu;
	
		//액자에 게시되어있는 학생들중에 방금 추천받은 학생이 있는지 찾기
		for (iter = frame.begin(); iter != frame.end(); iter++) {
			//추천받은 학생이 액자에 게시되어 있다면
			if ((*iter).studentNum == recStu) {
				(*iter).vote++;
				flag = true;
				break;
			}
		}

		//만약 액자에 추천받은 학생이 없다면
		if (!flag) {
			//액자가 꽉 차있을 때
			if(frame.size()>=n){
				//====만약 같으면 가장 추천수 낮으면서 오래된걸 삭제
				frame.sort(compSeq);	//등록순서 내림차순 정렬
				frame.sort(comVote);	//추천수 내림차순 정렬

				frame.pop_back();
			}		
			//학생 추가
			recStudent temp;
			temp.studentNum = recStu;
			temp.vote = 1;
			temp.seq = seq;
			seq++;

			frame.push_back(temp);
		}

	}

	//학생 번호 증가 순서로 정렬
	frame.sort(compStuNum);

	for (iter = frame.begin(); iter != frame.end(); iter++) {
		cout << (*iter).studentNum << " ";
	}


	return 0;
}