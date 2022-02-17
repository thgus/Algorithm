/*
14699번: 관악산 등반
https://www.acmicpc.net/problem/14699
*/

#include <iostream>
#include <vector>

#define MAX 5000

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<int> h(MAX+1);
vector<vector<int>> vec(MAX+1);

void initialize()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    int a,b;
    int h1,h2;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        h1=h[a]; h2=h[b];

        //a와 b지점의 높이를 비교해서
        //낮은곳에서 높은곳으로 향하도록 길 저장
        if(h1<h2){
            vec[a].push_back(b);
        }
        else if(h1>h2){
            vec[b].push_back(a);
        }
    }
}

int findShelter(vector<int> &visitShelter, int p){
    //쉘터에 접근한 적 있으면 그대로 리턴
    if(visitShelter[p]!=0){
        return visitShelter[p];
    }

    //해당 쉘터(p)에서 갈 수 있는 경로
    for(int i=0;i<vec[p].size();i++){
        int to=vec[p][i];

        int count;
        //만약 갈 수 있는 경로가 이전에 탐색된 적 있는지 확인
        if(visitShelter[to]!=0){
            count=visitShelter[to];
        }
        else{   
            //만약 갈 수 있는 경로가 없다면 해당 경로로 탐색
            count=findShelter(visitShelter, to);
        }

        //가장 많은 쉘터에 방문한 값을 저장함.
        if(count>visitShelter[p]){
            visitShelter[p]=count;
        }

    }

    //이전 경로까지의 max값 + p쉘터도 접근했으므로 1 더함
    visitShelter[p]+=1;

    return visitShelter[p];
}

void solve()
{
    vector<int> visitShelter(MAX+1,0);
    for(int i=1;i<=n;i++){
        cout<<findShelter(visitShelter,i)<<"\n";
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}