/*
25243번: 가희와 중부내륙선
https://www.acmicpc.net/problem/25243
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node
{
	int id;
	string str;

	int hour;
	int min;

	int dir;

	int goal;
	int index;

	bool operator<(const Node node) const {
		if (hour == node.hour)
		{
			if (min == node.min)
			{
				int a = index % 2;
				int b = node.index % 2;

				if (a != b)
				{
					if (a == 0)	return true;
					else return false;
				}
				else
				{
					if (str == node.str)
					{
						return id > node.id;
					}
					return str > node.str;
				}
			}
			return min > node.min;
		}
		return hour > node.hour;
	}
};

int c, h;
priority_queue<Node> pq;

// line = 1,3,5,7
// station = 0,2,4,6,8
int spend_time[9] = { 0,7,1,7,1,8,1,10,0 };

void solve()
{

	//부발 ~가남	7
	//가남 ~감곡장호원	7
	//감곡장호원 ~앙성온천	8
	//앙성온천 ~충주	10

	vector<pair<int, int>> isUsed(9, { -1,-1 });
	priority_queue<pair<int, string>,vector<pair<int, string>>,greater<pair<int,string>>> result;

	while (!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();

		// 목적지
		if (cur.goal == cur.index)
		{
			cur.hour %= 24;

			string hour = (cur.hour >= 10) ? to_string(cur.hour) : "0" + to_string(cur.hour);
			string min = (cur.min >= 10) ? to_string(cur.min) : "0" + to_string(cur.min);

			string time = hour + ":" + min;
			result.push({ cur.id,time });
			continue;
		}

		int cur_index = cur.index;
		int next_index = cur_index + cur.dir;

		if (cur_index % 2 == 0) // 현재 station에 있음
		{
			if (isUsed[next_index] == make_pair(-1, -1))	// line이 비어있음
			{
				cur.min += spend_time[next_index];
				cur.hour += cur.min / 60;
				cur.min %= 60;

				isUsed[next_index] = make_pair(cur.hour, cur.min);

				cur.index = next_index;
				pq.push(cur);
			}
			else // line에 전차가 있음
			{
				cur.hour = isUsed[next_index].first;
				cur.min = isUsed[next_index].second;

				pq.push(cur);
			}
		}
		else // 현재 line에 있음
		{			
			isUsed[cur_index] = { -1,-1 };
			cur.index += cur.dir;
			
			cur.min += spend_time[cur.index];
			cur.hour += cur.min / 60;
			cur.min %= 60;

			pq.push(cur);
		}

	}

	// 출력
	while (!result.empty())
	{
		cout << result.top().second << "\n";
		result.pop();
	}

}

int main()
{
	sync_off;

	//initialize===========================================
	cin >> c >> h;

	string time;
	int id, hour;
	int min;
	for (int i = 0; i < c; i++)
	{
		cin >> id >> time;
		hour = stoi(time.substr(0, 2));
		min = stoi(time.substr(3, 2));

		//ascending.push_back({ id,time,hour,min,0,4 });
		pq.push({ id,time,hour,min,1,8,0 });
	}

	for (int i = 0; i < h; i++)
	{
		cin >> id >> time;
		hour = stoi(time.substr(0, 2));
		min = stoi(time.substr(3, 2));

		//descending.push_back({ id,time,hour,min,4,0 });
		pq.push({ id,time,hour,min,-1,0,8 });
	}

	//=====================================================

	solve();

	return 0;
}