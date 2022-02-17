/*
1976번: 여행 가자
https://www.acmicpc.net/problem/1976

이거 왜 메모리초과 났던거지?? 이해할 수 없네
*/

#include <iostream>
#include <vector>
#include <queue>

#define NMAX 200
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,m;
vector<vector<bool>> vec(NMAX+1,vector<bool>(NMAX+1));
vector<bool> isVisited(NMAX+1,false);
vector<int> parent(NMAX+1);
vector<int> plan;

void initialize()
{
    cin>>n;
    cin>>m;

    int temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>temp;
            (temp==0)?vec[i][j]=false:vec[i][j]=true;
        }
    }

    int p;
    for(int i=0;i<m;i++){
        cin>>p;
        plan.push_back(p);
    }
}

int findParent(int a){
    if(parent[a]==a){
        return a;
    }
    else{
        return parent[a]=findParent(parent[a]);
    }
}

void makeUnion(int a, int b){
    int ap=findParent(a);
    int bp=findParent(b);
    parent[ap]=bp;
}

void solve()
{
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    queue<int> que;
    for(int i=1;i<=n;i++){
        if(isVisited[i]){
            continue;
        }
        que.push(i);
        isVisited[i] = true;

        while (!que.empty())
        {
            int cur = que.front();
            que.pop();

            for (int j = 1; j <= n; j++)
            {
                if (vec[cur][j] && !isVisited[j])
                {
                    isVisited[j] = true;
                    makeUnion(cur, j);
                    que.push(j);
                }
            }
        }
    }


    bool isPossible=true;
    for(int i=1;i<m;i++){
        if(findParent(plan[i-1])!=findParent(plan[i])){
            isPossible=false;
            break;
        }
    }

    if(isPossible){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

int main()
{
    initialize();
    solve();

    return 0;
}