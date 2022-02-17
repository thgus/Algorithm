/*
2056번: 작업
https://www.acmicpc.net/problem/2056

위상정렬 또 신기한 알고리즘이네
진짜 지금까지 공부했던 알고리즘들 다 정리할 필요가 있어보여;;
공부했던 알고리즘들 좀 적어놓을껄 뭐뭐 했는지 다 까먹었네;;

https://chosh95.tistory.com/426
앞의 작업부터 수행하면서 선행작업이 있을 때 선행작업 중에서 가장 늦게 끝나는 작업시간부터 현재 작업을 시작하면 된다.

뭔가 min함수를 사용해서 접근해야 할것만 같았는데 오히려 반복문을 돌 때 dp로 접근하여 잉여 시간 없이 작업을 수행하게 함으로
max로 값을 찾게된다
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;

vector<vector<int>> link(10001);
vector<pair<int,int>> vec(10001);

void initialize(){
    cin>>n;

    int a,b,c;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        //시간
        vec[i].first=a;
        //진입차수
        vec[i].second=b;
        for(int j=0;j<b;j++){
            cin>>c;
            link[c].push_back(i);
        }
    }
}

int main(){
    sync_off;
    initialize();
    
    queue<int> que;
    vector<int> time(10001,0);
    for(int i=1;i<=n;i++){
        if(vec[i].second==0){
            que.push(i);
            time[i]=vec[i].first;
        }
    }

    int num;

    while(!que.empty()){
        num=que.front();
        que.pop();

        //cout<<num<<": ";
        //cout<<time[num]<<"\n";

        for(int i=0;i<link[num].size();i++){
            //작업을 시작하려면 가장 오래걸리는 작업이 끝나야 시작할 수 있으므로 이전 작업중 가장 큰 시간을 저장
            //이 작업 후에 실행 되야 하는 작업들에게 자기가 끝나는 작업 시간을 알려줌
            //이 후 실행되는 작업들은 이전에 들어왔던 작업이 걸리는 시간과 현재 작업이 걸리는 시간을 비교해 더 큰 값을 저장 
            time[link[num][i]]=max(time[link[num][i]],time[num]);

            //앞서 작업들이 다 돌아서 진입차수가 0이 됨
            //위의 작업에서 진입차수가 0이 될 때 앞선 작업의 작업 시간을 알려주고 그 중 가장 큰 시간을 가지는 값을 저장하여
            //현재 que에 들어가기 까지의 걸리는 시간이 time에 저장되어 있음.
            if(--vec[link[num][i]].second==0){
                time[link[num][i]]+=vec[link[num][i]].first;
                que.push(link[num][i]);
            }
        }
    }

    int result=0;
    for(int i=1;i<=n;i++){
        result=max(time[i],result);
    }

    cout<<result;

    return 0;
}