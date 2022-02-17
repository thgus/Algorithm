/*
14698번: 전생했더니 슬라임 연구자였던 건에 대하여 (Hard)
https://www.acmicpc.net/problem/14698

연쇄행렬곱셈으로도 풀 수 있을 것 같다.

그리디로 풀 수 있대
 => 합성 에너지가 AxB이고 이 값들을 다 곱한 값이 제일 작게 만들어지려면
    합성 에너지를 작게 만드는 것이 이상적
아니 값 너무 큰데;; biginteger 써야할 거 같다;; 내일 java로 풀자
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 60
#define DIVISOR 1000000007
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve(priority_queue<int,vector<int>,greater<int>> &que)
{
    vector<long long> cost;
    while(que.size()!=1){
        long long s1=-que.top();
        que.pop();
        long long s2=-que.top();
        que.pop();

        long long s=(s1*s2);
        cost.push_back(s);
        que.push(s);

        cout<<s<<"\n";
    }
    
    long long result=1;
    for(int i=0;i<cost.size();i++){
        result*=cost[i];       
        result%=DIVISOR; 
    }
    cout<<result<<"\n";
}

void initialize()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        priority_queue<int,vector<int>,greater<int>> que;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            que.push(temp);
        }       

        solve(que); 
    }
}

int main()
{
    sync_off;
    initialize();

    return 0;
}