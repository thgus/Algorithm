#include<iostream>
#include<algorithm>
#include<queue>
#include<list>

using namespace std;

struct Node {
	int num;
	vector<int> edg;
};

class Graph
{
	//그래프 노드의 수
	int n;
	vector<Node> vec;
	
public:
	void addEdge(int a, int b) {
		vec[b].edg.push_back(a);
	}

	int bfs(int s) {
		queue<int> que;
		int step = 0;
		vector<int>::iterator iter;
		vector<bool> visited;

		for (int i = 0; i <= n; i++) {
			visited.push_back(false);
		}

		que.push(s);
		visited[s] = true;

		while (que.size() != 0) {
			int temp = que.front();
			for (iter = vec[temp].edg.begin(); iter != vec[temp].edg.end(); ++iter) {
				if (!visited[*iter]) {
					que.push(*iter);
					visited[*iter] = true;
					step++;
				}
			}
			que.pop();
		}

		return step;
	}

	Graph(int _n) {
		n = _n;
		for (int i = 0; i <= n; i++) {
			Node temp;
			temp.num = i + 1;
			vec.push_back(temp);
		}
	}
};

int main() {
	int n, m;

	cin >> n;
	cin >> m;

	Graph graph(n);

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		graph.addEdge(a, b);
	}

	vector<int> maxValue;
	int max = -1;
	int step;

	for (int i = 1; i <= n; i++) {
		step=graph.bfs(i);
		if (max == step) {
			maxValue.push_back(i);
		}
		else if (max < step) {
			maxValue.clear();
			maxValue.push_back(i);
			max = step;
		}
	}

	sort(maxValue.begin(), maxValue.end());

	for (int i = 0; i < maxValue.size(); i++)
		cout << maxValue[i] << " ";

}