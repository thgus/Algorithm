/*
19537번: 전투 시뮬레이션
https://www.acmicpc.net/problem/19537

처음에는 visited을 vector사용해서 선언해 줬는데
500*500 배열을 최대 10,000번 선언해주니 시간초과나서 정적배열로 선언함.
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Unit {
	int m, t, y, x;
};

struct Rush {
	int cost;
	int y, x;

	bool operator<(const Rush r)const {
		return r.cost < cost;
	}
};

int n, h, w;
int m;
vector<vector<int>> map;
vector<vector<int>> unit_map;
vector<Unit> unit;
bool visited[501][501];

bool isBoundary(int y, int x) {
	if (y >= 0 && y < h && x >= 0 && x < w) {
		return true;
	}
	else {
		return false;
	}
}

int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
void solve(int u, int a, int b){
	//목적지가 험준해서 갈 수 없는 곳이라면
	if(map[a][b]==-1)	return;
	//목적지에 다른 유닛이 존재한다면
	if(unit_map[a][b]!=-1)	return;
	visited[unit[u].y][unit[u].x]=true;
	
	priority_queue<Rush> que;
	que.push({0,unit[u].y,unit[u].x});
	
	while(!que.empty()){
		int cost=que.top().cost;
		int cy=que.top().y;
		int cx=que.top().x;
		que.pop();

		//목적지에 도착
		if(cy==a&&cx==b){
			unit_map[cy][cx]=unit[u].t;
			unit_map[unit[u].y][unit[u].x]=-1;
			//유닛의 위치 변경
			unit[u].y=a;
			unit[u].x=b;
			break;
		}

		//유닛 근처에 다른 세력의 유닛이 있는지 확인
		bool isBreak=false;
		for(int i=0;i<4;i++){
			int ny=cy+d[i][0];
			int nx=cx+d[i][1];
			if(!isBoundary(ny,nx))	continue;
			if(unit_map[ny][nx]!=-1&&unit_map[ny][nx]!=unit[u].t){
				isBreak=true;
				break;
			}
		}

		//유닛 근처에 다른 세력의 유닛이 있어 교전 상태가 된다면 이 분기로는 진행 X
		// 예외) 이 지점이 시작지점이라면 약진하여 교전에서 벗어날 수 있음.
		if(cost!=0 && isBreak)	continue;

		for(int i=0;i<4;i++){
			int ny=cy+d[i][0];
			int nx=cx+d[i][1];
			if(!isBoundary(ny,nx))	continue;
			
			// 험준해서 갈 수 없는 곳
			if(map[ny][nx]==-1)	continue;
			
			int ncost=cost+map[ny][nx];

			//소모한 스태미나가 약진으로 소모할 수 있는 스태미나를 초과한다면
			if(ncost>unit[u].m)	continue;
			//약진하려는 곳에 다른 세력의 유닛이 있다면
			if(unit_map[ny][nx]!=-1&&unit_map[ny][nx]!=unit[u].t)	continue;

			if(visited[ny][nx])	continue;
			visited[ny][nx]=true;
			que.push({ncost,ny,nx});
		}
	}
}

void initialize()
{	
	cin>>n>>h>>w;
	map.resize(h,vector<int>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>map[i][j];
		}
	}
	
	vector<int> level(n);
	for(int i=0;i<n;i++){
		cin>>level[i];
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			map[i][j]=level[map[i][j]-1];
		}
	}

	cin>>m;
	unit.resize(m);
	unit_map.resize(h,vector<int>(w,-1));
	for(int i=0;i<m;i++){
		cin>>unit[i].m>>unit[i].t>>unit[i].y>>unit[i].x;
		unit_map[unit[i].y][unit[i].x]=unit[i].t;
	}
}	

int main()
{
	sync_off;
	initialize();
	
	int k;
	cin>>k;
	
	int u,a,b;
	while(k--){
		cin>>u>>a>>b;

		//visited 배열 초기화
		for(int i=0; i<501; i++){
			memset(visited[i], false, sizeof(bool)*501); 
		}

		solve(u-1,a,b);
	}

	//결과 출력
	for(int i=0;i<unit.size();i++){
		cout<<unit[i].y<<" "<<unit[i].x<<"\n";
	}

	return 0;
}