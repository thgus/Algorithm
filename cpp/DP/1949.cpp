/*
1949번: 우수 마을
https://www.acmicpc.net/problem/1949

하지만 else 부분에서 자동적으로 max를 구하기 때문에 우수 x - 우수 x - 우수 x 같은 형식은 나오지 않는다.
*/

#include <iostream>
#include <vector>

#define NMAX 10000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> population(NMAX+1);
vector<vector<int>> trunk(NMAX+1);
void initialize()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>population[i];
    }

    int s,e;
    for(int i=0;i<n-1;i++){
        cin>>s>>e;
        trunk[s].push_back(e);
        trunk[e].push_back(s);
    }

}

vector<vector<int>> dp(NMAX,vector<int>(2,0));
vector<bool> isVisited(NMAX,false);
pair<int,int> dfs(int cur, int pre){
    int ev=population[cur], uev=0;
    for(int i=0;i<trunk[cur].size();i++){
        int next=trunk[cur][i];
        if(!isVisited[next]){
            isVisited[next]=true;
            pair<int,int> p=dfs(next,cur);
            ev+=p.second;
            uev+=max(p.first,p.second);
        }
    }

    return {ev,uev};
}

void solve()
{
    isVisited[1]=true;
    pair<int,int> result= dfs(1,0);
    cout<<max(result.first,result.second);
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}