/*
1050번: 물약
https://www.acmicpc.net/problem/1050
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>

#define ll long long

using namespace std;

int n, m;

struct Info
{
	string name;
	ll cost;
};

map<string, int> medicine;	// 물약 name, info index
vector<Info> info;

struct Node
{
	string name;
	int degree;
	ll cost;
};

map<string,vector<pair<int,int>>> topology;
vector<Node> node;

inline int insertMedicine(string str, ll curCost)
{
	auto it = medicine.find(str);

	int index;
	if (it == medicine.end())
	{
		index = info.size();
		medicine.insert({ str,index });
		info.push_back({ str,curCost });
	}
	else
	{
		index = it->second;
		if (curCost != -1) {
			ll &cost = info[index].cost;

			if (cost == -1)	cost = curCost;
			else cost = min(cost, curCost);
		}
	}

	return index;
}

void initialize()
{
	cin >> n >> m;

	string str;
	int num;

	int len = 0;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		cin >> str >> num;

		insertMedicine(str, num);

		len++;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;

		int index = str.find('=', 0);
		string goal = str.substr(0, index);
		index += 1;

		//int goal_index=insertMedicine(goal, -1);
		node.push_back({ goal,0,0 });
		
		while (index<str.length())
		{
			int nindex = str.find('+', index);
			if (nindex == -1)	nindex = str.length() + 1;

			string cur = str.substr(index, nindex - index);
			int num = cur[0] - '0';
			string material = cur.substr(1, cur.size() - 1);

			//int material_index=insertMedicine(material, -1);
			node.back().degree++;
			topology[material].push_back({ node.size() - 1, num });

			index = nindex + 1;
		}

	}
}

void solve()
{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	for (auto it = medicine.begin(); it != medicine.end(); it++)
	{
		pq.push({ info[it->second].cost,it->second });
	}

	while (!pq.empty())
	{
		pair<ll,int> cur = pq.top();
		int cur_index = cur.second;
		pq.pop();

		// cost로 정렬된 priority_queue를 사용하므로 
		// 현재 cost가 저장된 cost보다 값이 크면 이전에 작은 cost가 탐색되었을 것이므로 재 탐색하지 않게 자른다.
		if (cur.first > info[cur_index].cost)	continue;

		string cur_material = info[cur_index].name;
		ll cur_cost = info[cur_index].cost;
		
		auto cur_topology = topology.find(cur_material);
		if (cur_topology == topology.end())	continue;

		for (pair<int, int> next_pair : cur_topology->second)
		{
			int next_index = next_pair.first;
			ll mul = next_pair.second;

			Node &next = node[next_index];
			next.cost += mul * cur_cost;
			if (next.cost > 1000000000)	next.cost = 1000000001;
			if (--next.degree == 0)
			{
				int medicine_index = insertMedicine(next.name, next.cost);
				pq.push({ next.cost,medicine_index });
			}
		}
	}
	
	auto result = medicine.find("LOVE");
	if (result == medicine.end())
	{
		cout << "-1";
	}
	else
	{
		int rIndex = result->second;
		cout << info[rIndex].cost;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}