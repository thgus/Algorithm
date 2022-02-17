/*
9466번: 텀 프로젝트
https://www.acmicpc.net/problem/9466

반례들 다 정답 잘나오는데 모르겠다
시간초과인지 뭔지
느리기도 하고;;
*/

#include <iostream>
#include <vector>

#define STUDENTMAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> visited(STUDENTMAX + 1);
vector<int> student(STUDENTMAX+1);

int t, n;
int result;

//사이클 시작 노드. 사이클이 돌지 않으면 0
int dfs(int s){
    //0. 방문하지 않음.
    //1. 방문함. => 방문은 했지만 사이클을 형성하는지는 알 수 없음.
    //2. 사이클 형성
    //3. 사이클 형성 안함. => 짝을 찾지 못하는 사람

    int next=student[s];
    int cycleStart;

    //이번 탐색에서 방문했었는데 또 방문한다면
    if(visited[s]==1){
        visited[s]=2;
        return s;
    }//방문을 한 적 없다면
    else if(visited[s]==0){
        visited[s]=1;
        cycleStart = dfs(next);
    }//이미 사이클이 형성되어있는지 판단이 끝난 경우
    else{
        return 0;
    }
    
    if(cycleStart==0){
        result++;
        visited[s]=3;
        return 0;
    }
    else{
        if(cycleStart==s){
            return 0;
        }
        else{
            visited[s]=2;
            return cycleStart;
        }
    }

}

void solv()
{
    cin >> t;

    while (t-- > 0){
        result=0;

        cin >> n;
        int temp;

        //와,,, 이거 때문에 틀렸네;; 진짜 옹졸해진다
        //visited.assign(STUDENTMAX,0);
        visited.assign(STUDENTMAX+1,0);

        for (int i = 1; i <= n; i++){
            cin >> temp;
            student[i]=temp;
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(i);
            }
        }

        cout<<result<<"\n";
    }

}

int main()
{
    sync_off;
    solv();

    return 0;
}