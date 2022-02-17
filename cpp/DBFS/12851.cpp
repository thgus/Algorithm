/*
12851번: 숨바꼭질 2
https://www.acmicpc.net/problem/12851
*/

#include <iostream>
#include <vector>
#include <queue>

//https://www.acmicpc.net/board/view/61289
#define MAX 100000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, k;
void initialize()
{
    cin >> n >> k;
}

void solve()
{
    int sFindCase = 0;
    int sTime = -1;

    //해당 좌표에 접근하는 시간이 같은 경우의 수가 많을수도 있기 때문에 bool이 아니라 int를 써서
    //접근 시간을 저장하고 접근 시간과 같은 시간으로 접근하면 que에 넣어주는 방식
    //ex) 1인 경우 2에 접근하는 방법은 1+1, 1*2 둘 다 같은 시간을 소비해서 같은 배열에 접근하는데 bool을 쓰면 하나만 접근하게 됨.
    vector<int> isVisited(MAX, -1);
    queue<pair<int, int>> que;
    que.push({n, 0});

    int time, x;
    while (!que.empty())
    {
        x = que.front().first;
        time = que.front().second;
        que.pop();

        //sTime이 처음 초기화 했던 -1이 아니라는 뜻은 누나가 한번 동생을 찾았다는 뜻
        ////bfs로 접근하므로 접근 시간은 항상 증가하는 방향
        //그렇다면 현재 que에는 누나가 동생을 찾는 시간보다 작은 시간의 케이스는 없다.
        //따라서 현재 동생을 찾는 최소 시간의 케이스들은 이미 que안에 있다.
        //그러므로 que를 돌리면서 누나가 동생을 찾는 최소시간을 가지는 또 다른 케이스들을 찾는 과정 반복
        if (sTime != -1){
            //누나가 동생을 찾은 최소 시간보다 소요 시간이 커졌다면 이후에는 답이 나오지 않음.
            if (sTime < time){
                break;
            }

            //최소 시간으로 누나가 동생을 찾는 케이스가 또 있음
            if (x == k){
                sFindCase++;
            }
        }
        else if (k == x){ //누나와 동생의 위치가 같음
            //소요시간 저장
            sTime = time;
            sFindCase++;
        }
        else{
            //한번도 접근한 적 없다면
            if(isVisited[x]==-1){
                isVisited[x]=time;
            }//접근했을 때의 소요 시간과 현재 방법으로의 접근 시간이 같을 때
            else if(isVisited[x]==time){  
                continue;
            }

            if (x + 1 <= MAX){
                que.push({x + 1, time + 1});
            }
            if (x - 1 >= 0){
                que.push({x - 1, time + 1});
            }
            if (x * 2 <= MAX){
                que.push({x * 2, time + 1});
            }
        }
    }

    //결과 출력
    cout << sTime << "\n";
    cout << sFindCase;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}