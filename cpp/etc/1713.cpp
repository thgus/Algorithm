#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct recStudent {
	int studentNum; //��ȣ
	int seq; //����
	int vote; //ǥ
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
	
		//���ڿ� �ԽõǾ��ִ� �л����߿� ��� ��õ���� �л��� �ִ��� ã��
		for (iter = frame.begin(); iter != frame.end(); iter++) {
			//��õ���� �л��� ���ڿ� �ԽõǾ� �ִٸ�
			if ((*iter).studentNum == recStu) {
				(*iter).vote++;
				flag = true;
				break;
			}
		}

		//���� ���ڿ� ��õ���� �л��� ���ٸ�
		if (!flag) {
			//���ڰ� �� ������ ��
			if(frame.size()>=n){
				//====���� ������ ���� ��õ�� �����鼭 �����Ȱ� ����
				frame.sort(compSeq);	//��ϼ��� �������� ����
				frame.sort(comVote);	//��õ�� �������� ����

				frame.pop_back();
			}		
			//�л� �߰�
			recStudent temp;
			temp.studentNum = recStu;
			temp.vote = 1;
			temp.seq = seq;
			seq++;

			frame.push_back(temp);
		}

	}

	//�л� ��ȣ ���� ������ ����
	frame.sort(compStuNum);

	for (iter = frame.begin(); iter != frame.end(); iter++) {
		cout << (*iter).studentNum << " ";
	}


	return 0;
}