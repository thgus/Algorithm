/*
17071번: 숨바꼭질 5
https://www.acmicpc.net/problem/

신기하다
블로그 참고

한번 방문한 곳은 +1 -1로 인해서
2의 텀을 두고 방문하게되는 것을 이용해서 시간을 줄임.

0초에 n에 도착한다면 2,4,6,8...에 n에 방문
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 500000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int k;

void initialize()
{
    cin>>n>>k;
}

void solve()
{
    vector<int> odd(MAX+1,-1);
    vector<int> even(MAX+1,-1);

    queue<pair<int,int>> que;
    que.push({0,n});
    even[n]=0;

    while(!que.empty()){
        int ct=que.front().first;
        int cn=que.front().second;
        que.pop();

        int nt=ct+1;
        if(cn-1>=0){
            if(nt%2==0&&even[cn-1]==-1){
                even[cn-1]=nt;
                que.push({nt,cn-1});
            }
            else if(nt%2==1&&odd[cn-1]==-1){
                odd[cn-1]=nt;
                que.push({nt,cn-1});
            }
        }

        if(cn+1<=MAX){
            if(nt%2==0&&even[cn+1]==-1){
                even[cn+1]=nt;
                que.push({nt,cn+1});
            }
            else if(nt%2==1&&odd[cn+1]==-1){
                odd[cn+1]=nt;
                que.push({nt,cn+1});
            }
        }

        if(cn*2<=MAX){
            if(nt%2==0&&even[cn*2]==-1){
                even[cn*2]=nt;
                que.push({nt,cn*2});
            }
            else if(nt%2==1&&odd[cn*2]==-1){
                odd[cn*2]=nt;
                que.push({nt,cn*2});
            }
        }
    }

    int next=k;
    int time=0;
    while(next<=MAX){
        if(time%2==0&&even[next]<=time){
            cout<<time;
            return;
        }
        else if(time%2==1&&odd[next]<=time){
            cout<<time;
            return;
        }
        next+=++time;
    }

    cout<<"-1";
}  

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}