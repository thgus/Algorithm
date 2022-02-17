/*
2668번: 숫자고르기
https://www.acmicpc.net/problem/2668
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 100
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<int> vec(MAX+1,0);

//입력
void Initialize(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
}

int setSize=0;
int dfs(vector<int> &isChecked, int s){
    static int root;

    //1. 이번 dfs탐색에서 방문함 => 사이클을 형성하는 root를 찾음
    if (isChecked[s] == 1)
    {   
        //root에 현재 값 넣어주기
        root = s;
        return true;
    }//2. 방문한적 없음
    else if (isChecked[s] == 0)
    {
        //방문했음을 표시
        isChecked[s] = 1;

        //다음 값 탐색 후 반환값이 true라면 사이클을 찾았다는 뜻 => 집합 요소로 추가
        if (dfs(isChecked, vec[s]))
        {
            //집합 크기 증가
            setSize++;
            //사이클을 형성한다고 표시
            isChecked[s] = 2;

            //3. 사이클은 root까지만 형성되므로 만약 현재의 값이 root라면 그 이후부터는 집합 요소로 추가 X
            if (s == root)
            {
                return false;
            }
            return true;
        }
        else //4. 이미 사이클 확인이 끝남 => 집합에 들어갈 수 없음.
        {
            isChecked[s] = 3;
            return false;
        }

    }
    else{
        return false;
    }
}

void solve(){
    //방문한 적 있는지, 사이클을 형성 했는지 확인 여부
    //0:방문한 적 없음
    //1:방문은 했지만 사이클을 형성하는지는 알 수 없음
    //2:사이클을 형성함 => 첫째줄과 둘째줄의 정수 집합이 일치함
    //3:사이클을 형성하지 않음
    vector<int> isCheck(MAX+1,0);

    for(int i=1;i<=n;i++){
        if(isCheck[i]!=0){
            continue;
        }
        dfs(isCheck, i);
    }

    //print
    //뽑힌 정수의 갯수
    cout<<setSize<<"\n";
    //뽑힌 정수 출력
    for(int i=1;i<=n;i++){
        if(isCheck[i]==2){
            cout<<i<<"\n";
        }
    }

}

int main(){
    sync_off;
    Initialize();
    solve();

    return 0;
}