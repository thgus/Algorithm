#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct bottle
{
	int a;
	int b;
	int c;
};

int main() {
	int a, b, c;
	queue<bottle> q;
	bool visit[201][201] = { false };
	vector<int> r;

	cin >> a;
	cin >> b;
	cin >> c;

	q.push({0,0,c});

	while (!q.empty()) {
		bottle temp;
		temp.a = q.front().a;
		temp.b = q.front().b;
		temp.c = q.front().c;
		q.pop();

		//방문했다면
		if (visit[temp.a][temp.b])
			continue;

		visit[temp.a][temp.b] = true;

		//a가 비어있다면
		if (temp.a == 0) {
			r.push_back(temp.c);
		}

		//A->B
		if (temp.a + temp.b > b)	//용량이 넘친다면
			q.push({ temp.a + temp.b - b,b,temp.c });	//상한선까지만 물 넣음
		else
			q.push({ 0,temp.a + temp.b,temp.c });	//안넘치면 다 넣음

		//a->c
		if (temp.a + temp.c > c)
			q.push({ (temp.a + temp.b) - c,temp.b,c });
		else
			q.push({ 0,temp.b,temp.a + temp.c });

		//b->a
		if (temp.b + temp.a > a)
			q.push({ a,(temp.b + temp.a) - a,temp.c });
		else
			q.push({ temp.b + temp.a, 0, temp.c });

		//b->c
		if (temp.b + temp.c > c)
			q.push({ temp.a,(temp.b + temp.c) - c,c });
		else
			q.push({ temp.a, 0, temp.b + temp.c });

		//c->a
		if (temp.c + temp.a > a)
			q.push({ a,temp.b,(temp.c + temp.a) - a });
		else
			q.push({ temp.c + temp.a,temp.b,0 });

		//c->b
		if (temp.c + temp.b > b)
			q.push({ temp.a,b,(temp.c + temp.b) - b });
		else
			q.push({ temp.a,temp.c + temp.b,0 });
	}

	sort(r.begin(), r.end());

	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " ";
	}

	return 0;
}