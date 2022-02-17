/*
11437번: LCA
https://www.acmicpc.net/problem/11437
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

#define MAX 100000

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> vec(MAX);
vector<pair<int,int>> an;
int n,m;

int MAXDEPTH;

void initialize()
{
    cin>>n;
    MAXDEPTH=log2(n);

    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }  

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        an.push_back({a,b});
    }

}

void makeTree(vector<vector<int>> &parent, vector<int> &depth){
    stack<int> stk;
    stk.push(1);
    depth[1]=1;

    while(!stk.empty()){
        int cur=stk.top();
        stk.pop();
        
        //자식 노드가 있는지 탐색
        for(int next:vec[cur]){
            if(depth[next]==-1){
                //자식 노드의 깊이는 현재 깊이의 +1
                depth[next]=depth[cur]+1;
                //자식 노드의 부모를 cur로 설정
                parent[next][0]=cur;
                stk.push(next);
            }
        }
    }

    for(int j=1;j<=MAXDEPTH;j++){
        for(int i=1;i<=n;i++){
            //parent[i][j] => i노드의 2^j번 부모
            parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
}

int LCA(vector<vector<int>> &parent, vector<int> &depth, pair<int,int> p){

    int p1, p2;

    //깊이가 얕은 것을 p1, 깊은 것을 p2로 설정
    if (depth[p.first] < depth[p.second])
    {
        p1 = p.first; p2 = p.second;
    }
    else
    {
        p2 = p.first; p1 = p.second;
    }


    //예제로 maxdepth가 3이라고 하자. (MAXDEPTH가 3이라는 뜻은 n이 15이하라는 뜻, 최대로 될 수 있는 높이가 15)
    //8(2^3),4(2^2),2(2^1),1(2^0) 해서 8+4+2+1=15까지의 높이를 올라갈 수 있다. => 가장 낮은 깊이에서 최대 높이까지 올라갈 수 있다는 뜻
    //예를 들어 높이 p1와 p2의 높이 차이가 5이면 대충 4(2^2)+1(2^1) 이런 식으로 맞춰진다.
    
    //더 자세히 예를 들면 p1의 깊이가 1, p2의 깊이가 6이라고 하자.
    //깊이 차이는 5이므로 첫번째 k인 8(2^3)만큼 올라간다면 1의 높이를 넘어가므로 다음을 탐색한다.
    //다음 k는 4(2^2) p2(6)가 4만큼 올라가도 p1(1)을 넘어가지 않는다. 그럼 p2를 4만큼 올리자 => p1=1, p2=6-4=2
    //다음 k는 2(2^1) p2(2) 2만큼 올라가면 p1(1)을 넘어가므로 변경 X
    //다음 k는 1(2^0) p2(2)에서 1만큼 올라가면 p1=1, p2=1 같은 높이가 되었다.
    for(int k=MAXDEPTH;k>=0;k--){
        //p2와 p1의 깊이 차이가 2^k보다 크다면
        if(depth[p2]-depth[p1]>=(1<<k)){
            //p2의 2^k번 부모로 이동 => 2^k만큼 위로 올라감.
            p2=parent[p2][k];
        }
    }

    int result;
    if(p1==p2){
        result=p1;
    }
    else{
        for(int k=MAXDEPTH;k>=0;k--){
            //p1와 p2의 가장 높은 조상부터 조사한다. 모든 노드들은 1에서 기원하므로 가장 높은 조상은 같지만 어느순간 조상이 같아지지 않아진다.
            //만약 조상이 같지 않아진다면 가장 가까운 공통 조상은 p1,p2의 2^(k+1)의 부모와 같거나 아래 2^k만큼 부모보다는 위에 있다라는 의미가 된다.
            //위에서 p1, p2의 높이를 맞춰주던 것 처럼 p1,p2의 높이를 2^k만큼 올려준다.
            //2^(k+1)-2^(k)-1=2^(k-1)+2^(k-2)+...+2^(1)+2^(0) => 2^k번째 부모는 서로 같지 않으므로 후보에서 제외
            if(parent[p1][k]!=parent[p2][k]){
                p1=parent[p1][k];
                p2=parent[p2][k];
            }
        }
        result=parent[p1][0];
    }

    return result;
}

void solve()
{
    vector<vector<int>> parent(MAX+1,vector<int>(MAXDEPTH+1));
    vector<int> depth(MAX+1,-1);
    makeTree(parent,depth);

    for(pair<int,int> p:an){
        cout<<LCA(parent,depth,p)<<"\n";
    }
}

int main()
{
    initialize();
    solve();

    return 0;
}