/*
1506번: 경찰서
https://www.acmicpc.net/problem/1506

코사라주 알고리즘
https://wondy1128.tistory.com/130
증명
https://stonejjun.tistory.com/113

stack을 사용하는 이유? 내 나름대로 정리
dfs를 빠져나오는 순서대로 stack에 노드를 저장하게 되는데, 그렇게 된다면 그래프에 진입(시작)하는 노드들이 stack의 상단에 위치할 것이다.
이 진입 노드를 편의상 a라고 한다.
stack에 값이 저장되어 있다는 뜻은, 진입 노드 a에서 갈 수 있는 노드들이라는 뜻이다.
그렇다는 것은 a에서 역방향으로도 stack에 있는 노드들에 접근할 수 있다면, 두 노드들 간에 양방향 길이 있다는 뜻
한마디로 a->b->c->a의 길이 존재하고 이 때 stack을 사용하여 dfs를 빠져나오는 순서대로 저장한다면 다시 진입노드인 a부터 a->c->b->a의 길이 존재하는지 확인할 수 있다.
stack의 위에 있을수록 진입노드(진입노드와 가까운)이므로 이미 방문했다면 정방향에서는 길이 있었지만 후방향에서는 길이 없엇다.

궁금증
 1. 왜 역방향 그래프를 그리는가?
	이게 이 알고리즘에서 어떠한 역할을 하는지는 대충 짐작이 가는데 이것에 대한 자세한 설명?
	역방향으로 했는데 노드에 도달할 수 있다면 이것은 양 노드간의 길이 있다는 뜻이라고 나는 생각함.
	근데 뭔가 확신이 잘 안서요..
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> f_road;
vector<vector<int>> r_road;
vector<long long> cost;

void initialize()
{
	cin >> n;

	f_road.resize(n);
	r_road.resize(n);
	cost.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			if (i == j)	continue;
			if (str[j] == '0')	continue;
			
			f_road[i].push_back(j);
			r_road[j].push_back(i);
		}
	}

}

stack<int> s;

vector<bool> r_visited;
vector<bool> f_visited;

void f_dfs(int num)
{
	for (int next:f_road[num])
	{
		if (f_visited[next])  continue;
		f_visited[next] = true;

		f_dfs(next);
		s.push(next);
	}
}

void r_dfs(int num, long long& c_cost)
{
	if (c_cost > cost[num])
	{
		c_cost = cost[num];
	}

	for (int next:r_road[num])
	{
		if (r_visited[next])    continue;
		r_visited[next] = true;

		r_dfs(next, c_cost);
	}
}

void solve()
{
	f_visited.resize(n, false);
	r_visited.resize(n, false);

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		if (f_visited[i])  continue;
		f_visited[i] = true;
		
		f_dfs(i);
		s.push(i);

		/* 반례
			4
			1 2 3 4
			0100
			0000
			0100
			0010

			만약 넣은 족족 pop을 하면 정방향에서는 길이 없는데 역방향에서 우연히 길이 생겨서, 
			정방향에서 탐색하지 않은 길을 탐색할 가능성이 있음.
			또한, 위와 같은 이유로 정방향에서 탐색을 하지도 않았는데 이미 visite되어 탐색을 하지 않게 되는 경우가 생긴다.
			그렇기 때문에 일단 탐색을 다 한 후 역방향 탐색을 한다.

			일단 탐색을 다 하게 된다면,
			위에서 탐색되지 않은 길(정방향으로 연결되어 있지 않는 길)이 stack 위로 올라오기 때문에 이후 역방향 탐색에서 먼저 탐색되게 되어 visited됨
			 => 정방향으로 연결되어 있지 않은데 역방향으로 가는 오류를 없앨 수 있다.
		*/
		//while (!s.empty()) {
		//	int cur = s.top();
		//	s.pop();

		//	if (r_visited[cur])  continue;
		//	r_visited[cur] = true;

		//	long long c_cost = 1e9;
		//	r_dfs(cur, c_cost);

		//	result += c_cost;
		//}
		
	}

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		if (r_visited[cur])  continue;
		r_visited[cur] = true;

		long long c_cost = 1e9;
		r_dfs(cur, c_cost);

		result += c_cost;
	}

	cout << result;
}

int main()
{
	freopen("input.txt", "r", stdin);

	sync_off;

	initialize();
	solve();

	return 0;
}