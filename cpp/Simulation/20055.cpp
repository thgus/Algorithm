/*
20055번: 컨베이어 벨트 위의 로봇
https://www.acmicpc.net/problem/20055
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n,k;
vector<int> durability;

void initialize()
{
    cin>>n>>k;
    n*=2;
    durability.resize(n);

    for(int i=0;i<n;i++){
        cin>>durability[i];
    }
}

void solve()
{
    vector<bool> station(n,false);

    int durability_zero=0;

    int start=0;
    int end=n/2-1;

    int step=0;
    deque<int> dq;

    while(1){
        step++;

        //내리는 위치의 로봇은 내린다.
        if(!dq.empty()&&dq.back()==end){
            station[dq.back()]=false;
            dq.pop_back();
        }

        start--;
        if(start==-1){
            start=n-1;
        }
        end--;
        if(end==-1){
            end=n-1;
        }

        //내리는 위치의 로봇은 내린다.
        if(!dq.empty()&&dq.back()==end){
            station[dq.back()]=false;
            dq.pop_back();
        }

        //가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
        //이동할 수 없다면 가만히 있는다.
        for(int i=dq.size()-1;i>=0;i--){
            int cur=dq[i];
            int next=(cur+1)%n;

            //로봇이 내리는 위치가 아니고
            if(cur==end)  continue;
            //이동하려는 칸에 로봇이 없으며
            if(station[next])    continue;
            //그 칸의 내구도가 1 이상 남아 있어야 한다.
            if(durability[next]==0)   continue;

            //이동
            durability[next]--;
            station[cur]=false;
            station[next]=true;
            dq[i]=next;

            //현재 칸의 내구도가 0이 되면 카운트
            if(durability[next]==0){
                durability_zero++;
            }
        }

        //올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if(durability[start]>0){
            durability[start]--;
            station[start]=true;
            dq.push_front(start);

            //현재 칸의 내구도가 0이 되면 카운트
            if(durability[start]==0){
                durability_zero++;
            }
        }

        //내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.
        if(durability_zero>=k){
            cout<<step;
            return;
        }
    }
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}