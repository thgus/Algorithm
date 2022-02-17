/*
1715번: 카드 정렬하기
https://www.acmicpc.net/problem/1715
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
priority_queue<int> que;

void initialize()
{
    cin>>n;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        que.push(-temp);
    }
}

void solve()
{
    int comp=0;
    if(que.size()==1){
        cout<<0;
        return;
    }

    while(que.size()!=1){
        int a=-que.top();
        que.pop();
        int b=-que.top();
        que.pop();

        comp+=a+b;
        que.push(-(a+b));

    }

    cout<<comp;
}

int main()
{
    sync_off;
    initialize();
    solve();

    return 0;
}