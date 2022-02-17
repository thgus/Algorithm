/*
21611번: 마법사 상어와 블리자드
https://www.acmicpc.net/problem/21611

블리자드 마법을 시전하려면 방향 di와 거리 si를 정해야 한다. 총 4가지 방향 ↑, ↓, ←, →가 있고, 정수 1, 2, 3, 4로 나타낸다. 
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<int>> map;
int d,s;

int pop[4];

void blizzard_bead(int d, int s){
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};

    int y,x;
    y=x=n/2;
    for(int i=0;i<s;i++){
        y+=dy[d];   x+=dx[d];
        map[y][x]=-1;
    }
}

void print_vec(vector<vector<int>> &vec){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print_vec(deque<pair<int,int>> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<":"<<vec[i].second<<" ";
    }
    cout<<"\n";
}

bool isBoundary(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

void next_index(int &len, int &mlen, int &r, int &y, int &x){
    int dy[4]={1,0,-1,0};
    int dx[4]={0,1,0,-1};

    if(len==mlen){
        r++;
        len=0;
        if(r%4==0){
            y+=dy[3];   x+=dx[3];
            r=0;
            mlen+=2;
            return;
        }
    }
    y+=dy[r];   x+=dx[r];
}

void move_bead() {
    deque<pair<int,int>> que;
    vector<vector<int>> vec(n,vector<int>(n,0));

    int y=n/2, x=n/2-1;
    int len=0, mlen=2, r=0;
    
    que.push_back({0,0});
    while(1){
        if(map[y][x]!=-1){
            if(que.back().second==map[y][x]){
                que.back().first++;
            }
            else{
                que.push_back({1,map[y][x]});
            }
        }
        next_index(++len,mlen,r,y,x);
        if(!isBoundary(y,x))    break;
    }

    deque<pair<int,int>> temp;
    bool isPop=true;
    while(isPop){
        temp.clear();
        isPop=false;
        for(int i=0;i<que.size();i++){
            if(!temp.empty()&&temp.back().second==que[i].second){
                temp.back().first+=que[i].first;
            }
            else if(que[i].first>=4){
                isPop=true;
                pop[que[i].second]+=que[i].first;
                continue;
            }
            else{
                temp.push_back(que[i]);
            }
        }
        que=temp;
    }

    y=n/2; x=n/2-1;
    len=0; mlen=2; r=0;
    for(int i=1;i<que.size();i++){
        int l=que[i].first;
        int t=que[i].second;

        if(!isBoundary(y,x))    break;
        vec[y][x]=l;
        next_index(++len,mlen,r,y,x);
        if(!isBoundary(y,x))    break;
        vec[y][x]=t;
        next_index(++len,mlen,r,y,x);
    }
    map=vec;    
}

void solve(int d, int s)
{
    blizzard_bead(d-1,s);
    move_bead();
}

void initialize()
{
    cin>>n>>m;
    map.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    pop[0]=pop[1]=pop[2]=pop[3]=0;
    for(int i=0;i<m;i++){
        cin>>d>>s;
        solve(d,s);
    }
}

int main()
{
    sync_off;
    initialize();

    cout<<pop[1]+2*pop[2]+3*pop[3];

    return 0;
}